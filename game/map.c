/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:09:03 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/14 14:48:54 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
	This function will read the first line of the map 
	and tell how wide it is
*/
static int	map_width(char *str)
{
	int	width;

	width = 0;
	while(str[width] != '\0')
		width++;
	if (str[width - 1] == '\n')
		width--;
	return (width);
}

/*
	This function will malloc and add a new line to the map
	using a previous map if existent then adding the 
	new line from GNL
*/
static int	add_line(t_comp *game, char *line)
{
	char **temp;
	int i;

	i = 0;
	if (!line)
		return (0);
	game->height++;  // Increase the height of the map
	temp = malloc(sizeof(char *) * (game->height + 1));
	temp[game->height] = NULL;
	while(i < game->height - 1) // Copy the map to the temp variable we use - 1 cuz the last line is NULL and the height - 1 line still doesn't exist
	{							// we use - 1 cuz the last line is NULL and the height - 1 line still doesn't exist
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line; // Adds the new line to the temp variable
	if (game->map) // If there is a map, free it
		free(game->map);
	game->map = temp; // Creates the updated map
	return (1);
}

int	map_reading(t_comp *game, char **av)
{
	char *mapline;

	game->fd = open(av[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while(1)
	{
		mapline = get_next_line(game->fd);
		if(!add_line(game, mapline))
			break ;
	}
	close (game->fd);
	game->width = map_width(game->map[0]);
	return (1);
}
