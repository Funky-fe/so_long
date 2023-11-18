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
	game->mlxpointer = NULL;
	game->winpointer = NULL;
	return (0);
}

void	destroy_windows(t_comp *game)
{
	if (game->player)
	{
		mlx_destroy_image(game->mlxpointer, game->floor);
		mlx_destroy_image(game->mlxpointer, game->player);
		mlx_destroy_image(game->mlxpointer, game->wall);
		mlx_destroy_image(game->mlxpointer, game->collectable);
		mlx_destroy_image(game->mlxpointer, game->exit);
	}
    if (game->mlxpointer != NULL)
	{
		mlx_clear_window(game->mlxpointer, game->winpointer);
		mlx_destroy_window(game->mlxpointer, game->winpointer);
		game->winpointer = NULL;
		mlx_destroy_display(game->mlxpointer);
		free (game->mlxpointer);
	}
}