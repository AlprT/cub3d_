
#include "../inc/cub3d.h"
#include "../../minilibx/mlx.h"

void	init_mlx(t_cub3d *cub3d)
{
	int	w;
	int	h;

	w = SCREEN_WIDTH;
	h = SCREEN_HEIGHT;
	cub3d->game->mlx = mlx_init();
	if (cub3d->game->mlx == NULL)
		print_error(cub3d, "mlx malloc error.");
	cub3d->game->window = mlx_new_window(cub3d->game->mlx, w, h, "Saz3D");
	if (cub3d->game->window == NULL)
		print_error(cub3d, "window malloc error.");
}

void	init_screen(t_cub3d *cub3d)
{
	t_game	*game;

	game = cub3d->game;
	game->screen = malloc(sizeof(t_mlx_image));
	if (game->screen == NULL)
		print_error(cub3d, "game->screen malloc error.");
	game->screen->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (game->screen->img == NULL)
		print_error(cub3d, "game->screen->img malloc error.");
	game->screen->addr = mlx_get_data_addr(game->screen->img,
			&game->screen->bits_per_pixel,
			&game->screen->size_line,
			&game->screen->endian);
	if (game->screen->addr == NULL)
		print_error(cub3d, "game->screen->addr malloc error.");
}

void	free_screen(t_cub3d *cub3d)
{
	if (cub3d->game->screen == NULL)
		return ;
	if (cub3d->game->screen->img != NULL)
		mlx_destroy_image(cub3d->game->mlx, cub3d->game->screen->img);
	free(cub3d->game->screen);
}

void	free_mlx(t_cub3d *cub3d)
{
	if (cub3d->game->mlx == NULL)
		return ;
	if (cub3d->game->window != NULL)
		mlx_destroy_window(cub3d->game->mlx, cub3d->game->window);
}
