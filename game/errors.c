/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:43:32 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/23 19:59:13 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_errors(t_comp *game)
{
	check_walls(game);
	char_checker(game);
}

void	exit_game(t_comp *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free (game->mlxpointer);
	while (line < game->height - 1)
		free(game->map[line++]);
	free (game->map);
	exit (0);
}
