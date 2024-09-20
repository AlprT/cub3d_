#include "../inc/cub3d.h"
#include <fcntl.h>
#include <unistd.h>

static void	check_north_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("NO", line, 2) == 0)
	{
		data->xpm_files->north = ft_strtrim_start(line + 2, " \t");
		if (data->xpm_files->north[0] == '\0')
			print_error(cub3d, "NO element can't be null.");
		if (ft_strcmp(data->xpm_files->north
				+ ft_strlen(data->xpm_files->north) - 4, ".xpm") != 0)
			print_error(cub3d, "NO element must end with the .xpm extension.");
		fd = open(data->xpm_files->north, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "NO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	check_south_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("SO", line, 2) == 0)
	{
		data->xpm_files->south = ft_strtrim_start(line + 2, " \t");
		if (data->xpm_files->south[0] == '\0')
			print_error(cub3d, "SO element cant' be empty.");
		if (ft_strcmp(data->xpm_files->south
				+ ft_strlen(data->xpm_files->south) - 4, ".xpm") != 0)
			print_error(cub3d, "SO element must end with the .xpm extension.");
		fd = open(data->xpm_files->south, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "SO xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	check_west_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("WE", line, 2) == 0)
	{
		data->xpm_files->west = ft_strtrim_start(line + 2, " \t");
		if (data->xpm_files->west[0] == '\0')
			print_error(cub3d, "WE element cant' be empty.");
		if (ft_strcmp(data->xpm_files->west
				+ ft_strlen(data->xpm_files->west) - 4, ".xpm") != 0)
			print_error(cub3d, "WE element must end with the .xpm extension.");
		fd = open(data->xpm_files->west, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "WE xpm file not found or can't be opened.");
		close(fd);
	}
}

static void	check_east_xpm(t_cub3d *cub3d, char *line)
{
	t_data	*data;
	int			fd;

	data = cub3d->data;
	fd = -1;
	if (ft_strncmp("EA", line, 2) == 0)
	{
		data->xpm_files->east = ft_strtrim_start(line + 2, " \t");
		if (data->xpm_files->east[0] == '\0')
			print_error(cub3d, "EA element cant' be empty.");
		if (ft_strcmp(data->xpm_files->east
				+ ft_strlen(data->xpm_files->east) - 4, ".xpm") != 0)
			print_error(cub3d, "EA element must end with the .xpm extension.");
		fd = open(data->xpm_files->east, O_RDONLY);
		if (fd == -1)
			print_error(cub3d, "EA xpm file not found or can't be opened.");
		close(fd);
	}
}

void	check_xpm_files(t_cub3d *cub3d, char *line)
{
	check_north_xpm(cub3d, line);
	check_south_xpm(cub3d, line);
	check_west_xpm(cub3d, line);
	check_east_xpm(cub3d, line);
}
