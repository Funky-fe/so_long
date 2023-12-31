/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:23 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/30 15:25:33 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	exit_game(t_comp *game)
{
	int	line;

	line = 0;
	destroy_windows(game);
	while (line < game->height)
	{
		free(game->map[line]);
		line++;
	}
	if (game->map2)
	{
		line = 0;
		while (line < game->height)
		{
			free(game->map2[line]);
			line++;
		}
		free (game->map2);
	}
	free (game->map);
	exit (0);
}

static void	*ft_memset(void *b, int c, size_t lenght)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (lenght--)
		*ptr++ = (unsigned char)c;
	return (b);
}

int	main(int ac, char **av)
{
	t_comp	game;

	if (ac != 2)
		return (0);
	if (isber(av[1]) == 0)
	{
		ft_printf("Error\nInvalid file extension\n");
		exit (0);
	}
	ft_memset(&game, 0, sizeof(t_comp));
	init_list(&game);
	map_reading(&game, av);
	check_errors(&game);
	game.mlxp = mlx_init();
	game.winp = mlx_new_window(game.mlxp, game.width * 32, 
			game.height * 32, "so_long");
	set_img_to_var(&game);
	update_graphics(&game);
	mlx_key_hook(game.winp, controls_hook, &game);
	mlx_hook(game.winp, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxp);
}
