#include "includes/cub3d.h"

int	stop_game(t_map *map)
{
	mlx_destroy_window(map->img.mlx, map->img.win);
	exit(0);
}
