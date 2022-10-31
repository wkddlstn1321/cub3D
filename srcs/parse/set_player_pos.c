#include "includes/cub3d.h"

static	void	set_player_dir(t_map *map, char c)
{	
	if (c == 'N')
		map->player.angle = 90 * M_PI / 180;
	else if (c == 'E')
		map->player.angle = 180 * M_PI / 180;
	else if (c == 'S')
		map->player.angle = 270 * M_PI / 180;
	else if (c == 'W')
		map->player.angle = 0;
}

void	set_player_pos(t_map *map)
{
	int		y;
	int		x;
	char	**maze;

	maze = map->map_info;
	y = 0;
	while (maze[y] != NULL)
	{
		x = 0;
		while (maze[y][x] != '\0')
		{
			if (maze[y][x] == 'N' || maze[y][x] == 'E'
				|| maze[y][x] == 'W' || maze[y][x] == 'S')
			{
				map->player.pos.y = y;
				map->player.pos.x = x;
				set_player_dir(map, maze[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
}

