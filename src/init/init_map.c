
#include "../inc/cub3d.h"
#include <stdlib.h>

void	init_map(t_cub3d *cub3d)
{
	cub3d->data->map = malloc(sizeof(t_map));
	if (cub3d->data->map == NULL)
		print_error(cub3d, "map malloc error.");
	cub3d->data->map->text = NULL;
	cub3d->data->map->starting_line = 0;
	cub3d->data->map->row_count = 0;
	cub3d->data->map->col_count = 0;
	cub3d->data->map->player_count = 0;
	cub3d->data->map->player_row = 0;
	cub3d->data->map->player_col = 0;
}

void	free_map(t_cub3d *cub3d)
{
	if (cub3d->data->map == NULL)
		return ;
	free_double_pointer(cub3d->data->map->text);
	free(cub3d->data->map);
}
