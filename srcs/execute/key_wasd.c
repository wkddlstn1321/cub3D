#include "includes/cub3d.h"

//대각으로 나가면 맵 밖으로 나가짐 수정 필요
void	key_wasd(int key, t_map *map)
{
	char	**maze;

	maze = map->map_info;
	if (key == E_W)
	{
		if (maze[(int)(map->player.pos.y + map->player.dir.y * 0.3)][(int)(map->player.pos.x + map->player.dir.x * 0.3)] != '1')
		{
			map->player.pos.x += map->player.dir.x * 0.1;
			map->player.pos.y += map->player.dir.y * 0.1;
		}

	}
	if (key == E_A)
	{
		if (maze[(int)(map->player.pos.y - get_move_y(map->player.dir, 90) * 0.3)][(int)(map->player.pos.x -get_move_x(map->player.dir, 90) * 0.3)] != '1')
		{
			map->player.pos.x -= get_move_x(map->player.dir, 90) * 0.1;
			map->player.pos.y -= get_move_y(map->player.dir, 90) * 0.1;
		}

	}
	if (key == E_S)
	{
		if (maze[(int)(map->player.pos.y - map->player.dir.y * 0.3)][(int)(map->player.pos.x - map->player.dir.x * 0.3)] != '1')
		{
			map->player.pos.x -= map->player.dir.x * 0.1;
			map->player.pos.y -= map->player.dir.y * 0.1;
		}
	}
	if (key == E_D)
	{
		if (maze[(int)(map->player.pos.y +  get_move_y(map->player.dir, 90) * 0.3)][(int)(map->player.pos.x + get_move_x(map->player.dir, 90) * 0.3)] != '1')
		{
			map->player.pos.x += get_move_x(map->player.dir, 90) * 0.1;
			map->player.pos.y += get_move_y(map->player.dir, 90) * 0.1;
		}
	}
}
