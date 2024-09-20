
#include "../inc/cub3d.h"
#include <fcntl.h>

char	**create_uniform(t_cub3d *cub3d)
{
	t_data	*data;
	char		**map;
	int			i;

	data = cub3d->data;
	map = malloc(sizeof(char *) * (data->map->row_count + 1));
	if (map == NULL)
		print_error(cub3d, "create_map_same_row_len malloc error.");
	i = 0;
	while (data->map->text[i] != NULL)
	{
		map[i] = malloc(data->map->col_count + 1);
		if (map[i] == NULL)
		{
			free_double_pointer(map);
			print_error(cub3d, "create_map_same_row_len[i] malloc error.");
		}
		ft_strncpy(map[i], data->map->text[i], data->map->col_count);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	get_map(t_cub3d *cub3d)
{
	t_data	*data;
	int			map_index;
	int			col_count;
	int			i;

	data = cub3d->data;
	map_index = 6;
	data->map->row_count = data->full_line_count - map_index;
	data->map->text = malloc(sizeof(char *) * (data->map->row_count + 1));
	if (data->map->text == NULL)
		print_error(cub3d, "data->map->text malloc error.");
	col_count = 0;
	i = 0;
	while (data->text[map_index] != NULL)
	{
		data->map->text[i] = ft_strdup(data->text[map_index]);
		col_count = ft_strlen(data->text[map_index]);
		if (col_count > data->map->col_count)
			data->map->col_count = col_count;
		i++;
		map_index++;
	}
	data->map->text[i] = NULL;
}


void	check_empty(t_cub3d *cub3d)
{
	t_data	*data;
	char		*line;
	int			i;
	int			fd;

	data = cub3d->data;
	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	line = NULL;
	i = 1;
	while (i <= data->total_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (is_empty_line(line) && i > data->map->starting_line)
		{
			free(line);
			print_error(cub3d,
				"There can't be empty line on middle of the map or end");
		}
		free(line);
		i++;
	}
	close(fd);
}

void	check_map(t_cub3d *cub3d)
{
	get_map(cub3d);
	check_empty(cub3d);
	check_chars(cub3d);
	check_walls(cub3d);
	check_spaces(cub3d);
}
