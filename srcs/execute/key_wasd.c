#include "includes/cub3d.h"

void	key_wasd(int key, t_map *map)
{
	if (key == E_D)
	{
		map->player.pos.x += get_move_x(map->player.dir, 90) * 0.1;
		map->player.pos.y += get_move_y(map->player.dir, 90) * 0.1;
	}
	if (key == E_A)
	{
		map->player.pos.x -= get_move_x(map->player.dir, 90) * 0.1;
		map->player.pos.y -= get_move_y(map->player.dir, 90) * 0.1;
	}
	if (key == E_W)
	{
		map->player.pos.x += map->player.dir.x * 0.1;
		map->player.pos.y += map->player.dir.y * 0.1;
	}
	if (key == E_S)
	{
		map->player.pos.x -= map->player.dir.x * 0.1;
		map->player.pos.y -= map->player.dir.y * 0.1;
	}
}
