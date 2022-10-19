#include "includes/cub3d.h"

// 미로 내부 값들 확인
void	check_news(char **info, int w, int h)
{
	int		x;
	int		y;

	y = 1;
	while (info[y])
	{
		x = 1;
		while (info[y][x] != '\0')
		{
			if (y != h && x != w && (info[y][x] == ' ' || info[y][x] == '1'))
				;
			else if (y != h && x != w && (info[y][x] == '0' || info[y][x] == 'E'
				|| info[y][x] == 'W' || info[y][x] == 'S' || info[y][x] == 'N'))
			{
				if (info[y + 1][x] == ' ' || info[y - 1][x] == ' '
				|| info[y][x + 1] == ' ' || info[y][x - 1] == ' ')
					exit(ft_error("not surround wall"));
			}
			else
				exit(ft_error("map arg only [1] [0] ... [E]"));
			x++;
		}
		y++;
	}
}

//미로 테두리 확인
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
					exit(ft_error("border errrrrr"));
				x++;
			}
		}
		else
			if ((maze[y][0] != '1' && maze[y][0] != ' ')
				|| (maze[y][map->w - 1] != '1' && maze[y][map->w - 1] != ' '))
				exit(ft_error("border errrrrr"));
		y++;
	}
}

int	main(int ac, char **av)
{
	char	*file_name;
	char	**contents;
	t_map	map;

	if (ac != 2)
		return (ft_error("Wrong arguments  [./cub3D] [*.cub]"));
	file_name = av[1];
	check_extension(file_name);
	contents = init_contents(file_name);
	set_map(&map, contents);
	check_border(&map);
	check_news(map.map_info, map.w, map.h);
	printf("Success\n");
	return (0);
}
