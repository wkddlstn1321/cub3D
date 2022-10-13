#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

# define MAP_EXTENSION				".cub"

typedef struct s_player
{
	double	x;
	double	y;
	double	v_x;
	double	v_y;
}	t_player;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_rgb
{
	int	f[3];
	int	s[3];
}	t_rgb;

typedef struct s_map
{
	int			p_count;
	char		p_spawn;
	char		**map_info;
	t_texture	*texture;
	t_rgb		*rgb;
}	t_map;

int		ft_error(char *str);
void	check_extension(char *dir);

#endif