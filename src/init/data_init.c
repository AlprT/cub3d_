
#include "../inc/cub3d.h"
#include <stdlib.h>

void	init_data(t_cub3d *cub3d, int argument_count, char *filename)
{
	cub3d->data = malloc(sizeof(t_data));
	if (cub3d->data == NULL)
		print_error(cub3d, "data malloc error.");
	cub3d->data->argument_count = argument_count;
	cub3d->data->filename = filename;
	cub3d->data->text = NULL;
	cub3d->data->total_line_count = 0;
	cub3d->data->full_line_count = 0;
	cub3d->data->empty_line_count = 0;
	cub3d->data->xpm_files = NULL;
	cub3d->data->floor_color = NULL;
	cub3d->data->ceiling_color = NULL;
	cub3d->data->map = NULL;
}

void	free_data(t_cub3d *cub3d)
{
	if (cub3d->data == NULL)
		return ;
	free_map(cub3d);
	free_colors(cub3d);
	free_xpm_files(cub3d);
	free_double_pointer(cub3d->data->text);
	free(cub3d->data);
}
