#include "../inc/cub3d.h"
#include <stdlib.h>

static void	check_unknown_element_type(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->data->text[i];
		if (ft_strncmp("NO", line, 2) != 0 && ft_strncmp("SO", line, 2) != 0
			&& ft_strncmp("WE", line, 2) != 0 && ft_strncmp("EA", line, 2) != 0
			&& ft_strncmp("F", line, 1) != 0 && ft_strncmp("C", line, 1) != 0)
		{
			print_error(cub3d, "Only NO, SO, WE, EA, F and C element types \
			can be in the first 6 filled text.");
		}
		i++;
	}
}

static void	check_multiple_element_type(t_cub3d *cub3d)
{
	t_data	*data;

	data = cub3d->data;
	if (data->xpm_files->north_count > 1)
		print_error(cub3d, "NO element type cannot be more than 1.");
	if (data->xpm_files->south_count > 1)
		print_error(cub3d, "SO element type cannot be more than 1.");
	if (data->xpm_files->west_count > 1)
		print_error(cub3d, "WE element type cannot be more than 1.");
	if (data->xpm_files->east_count > 1)
		print_error(cub3d, "EA element type cannot be more than 1.");
	if (data->floor_color->count > 1)
		print_error(cub3d, "F element type cannot be more than 1.");
	if (data->ceiling_color->count > 1)
		print_error(cub3d, "C element type cannot be more than 1.");
}

static void	validate_different_xpm_files(t_cub3d *cub3d)
{
	t_data	*data;

	data = cub3d->data;
	if (ft_strcmp(data->xpm_files->north, data->xpm_files->south) == 0
		|| ft_strcmp(data->xpm_files->north, data->xpm_files->west) == 0
		|| ft_strcmp(data->xpm_files->north, data->xpm_files->east) == 0)
		print_error(cub3d, "NO texture can't be used for other textures.");
	if (ft_strcmp(data->xpm_files->south, data->xpm_files->north) == 0
		|| ft_strcmp(data->xpm_files->south, data->xpm_files->west) == 0
		|| ft_strcmp(data->xpm_files->south, data->xpm_files->east) == 0)
		print_error(cub3d, "SO texture can't be used for other textures.");
	if (ft_strcmp(data->xpm_files->west, data->xpm_files->north) == 0
		|| ft_strcmp(data->xpm_files->west, data->xpm_files->south) == 0
		|| ft_strcmp(data->xpm_files->west, data->xpm_files->east) == 0)
		print_error(cub3d, "WE texture can't be used for other textures.");
	if (ft_strcmp(data->xpm_files->east, data->xpm_files->south) == 0
		|| ft_strcmp(data->xpm_files->east, data->xpm_files->north) == 0
		|| ft_strcmp(data->xpm_files->east, data->xpm_files->west) == 0)
		print_error(cub3d, "EA texture can't be used for other textures.");
}

static void	validate_different_color(t_cub3d *cub3d)
{
	t_data	*data;

	data = cub3d->data;
	if (data->floor_color->red == data->ceiling_color->red
		&& data->floor_color->green == data->ceiling_color->green
		&& data->floor_color->blue == data->ceiling_color->blue)
	{
		print_error(cub3d, "Floor and ceiling color should not be the same.");
	}
}

void	check_content(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	set_elements_count(cub3d);
	check_unknown_element_type(cub3d);
	check_multiple_element_type(cub3d);
	line = NULL;
	i = 0;
	while (i < 6)
	{
		line = cub3d->data->text[i];
		check_xpm_files(cub3d, line);
		check_fc(cub3d, line);
		check_cc(cub3d, line);
		i++;
	}
	validate_different_xpm_files(cub3d);
	validate_different_color(cub3d);
}
