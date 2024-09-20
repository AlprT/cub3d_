
#include "../inc/cub3d.h"
#include <stdlib.h>
#include <fcntl.h>

void	check_arg(t_cub3d *cub3d)
{
	char	*filename;

	filename = cub3d->data->filename;
	if (cub3d->data->argument_count == 1)
		print_error(cub3d, "Map name not entered. \
		You must enter the map name!");
	if (cub3d->data->argument_count > 2)
		print_error(cub3d,
			"Only the map name should be entered as an argument.");
	if (filename == NULL || *filename == '\0')
		print_error(cub3d, "Map name cannot be null or empty.");
	if (ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
		print_error(cub3d, "Map name does not end with the .cub extension.");
}

void	check_blackhole(t_cub3d *cub3d)
{
	char	character;
	int		readed_byte;
	int		fd;

	character = '\0';
	readed_byte = 0;
	fd = open(cub3d->data->filename, O_RDONLY);
	if (fd == -1)
		print_error(cub3d, "An error occurred while opening the map file.");
	readed_byte = read(fd, &character, 1);
	if (readed_byte == -1)
		print_error(cub3d, "An error occurred while reading the map file.");
	if (readed_byte == 0)
		print_error(cub3d, "Map file must not be empty.");
	close(fd);
}
