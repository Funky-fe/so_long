/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:01:24 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/14 13:49:39 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"

typedef struct t_start
{
	int	fd;		// file descriptor	
	int	height;	// height of the map
	int	width;	// width of the map
	int	exitcount;	// number of exits
	int	playercount;	// number of players
	int	columncount;	// number of collectables
	int	collectables;
	int	counter;	// move counter
	int	x_axis;	// x axis
	int	y_axis;	// y axis

	char	**map;

	void	*floor;
	void	*barrier;
	void	*exit;
	void	*player;
	void	*collectable;
	void	*winpointer;
	void	*mlxpointer;

}			t_comp;

#endif