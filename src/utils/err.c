
#include "cub3d.h"
#include <stdio.h>

void	print_error(t_cub3d *cub3d, char *message)
{
	printf("error: %s\n", message);
	free_cub3d(cub3d);
	exit(1);
}
