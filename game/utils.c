/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:26:05 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/27 19:15:34 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	init_list(t_comp *game)
{
	game->fd = 0;
	game->height = 0;
	game->width = 0;
	game->exitcount = 0;
	game->playercount = 0;
	game->collcount = 0;
	game->collectables = 0;
	game->counter = 0;
	game->x_axis = 0;
	game->y_axis = 0;
	game->collectcheck = 0;
	game->exitcheck = 0;
	game->mlxp = NULL;
	game->winp = NULL;
	return (0);
}

void	destroy_windows(t_comp *game)
{
	if (game->player)
	{
		mlx_destroy_image(game->mlxp, game->floor);
		mlx_destroy_image(game->mlxp, game->player);
		mlx_destroy_image(game->mlxp, game->wall);
		mlx_destroy_image(game->mlxp, game->collectable);
		mlx_destroy_image(game->mlxp, game->exit);
	}
	if (game->mlxp != NULL)
	{
		mlx_clear_window(game->mlxp, game->winp);
		mlx_destroy_window(game->mlxp, game->winp);
		game->winp = NULL;
		mlx_destroy_display(game->mlxp);
		free (game->mlxp);
	}
}
