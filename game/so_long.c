/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:23 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/10/18 16:52:42 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_memset(void *b, int c, size_t lenght)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while(lenght--)
	{
		*ptr++ = (unsigned char)c;
	}
	return (b);
}

int main(int ac, char **av)
{
	t_comp	game;

	if (ac != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_comp));
	map_reading(&game, av);
	check_errors(&game);
	game.mlxpointer = mlx_init();
	game.winpointer = mlx_new_window(game.mlxpointer, game.width * 69, game.height * 69, "so_long");
	mlx_loop(game.mlxpointer);
}
