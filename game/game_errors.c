/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:51:16 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/16 18:49:48 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// maybe this will check the map
static int	horiz_wall(t_comp *game) 
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


static int	vert_wall(t_comp *game)
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
		exit(0);
	}
}