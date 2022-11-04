#include "includes/cub3d.h"

int	on_key_press(t_map *map)
{
	if (map->player.angle > 360 * (M_PI / 180))
		map->player.angle = 0;
	else if (map->player.angle < 0)
		map->player.angle = 360 * (M_PI / 180);
	if (map->event.r == 1)
		map->player.angle += 0.03;
	if (map->event.l == 1)
		map->player.angle -= 0.03;
	key_wasd(map);
	return (0);
}
