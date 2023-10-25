/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:19:57 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/25 18:58:51 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (keycode == 0)
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		if (!legal_move(game, x, y))
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (keycode == 0)
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
	if (keycode == 0)
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		if (!legal_move(game, x, y))
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (keycode == 0)
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
	(void)game;
	ft_printf("this is the keycode: %i\n", keycode);
	return (1);
}