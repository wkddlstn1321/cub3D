#include "includes/cub3d.h"

int	stop_game(t_map *map)
{
	mlx_destroy_window(map->spr.mlx, map->spr.win);
	exit(0);
}
