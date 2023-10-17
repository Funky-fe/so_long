/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:16 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/17 13:44:32 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horiz_wall(t_comp *game)
{
	int	i;
	int	j;

	i = game->width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][j] != '1' && game->map[game->height - 1][j] != '1' )
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
		if (game->map[height][0] != '1' && game->map[height][width - 1] != '1')
			return (0);
		height++;
	}
}

void	check_walls(t_comp *game)
{
	int	verticalwall;
	int	horizontalwall;

	verticalwall = vert_wall(game);
	horizontalwall = horiz_wall(game);
	if (!verticalwall || !horizontalwall)
	{
		printf("Error\nMap is not surrounded by walls\n");
		/*inserir funcao de erro e dar free no jogo*/
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
		return (0);
	{
		printf("Error\nMap is not valid here%c\n", game->map[height][width]);
		/*funcao erro free*/
	}
	if (game->map == 'C')
		game->columncount++;
	if (game->map == 'E')
		game->exitcount++;
	if (game->map == 'P')
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
		while (width <= width)
		{
			counter_checker(game, height, width);
			width++;
		}
		height++;
	}
	if (game->playercount != 1 || game->exitcount != 1
		|| game->columncount < 1)
	{
		printf("Error\nSomething is wrong\n");
		printf("Player, Collectable or exit numbers issue!\n");
		/*funcao eriowfkqwpef keq :D*/
	}
}
