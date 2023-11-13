/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlima-fe <rlima-fe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:06:23 by rlima-fe          #+#    #+#             */
/*   Updated: 2023/11/13 18:37:44 by rlima-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	exit_game(t_comp *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	free (game->mlxpointer);
	while (line < game->height - 1)
    {
		free(game->map[line]);
        line++;
    }
	free (game->map);
	exit (0);
}

static void	*ft_memset(void *b, int c, size_t lenght)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while(lenght--)
		*ptr++ = (unsigned char)c;
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
	game.winpointer = mlx_new_window(game.mlxpointer, game.width * 64, game.height * 64, "so_long");
	set_img_to_var(&game);
	update_graphics(&game);
	mlx_key_hook(game.winpointer, controls_hook, &game);
	mlx_loop(game.mlxpointer);
	exit_game(&game);
}
