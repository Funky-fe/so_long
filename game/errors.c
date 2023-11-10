/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubenfernandes <rubenfernandes@student.42. +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:43:32 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/10 17:45:38 by rubenfernandes   ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void    map_copy(t_comp *game)
{
	int x;
	int y;

	y = 0;
	while(y < game->height)
	{
		x = 0;
		while(x < game->width)
		{
			game->map2[y][x] = game->map[y][x];
			x++;
		}
		y++;	
	}
}

void    flood_fill2(t_comp *game, int y, int x)
{
    if (game->map[y][x] == 'a')
        game->map[y][x] = '0';
    if (game->map[y][x] == 'c')
        game->map[y][x] = 'P';
    if (game->map[y][x] == 'd')
    {
        game->map[y][x] = 'E';
        game->exitcheck++;
    }
    if (game->map[y][x] == 'e')
    {
        game->map[y][x] = 'C';
        game->collectcheck++;
    }
    if (game->map[y][x] == 'f')
        game->map[y][x] = 'S';
}

int    flood_fill(t_comp *game, int y, int x)
{
    if (game->map[y][x] == 'a' ||
    game->map[y][x] == 'c' || game->map[y][x] == 'd'
    || game->map[y][x] == 'e' || game->map[y][x] == 'f')
    {
        flood_fill2(game, y, x);
        flood_fill(game, y, x + 1);
        flood_fill(game, y, x - 1);
        flood_fill(game, y + 1, x);
        flood_fill(game, y - 1, x);
    }
    return (1);
}

void	check_errors(t_comp *game)
{
	check_walls(game);
	char_checker(game);
	map_copy(game);
	flood_fill(game, game->y_axis, game->x_axis);
	if (game->exitcheck != 1 || game->collectcheck != game->collcount)
		exit_game(game);
}

void	exit_game(t_comp *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free (game->mlxpointer);
	while (line < game->height - 1)
    {
        free(game->map2[line]);
		free(game->map[line]);
        line++;
    }
	free (game->map);
	exit (0);
}
