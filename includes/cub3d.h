#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "get_next_line.h"

# define MAP_EXTENSION				".cub"

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

typedef struct s_player
{
	double	x;
	double	y;
	double	v_x;
	double	v_y;
}	t_player;

// typedef struct s_texture
// {
// 	char	*no;
// 	char	*so;
// 	char	*we;
// 	char	*ea;
// }	t_texture;

typedef struct s_rgb
{
	int	floor[3];
	int	ceiling[3];
}	t_rgb;

typedef struct s_map
{
	int		p_count;
	char	**map_info;
	char	**texture;
	int		**rgb;
	// t_rgb	*rgb;
	int		w;
	int		h;
	int		location;
}	t_map;

int		ft_error(char *str);
void	check_extension(char *dir);
char	**init_contents(char *file_name);
char	**join_contents(char **arr, char *str);
int		set_arg(char **contents, t_map *map);
void	ft_converter(char *line);

#endif