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

# define MAP_EXTENSION				".cub"
# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define GRID_SIZE	128

typedef struct s_new_img
{
	void	*img;
	int		*img_set;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
}	t_new_img;

typedef enum e_key_types
{
	E_W = 13,
	E_A = 0,
	E_S = 1,
	E_D = 2,
	E_LEFT = 123,
	E_RIGHT = 124,
	E_EXIT = 53,
}	t_key_types;

typedef enum e_texture_types
{
	E_NO = 0,
	E_SO,
	E_EA,
	E_WE,
}	t_texture_types;

typedef enum e_rgb_types
{
	E_F = 0,
	E_C
}	t_rgb_types;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_plane
{
	double	x;
	double	y;
}	t_plane;

typedef struct s_player
{
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	double		angle;
}	t_player;

typedef struct s_img_info
{
	int	**no;
	int	**ea;
	int	**we;
	int	**so;
}		t_img_info;

typedef struct s_map
{
	void		*mlx_win;
	void		*mlx;
	int			p_count;
	char		**map_info;
	char		**texture_path;
	int			**rgb;
	int			w;
	int			h;
	int			***sprite_info;
	t_player	player;
	t_img_info	img;
	t_new_img	img_info;
}	t_map;

typedef struct s_info
{
	void		*mlx;
	void		*mlx_win;
	void		*new_win;
	void		*img;
}		t_info;

int		ft_error(char *str);
void	check_extension(char *dir);
char	**init_contents(char *file_name);
int		set_arg(char **contents, t_map *map);
int		get_arr_len(char **arr);
void	ft_converter(char *line);
void	set_map(t_map *map, char **contents);
//test
void	execute_mlx(double dis, int xpos, double hit_po);
void	dda(t_map *map);
// parse
void	set_player_pos(t_map *map);
void	check_type(t_map *map, char **arr);
void	check_border(t_map *map);
void	check_news(char **info, int w, int h);

// utils
double	get_move_x(t_vector dir, double degree);
double	get_move_y(t_vector dir, double degree);
double	ft_dtor(double degree);

#endif