/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:19:57 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/02 16:27:44 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	legal_move(t_comp *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->collectables == 0)
		{
			ft_printf("You win!\n");
			exit_game(game);
		}
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->collectables--;
		game->counter++;
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->x_axis = x;
		game->y_axis = y;
		game->counter++;
	}
	return (1);
} 

/*
	This function will move the player to the left and right.
	If its a legal move, the previous location of the player
	will be replaced with a 0 aka floor.
*/
int	key_a_d(t_comp *game, int keycode)
{
	int	x;
	int	y;

	x = game->x_axis;
	y = game->y_axis;
	if (keycode == 97)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		if (!legal_move(game, x, y))
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (keycode == 100)
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		if (!legal_move(game, x, y))
			return (0);
		game->map[y][x - 1] = '0';
	}
	ft_printf("steps taken %i\n", game->counter);
	return (1);
}
/*
	This function will move the player up and down.
	If its a legal move, the previous location of the player
	will be replaced with a 0 aka floor.
*/
int	key_w_s(t_comp *game, int keycode)
{
	int	x;
	int	y;

	x = game->x_axis;
	y = game->y_axis;
	if (keycode == 119)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		if (!legal_move(game, x, y))
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (keycode == 115)
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		if (!legal_move(game, x, y))
			return (0);
		game->map[y - 1	][x] = '0';
	}
	ft_printf("steps taken %i\n", game->counter);
	return (1);
}

int	controls_hook(int keycode, t_comp *game)
{
	int	valid;

	valid = 0;
	if (keycode == 119 || keycode == 115)
		valid = key_w_s(game, keycode);
	else if (keycode == 65307)
		exit_game(game);
	else if (keycode == 97 || keycode == 100)
		valid = key_a_d(game, keycode);
	if (valid)
		update_graphics(game);
	return (1);
}
