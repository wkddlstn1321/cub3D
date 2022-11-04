#include "includes/cub3d.h"

void	check_border(t_map *map)
{
	int		y;
	int		x;
	char	**maze;

	maze = map->map_info;
	y = 0;
	while (maze[y] != NULL)
	{
		x = 0;
		if (y == 0 || y == (map->h - 1))
		{
			while (maze[y][x] != '\0')
			{
				if (maze[y][x] != ' ' && maze[y][x] != '1')
					exit(ft_error("Border is not satisfied."));
				x++;
			}
		}
		else
			if ((maze[y][0] != '1' && maze[y][0] != ' ')
				|| (maze[y][map->w - 1] != '1' && maze[y][map->w - 1] != ' '))
				exit(ft_error("Border is not satisfied."));
		y++;
	}
}
