#include "includes/cub3d.h"

static	void	key_w(t_map *map, double speed, double dis, char **maze)
{
	if (maze[(int)(map->player.pos.y + map->player.dir.y * dis)] \
		[(int)(map->player.pos.x)] != '1')
		map->player.pos.y += map->player.dir.y * speed;
	if (maze[(int)(map->player.pos.y)] \
		[(int)(map->player.pos.x + map->player.dir.x * dis)] != '1')
		map->player.pos.x += map->player.dir.x * speed;
}

static	void	key_a(t_map *map, double speed, double dis, char **maze)
{
	if (maze[(int)(map->player.pos.y - get_move_y(map->player.dir, 90) * dis)] \
	[(int)(map->player.pos.x)] != '1')
		map->player.pos.y -= get_move_y(map->player.dir, 90) * speed;
	if (maze[(int)(map->player.pos.y)][(int)(map->player.pos.x \
		- get_move_x(map->player.dir, 90) * dis)] != '1')
		map->player.pos.x -= get_move_x(map->player.dir, 90) * speed;
}

static	void	key_s(t_map *map, double speed, double dis, char **maze)
{
	if (maze[(int)(map->player.pos.y - map->player.dir.y * dis)] \
		[(int)(map->player.pos.x)] != '1')
		map->player.pos.y -= map->player.dir.y * speed;
	if (maze[(int)(map->player.pos.y)] \
		[(int)(map->player.pos.x - map->player.dir.x * dis)] != '1')
		map->player.pos.x -= map->player.dir.x * speed;
}

static	void	key_d(t_map *map, double speed, double dis, char **maze)
{
	if (maze[(int)(map->player.pos.y + get_move_y(map->player.dir, 90) * dis)] \
		[(int)(map->player.pos.x)] != '1')
		map->player.pos.y += get_move_y(map->player.dir, 90) * speed;
	if (maze[(int)(map->player.pos.y)][(int)(map->player.pos.x \
		+ get_move_x(map->player.dir, 90) * dis)] != '1')
		map->player.pos.x += get_move_x(map->player.dir, 90) * speed;
}

void	key_wasd(t_map *map)
{
	char	**maze;
	double	dis;
	double	speed;

	dis = 0.3;
	speed = 0.05;
	maze = map->map_info;
	if (map->event.w == 1)
		key_w(map, speed, dis, maze);
	if (map->event.a == 1)
		key_a(map, speed, dis, maze);
	if (map->event.s == 1)
		key_s(map, speed, dis, maze);
	if (map->event.d == 1)
		key_d(map, speed, dis, maze);
}
