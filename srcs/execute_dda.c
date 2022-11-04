#include "cub3d.h"

static int	press_key(int key, t_map *map)
{
	if (key == RIGHT)
		map->event.r = 1;
	if (key == LEFT)
		map->event.l = 1;
	if (key == W)
		map->event.w = 1;
	if (key == A)
		map->event.a = 1;
	if (key == S)
		map->event.s = 1;
	if (key == D)
		map->event.d = 1;
	if (key == EXIT)
	{
		mlx_destroy_window(map->spr.mlx, map->spr.win);
		exit(0);
	}
	return (0);
}

static int	release_key(int key, t_map *map)
{
	if (key == RIGHT)
		map->event.r = 0;
	if (key == LEFT)
		map->event.l = 0;
	if (key == W)
		map->event.w = 0;
	if (key == A)
		map->event.a = 0;
	if (key == S)
		map->event.s = 0;
	if (key == D)
		map->event.d = 0;
	return (0);
}

void	execute_dda(t_map *map)
{
	mlx_hook(map->spr.win, 17, 0, stop_game, map);
	mlx_hook(map->spr.win, 2, 0, press_key, map);
	mlx_hook(map->spr.win, 3, 0, release_key, map);
	mlx_loop_hook(map->spr.mlx, &main_loop, map);
	mlx_loop(map->spr.mlx);
}
