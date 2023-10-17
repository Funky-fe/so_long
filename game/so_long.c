/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:23 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/17 14:10:33 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_comp	*game;

	if (ac != 2)
		return (0);
	// set memoria no mapa
	map_reading(&game, av);
	check_errors(&game);
}