/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:04:34 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/06 18:06:08 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	set_img_to_var(t_comp *game)
{
	int	i;
	int	j;

	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"./images/player.xpm", &i, &j);
	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"./images/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlxpointer,
			"./images/wall.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"./images/collectable.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"./images/exit.xpm", &i, &j);
}

void		graphics_helper(t_comp *game, int i, int j)
{
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->wall, j * 64, i * 64);
	if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->floor, j * 64, i * 64);
	if (game->map[i][j] == 'C')
	{
		game->collectables++;
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->collectable, j * 64, i * 64);
	}
	if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->exit, j * 64, i * 64);
	if (game->map[i][j] == 'P')
	{
		game->x_axis = j;
		game->y_axis = i;
		mlx_put_image_to_window(game->mlxpointer, game->winpointer,
			game->player, j * 64, i * 64);
	}
}

void	update_graphics(t_comp *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectables = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			graphics_helper(game, i, j);
			j++;
		}
		i++;
	}
}
