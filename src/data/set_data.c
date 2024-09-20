
#include "../inc/cub3d.h"
#include <fcntl.h>
#include <stdlib.h>

void	set_data(t_cub3d *cub3d)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(cub3d->data->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	cub3d->data->text = malloc(
			sizeof(char *) * (cub3d->data->full_line_count + 1));
	if (cub3d->data->text == NULL)
		print_error(cub3d, "data->text malloc error.");
	cub3d->data->text[cub3d->data->full_line_count] = NULL;
	i = 0;
	while (i < cub3d->data->full_line_count)
	{
		line = get_next_line(cub3d, fd);
		if (!is_empty_line(line))
		{
			cub3d->data->text[i] = line;
			i++;
		}
		else
			free(line);
	}
	close(fd);
}
