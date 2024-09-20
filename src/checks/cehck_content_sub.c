#include "../inc/cub3d.h"

void	set_elements_count(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->data->text[i];
		if (ft_strncmp("NO", line, 2) == 0)
			cub3d->data->xpm_files->north_count++;
		if (ft_strncmp("SO", line, 2) == 0)
			cub3d->data->xpm_files->south_count++;
		if (ft_strncmp("WE", line, 2) == 0)
			cub3d->data->xpm_files->west_count++;
		if (ft_strncmp("EA", line, 2) == 0)
			cub3d->data->xpm_files->east_count++;
		if (ft_strncmp("F", line, 1) == 0)
			cub3d->data->floor_color->count++;
		if (ft_strncmp("C", line, 1) == 0)
			cub3d->data->ceiling_color->count++;
		i++;
	}
}