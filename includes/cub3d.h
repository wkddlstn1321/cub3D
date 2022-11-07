#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "get_next_line.h"
# include <math.h>

# define MAP_EXTENSION	".cub"
# define SCREEN_W		1920
# define SCREEN_H		1080

typedef struct s_key_event
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	l;
	int	r;
}	t_key_event;

typedef struct s_mlx_info
{
	void	*mlx;
	void	*img;
	void	*win;
	int		*img_set;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
}	t_mlx_info;

typedef enum e_key_types
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	LEFT = 123,
	RIGHT = 124,
	EXIT = 53,
}	t_key_types;

typedef enum e_spr_dir
{
	NO = 0,
	SO,
	EA,
	WE,
}	t_spr_dir;

typedef enum e_bg
{
	F = 0,
	C
}	t_bg;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_dda
{
	t_vector	delta;
	t_vector	step;
	t_vector	side;
	t_vector	ray_dir;
	int			spr_start;
	int			line_h;
	int			map_x;
	int			map_y;
	int			check_wall;
	int			spr_dir;
	int			draw_start;
	int			draw_end;
	double		wall_hit_point;
}	t_dda;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		angle;
}	t_player;

typedef struct s_map
{
	char		**map_info;
	char		**texture_path;
	int			**rgb;
	int			w;
	int			h;
	int			***sprite_info;
	int			xy[4][2];
	t_player	player;
	t_mlx_info	spr;
	t_key_event	event;
}	t_map;

int		ft_error(char *str);
void	check_extension(char *dir);
char	**init_contents(char *file_name);
int		set_arg(char **contents, t_map *map);
int		get_arr_len(char **arr);
void	ft_converter(char *line);
void	set_map(t_map *map, char **contents);

// parse
void	set_player_pos(t_map *map);
void	check_type(t_map *map, char **arr);
void	check_border(t_map *map);
void	check_news(char **info, int w, int h);
void	save_sprite_data(t_map *map, void *mlx);

// utils
double	get_move_x(t_vector dir, double degree);
double	get_move_y(t_vector dir, double degree);
double	ft_dtor(double degree);

//execute
void	draw_map(t_map *map, double dist, int x, t_dda *dda);
void	execute(t_map *map, t_dda *dda, int x);
void	key_wasd(t_map *map);
int		main_loop(t_map *map);
int		on_key_press(t_map *map);
void	set_delta(t_map *map, t_dda *dda);
int		stop_game(t_map *map);
void	execute_dda(t_map *map);
void	draw_bg(t_map *map);

// images
void	set_mlx_win(t_map *map);
#endif