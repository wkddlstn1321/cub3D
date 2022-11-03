#include "cub3d.h"

void	execute_dda(t_map *map)
{
	mlx_hook(map->img.win, 17, 0, stop_game, map);
	mlx_hook(map->img.win, 2, 0, on_key_press, map);
	mlx_loop_hook(map->img.mlx, &main_loop, map);
	mlx_loop(map->img.mlx);
}
