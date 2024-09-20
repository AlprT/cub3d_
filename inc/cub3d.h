/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atangil <atangil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:42:14 by atangil           #+#    #+#             */
/*   Updated: 2024/09/13 17:42:14 by atangil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "src/libft/libft.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define MOVE_SPEED 0.075
# define TURN_SPEED 0.05

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_DESTROY 17

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

typedef struct s_screen
{
	long	wall_height;
	int		wall_start_point;
	int		wall_end_point;
	int		hit_point_wall_texture;
	double	texture_offset_y;
	double	texture_pixel_ratio;
}			t_screen;

typedef struct s_mlx_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx_image;

typedef struct s_vector_double
{
	double	x;
	double	y;
}			t_vector_double;

typedef struct s_vector_int
{
	int	x;
	int	y;
}		t_vector_int;

typedef struct s_xpm_files
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;

	int		north_count;
	int		south_count;
	int		west_count;
	int		east_count;
}			t_xpm_files;

typedef struct s_map
{
	char	**text;
	int		starting_line;
	int		row_count;
	int		col_count;

	int		player_count;
	int		player_row;
	int		player_col;
}			t_map;

typedef struct s_color
{
	char	*red_string;
	char	*green_string;
	char	*blue_string;
	char	*string;

	int		count;
	int		red;
	int		green;
	int		blue;
}			t_color;

typedef struct s_data
{
	int			argument_count;
	char		*filename;

	char		**text;
	int			total_line_count;
	int			full_line_count;
	int			empty_line_count;

	t_xpm_files	*xpm_files;
	t_color		*floor_color;
	t_color		*ceiling_color;
	t_map		*map;
}				t_data;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}		t_keys;

typedef struct s_player
{
	t_vector_double	position;
	t_vector_double	direction;
	t_vector_double	camera_plane;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_mlx_image	*screen;
	t_mlx_image	*north_image;
	t_mlx_image	*south_image;
	t_mlx_image	*west_image;
	t_mlx_image	*east_image;
	int			floor_rgb;
	int			ceiling_rgb;
	t_keys		keys;
	t_player	*player;
}				t_game;

typedef struct s_ray
{
	t_vector_int	map_position;
	t_vector_double	real_position;
	t_vector_double	direction;
	t_vector_double	side_dist;
	t_vector_double	next_hit_dist;
	t_vector_int	map_step;
	int				hit_wall;
	char			hit_wall_side;
	double			view_of_wall;
	double			hit_point_wall;
	t_screen		screen;
}					t_ray;

typedef struct s_cub3d
{
	t_data	*data;
	t_game	*game;
}			t_cub3d;

// init
t_cub3d	*init_cub3d(int argument_count, char *filename);
void	init_data(t_cub3d *cub3d, int argument_count, char *filename);
void	init_xpm_files(t_cub3d *cub3d);
void	init_colors(t_cub3d *cub3d);
void	init_map(t_cub3d *cub3d);

// free
void	free_cub3d(t_cub3d *cub3d);
void	free_data(t_cub3d *cub3d);
void	free_xpm_files(t_cub3d *cub3d);
void	free_colors(t_cub3d *cub3d);
void	free_map(t_cub3d *cub3d);

// map
char	**create_uniform(t_cub3d *cub3d);
void	check_map(t_cub3d *cub3d);
void	get_map(t_cub3d *cub3d);
void	check_empty(t_cub3d *cub3d);
void	check_chars(t_cub3d *cub3d);
void	check_walls(t_cub3d *cub3d);

// checks
void	set_elements_count(t_cub3d *cub3d);
void	check_arg(t_cub3d *cub3d);
void	check_blackhole(t_cub3d *cub3d);
void	check_content(t_cub3d *cub3d);
void	check_xpm_files(t_cub3d *cub3d, char *line);
void	check_fc(t_cub3d *cub3d, char *line);
void	check_cc(t_cub3d *cub3d, char *line);

// utils
void	free_double_pointer(char **pointer);
int		is_empty_line(char *line);
void	print_error(t_cub3d *cub3d, char *message);
char	*get_next_line(t_cub3d *cub3d, int fd);
char	*ft_strtrim_start(char *s1, char *set);

// data
void	set_line_count(t_cub3d *cub3d);
void	set_data(t_cub3d *cub3d);

// map
void	set_map_text(t_cub3d *cub3d);

// game
void	player_move_up(t_map *map, t_player *player);
void	player_move_down(t_map *map, t_player *player);
void	player_move_left(t_map *map, t_player *player);
void	player_move_right(t_map *map, t_player *player);

//game/init
void	init_game(t_cub3d *cub3d);
void	init_screen(t_cub3d *cub3d);
void	free_screen(t_cub3d *cub3d);
void	free_mlx(t_cub3d *cub3d);
void	init_north_mlx_image(t_cub3d *cub3d);
void	init_south_mlx_image(t_cub3d *cub3d);
void	init_west_mlx_image(t_cub3d *cub3d);
void	init_east_mlx_image(t_cub3d *cub3d);
void	free_xpm_images(t_cub3d *cub3d);
void	init_floor_rgb(t_cub3d *cub3d);
void	init_ceiling_rgb(t_cub3d *cub3d);
void	init_player(t_cub3d *cub3d);
void	free_player(t_cub3d *cub3d);

// game/mlx
int	keyup_handler(int key, t_cub3d *cub3d);
int	keydown_handler(int key, t_cub3d *cub3d);
int	destroy_handler(t_cub3d *cub3d);
int	loop_handler(t_cub3d *cub3d);

#endif
