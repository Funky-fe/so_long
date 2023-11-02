/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:04:16 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/02 15:31:26 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	horiz_wall(t_comp *game)
{
	int	i;
	int	j;

	i = game->width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1' )
			return (0);
		j++;
	}
	return (1);
}

int	vert_wall(t_comp *game)
{
	int	height;
	int	width;

	width = game->width;
	height = 0;
	while (height < game->height)
	{
		if (game->map[height][0] != '1' || game->map[height][width - 1] != '1')
			return (0);
		height++;
	}
	return (1);
}

void	check_walls(t_comp *game)
{
	int	verticalwall;
	int	horizontalwall;

	verticalwall = vert_wall(game);
	horizontalwall = horiz_wall(game);
	if (!verticalwall || !horizontalwall)
	{
		ft_printf("Error\nMap is not surrounded by walls\n");
		exit_game(game);
	}
}

void	counter_checker(t_comp *game, int height, int width)
{
	if (game->map[height][width] != '1' &&
			game->map[height][width] != '0' &&
			game->map[height][width] != 'C' &&
			game->map[height][width] != 'E' &&
			game->map[height][width] != 'P' &&
			game->map[height][width] != '\n')
	{
		ft_printf("Error\nMap is not valid here:\n");
		ft_printf("Line: %i\n", game->height - 1);
		ft_printf("Column: %i\n", game->width - 2);
		exit_game(game);
	}
	if (game->map[height][width] == 'C')
		game->columncount++;
	if (game->map[height][width] == 'E')
		game->exitcount++;
	if (game->map[height][width] == 'P')
		game->playercount++;
}

void	char_checker(t_comp *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height - 1)
	{
		width = 0;
		while (width <= game->width)
		{
			counter_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->playercount != 1 || game->exitcount != 1
		|| game->columncount < 1)
	{
		ft_printf("Error\nSomething is wrong\n");
		ft_printf("Player, Collectable or exit numbers issue!\n");
		exit_game(game);
	}
}
