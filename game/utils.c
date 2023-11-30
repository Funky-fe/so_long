/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:26:05 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/30 15:26:33 by rlima-fe         ###   ########.fr       */
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	isber(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == 0)
		return (0);
	if (ft_strcmp(file + len - 4, ".ber") != 0)
		return (0);
	return (1);
}
