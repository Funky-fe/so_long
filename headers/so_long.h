/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:01:24 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/25 18:58:14 by rlima-fe         ###   ########.fr       */
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
# include "mlx.h"
# include "../printf/ft_printf.h"

typedef struct t_start
{
	int		fd;
	int		height;
	int		width;
	int		exitcount;
	int		playercount;
	int		columncount;
	int		collectables;
	int		counter;
	int		x_axis;
	int		y_axis;

	char	**map;

	void	*floor;
	void	*barrier;
	void	*exit;
	void	*player;
	void	*collectable;
	void	*winpointer;
	void	*mlxpointer;

}			t_comp;

/*			MAP			*/
int		map_width(char *str);
int		add_line(t_comp *game, char *line);
int		map_reading(t_comp *game, char **av);

/*			GAME_ERRORS			*/
int		horiz_wall(t_comp *game);
int		vert_wall(t_comp *game);
void	check_walls(t_comp *game);
void	counter_checker(t_comp *game, int height, int width);
void	char_checker(t_comp *game);

int		controls_hook(int keycode, t_comp *game);

void	check_errors(t_comp *game);
void	exit_game(t_comp *game);

#endif