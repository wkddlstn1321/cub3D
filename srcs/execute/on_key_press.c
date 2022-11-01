#include "includes/cub3d.h"

int	on_key_press(int key, t_map *map)
{
	if (map->player.angle > 360 * (M_PI / 180))
		map->player.angle = 0;
	else if (map->player.angle < 0)
		map->player.angle = 360 * (M_PI / 180);
	if (key == E_RIGHT)
		map->player.angle += 0.1;
	if (key == E_LEFT)
		map->player.angle -= 0.1;
	if (key == E_EXIT)
	{
		mlx_destroy_window(map->img.mlx, map->img.win);
		exit(0);
	}
	key_wasd(key, map);
	return (0);
}