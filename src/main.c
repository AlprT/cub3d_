/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:59:54 by atangil           #+#    #+#             */
/*   Updated: 2024/09/13 16:59:54 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int main(int ac, char **av)
{
	t_cub3d	*cub3d;

	cub3d = init_cup3d(ac, av[1]);
	check_arg(cub3d);
	check_blackhole(cub3d);
	set_line_count(cub3d);
	set_data(cub3d);
	check_content(cub3d);
	check_map(cub3d);
	init_game(cub3d);
	//raycaster
	mlx_put_image_to_window(cub3d->game->mlx, cub3d->game->window,
	cub3d->game->screen->img, 0, 0);
	mlx_hook(cub3d->game->window, ON_DESTROY, 0, destroy_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYDOWN, 1L << 0, keydown_handler, cub3d);
	mlx_hook(cub3d->game->window, ON_KEYUP, 1L << 1, keyup_handler, cub3d);
	mlx_loop_hook(cub3d->game->mlx, loop_handler, cub3d);
	mlx_loop(cub3d->game->mlx);
	return (0);
}
