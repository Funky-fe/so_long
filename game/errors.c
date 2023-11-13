/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:43:32 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/13 18:29:14 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void map_copy(t_comp *game)
{
    int y;
    int x;

    y = 0;
    game->map2 = malloc(sizeof(char *) * (game->height + 1));
    while (y < game->height)
    {
        x = 0;
        game->map2[y] = malloc(sizeof(char) * (game->width + 1));
        while (x < game->width)
        {
            game->map2[y][x] = game->map[y][x];
            x++;
        }
        game->map2[y][x] = '\n';
        y++;
    }
    game->map2[y] = NULL;
}


int	valid_path(t_comp *game, char **map, int x, int y)
{
	static int	e;
	static int	c;

	if (x < 0 || y < 0 || x > game->width || y > game->height
		|| map[y][x] == '1' || map[y][x] == 'X')
			return (0);
	if (map[y][x] == 'E')
		e++;
	if (map[y][x] == 'C')
		c++;
	map[y][x] = 'X';
	valid_path(game, map, x + 1, y);
	valid_path(game, map, x - 1, y);
	valid_path(game, map, x, y + 1);
	valid_path(game, map, x, y - 1);
	if (e == 1 && c == game->collcount)
		return (1);
	else
		return (0);
}

void	check_errors(t_comp *game)
{
	// int i = 0;
	check_walls(game);
	char_checker(game);
	map_copy(game);
	if (!valid_path(game, game->map2, game->x_axis, game->y_axis))
	{
		ft_printf("Error\nNot all collecatables or exits are reachable\n");
		exit_game(game);
	}
}
