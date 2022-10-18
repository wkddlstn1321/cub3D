#include "includes/cub3d.h"

// 미로 내부 값들 확인
int	check_news(t_map *map)
{
	int		x;
	int		y;
	char	**maze;

	maze = map->map_info;
	y = 1;
	while (maze[y])
	{
		x = 1;
		while (maze[y][x])
		{
			if (y != map->h && x != map->w
				&& (maze[y][x] == ' ' || maze[y][x] == '1'))
				;
			else if (y != map->h && x != map->w && (maze[y][x] == '0'
				|| maze[y][x] == 'E' || maze[y][x] == 'W'
				|| maze[y][x] == 'S' || maze[y][x] == 'N'))
			{
				if (maze[y + 1][x] == ' ' || maze[y - 1][x] == ' '
				|| maze[y][x + 1] == ' ' || maze[y][x - 1] == ' ')
					exit(ft_error("not surround wall"));
			}
			else
				exit(ft_error("map arg only [1] [0] ... [E]"));
			x++;
		}
		y++;
	}
	return (0);
}

//미로 테두리 확인
int	check_border(t_map *map)
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
					return (1);
				x++;
			}
		}
		else
			if ((maze[y][0] != '1' && maze[y][0] != ' ')
				|| (maze[y][map->w - 1] != '1' && maze[y][map->w - 1] != ' '))
				return (1);
		y++;
	}
	return (0);
}

// 미로 세팅 및 map 인자 체크 할 에정
void	fuck_set_map(char **contents, t_map *map)
{
	int		i;

	i = 0;
	while (contents[i] != NULL)
	{
		map->map_info[i] = malloc(sizeof(char) * (map->w + 1));
		if (map->map_info[i] == NULL)
			exit(ft_error("malloc error"));
		(map->map_info[i])[map->w] = '\0';
		ft_memset(map->map_info[i], ' ', map->w);
		ft_memcpy(map->map_info[i],
			contents[i], ft_strlen(contents[i]));
		i++;
	}
}

//maze 오른쪽이 딱 맞게
void	ft_converter(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			*line = '\0';
		line++;
	}
}

//maze의 높이와 가로길이 확인
void	set_map_height_width(t_map *map, char **contents)
{
	int		i;
	int		tmp;

	map->h = get_arr_len(contents);
	map->map_info = calloc(sizeof(char *), (map->h + 1));
	if (map->map_info == NULL)
		exit(ft_error("malloc error"));
	tmp = 0;
	while (*contents != NULL)
	{
		tmp = ft_strlen(*contents);
		if (tmp > map->w)
			map->w = tmp;
		i = 0;
		while ((*contents)[i])
		{
			if ((*contents)[i] == 'N' || (*contents)[i] == 'E'
				|| (*contents)[i] == 'W' || (*contents)[i] == 'S')
				map->p_count++;
			i++;
		}
		contents++;
	}
	if (map->p_count != 1)
		exit (ft_error("map error"));
}
// TEST*/


// int	check_arg(t_map *map)
// {
// 	int		total;
// 	char	*img_path;
// 	char	*line;

// 	map->texture = malloc(sizeof(t_texture));
// 	map->rgb = malloc(sizeof(t_rgb));
// 	if (!map->texture || !map->rgb)
// 		return (NULL);

// 	if (total == 6)
// 		return (1);
// 	return (0);
// }
/*
	NO, SO, WE, EA order / duplicate / ac == 2
	r,g,b 3 argument & range [0, 255] / 00

*/

void	set_map(t_map *map)
{
	map->texture = ft_calloc(sizeof(char *), 5);
	map->rgb = ft_calloc(sizeof(int *), 2);
	map->p_count = 0;
	map->idx = 0;
	map->h = 0;
	map->w = 0;
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
	set_map(&map);
	map.idx = set_arg(contents, &map);
	set_map_height_width(&map, &(contents[map.idx]));
	fuck_set_map(&(contents[map.idx]), &map);
	if (check_border(&map) || check_news(&map))
		return (ft_error("map error"));
	printf("Success\n");
	return (0);
}
