#include "cub3d.h"

void *mlx_win;
void *mlx;
void *new_win;
char *img_path = "./imgs/dogeye.XPM";
int x;
int y;

t_new_img	dog;

int bits_per_pixel = 0;
int size_line = 0;
int endian = 0;
int	*data;
int	*img_data;

void	execute_dda(t_map *map)
{
	mlx_hook(map->img.win, 17, 0, stop_game, map);
	mlx_hook(map->img.win, 2, 0, on_key_press, map);
	mlx_loop_hook(map->img.mlx, &main_loop, map);
	mlx_loop(map->img.mlx);
}
