#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "get_next_line.h"
#include <math.h>

# define MAP_EXTENSION				".cub"
# define SCREEN_WIDTH	1920
# define SCREEN_HEIGHT	1080
# define GRID_SIZE	128

typedef enum e_key_types
{
	E_W = 13,
	E_S = 1,
	E_A = 2,
	E_D = 0,
	E_RIGHT = 123,
	E_LEFT = 124,
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

typedef struct s_player
{
	t_vector	pos;
	char		dir;
}	t_player;

typedef struct s_map
{
	int			p_count;
	char		**map_info;
	char		**texture;
	int			**rgb;
	int			w;
	int			h;
	t_player	player;
}	t_map;

int		ft_error(char *str);
void	check_extension(char *dir);
char	**init_contents(char *file_name);
int		set_arg(char **contents, t_map *map);
int		get_arr_len(char **arr);
void	ft_converter(char *line);
void	check_type(t_map *map, char **arr);
void	set_map(t_map *map, char **contents);
//test
void	execute_mlx(double dis, int xpos, double hit_po);
void	dda(t_map *map);
#endif