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
			{
				x++;
				continue ;
				// ???/
			}
			else if (y != map->h && x != map->w && (maze[y][x] == 'N' || maze[y][x] == 'E'
				|| maze[y][x] == 'W' || maze[y][x] == 'S' || maze[y][x] == '0'))
			{
				if (maze[y + 1][x] == ' ')
					return (1);
				else if (maze[y - 1][x] == ' ')
					return (1);
				else if (maze[y][x + 1] == ' ')
					return (1);
				else if (maze[y][x - 1] == ' ')
					return (1);
			}
			else
				return (1);
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
	int		width;
	int		height;
	char	*line;
	char	**maze;

	width = map->w;
	height = map->h;
	maze = map->map_info;
	y = 0;
	while (maze[y] != NULL)
	{
		line = maze[y];
		if (y == 0 || y == (height - 1))
		{
			while (*line != '\0')
			{
				if (*line != ' ' && *line != '1')
					return (1);
				line++;
			}
		}
		else
			if ((line[0] != '1' && line[0] != ' ')
				|| (line[width - 1] != '1' && line[width - 1] != ' '))
				return (1);
		y++;
	}
	return (0);
}

// 미로 세팅 및 map 인자 체크 할 에정
// void set_map(char *map_dir, t_map *map)
// {
// 	int		fd;
// 	char	*line;
// 	char	**maze;

// 	fd = open(map_dir, O_RDONLY);
// 	if (fd == -1)
// 		ft_error("File can't open this time\n");
// 	maze = map->map_info;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		if (*line == ' ' || *line == '1')
// 			exit(ft_error("Map is first"));
// 		else
// 		{
// 			if (check_arg(map))
// 			{
// 				*maze = malloc(sizeof(char) * (map->w + 1));
// 				if (*maze == NULL)
// 					exit(1);
// 				(*maze)[map->w] = '\0';
// 				ft_memset(*maze, ' ', map->w);
// 				ft_memcpy(*maze, line, ft_strlen(line));
// 				maze++;
// 			}
// 			else
// 				exit(ft_error("Argument Error"));
// 		}
// 	}
// }

// map의 maze를 제외한 인자들 먼저 확인
void	set_arg(char *map_dir, t_map *map)
{
	int		fd;
	char	*line;
	char	**maze;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		ft_error("File can't open this time\n");
	maze = map->arg_info;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (!ft_strncmp(line, "NO ", 3))
		{
			if (map->a_count[E_NO] == 0)
			{
				map->a_count[E_NO] = 1;
				//a.cnt++;
			}
			else
				//error
		}
			map->a_count++;
		else if (!ft_strncmp(line, "SO ", 3))
			map->a_count++;
		else if (!ft_strncmp(line, "EA ", 3))
			map->a_count++;
		else if (!ft_strncmp(line, "WE ", 3))
			map->a_count++;
		else if (!ft_strncmp(line, "F ", 2))
			map->a_count++;
		else if (!ft_strncmp(line, "C ", 2))
			map->a_count++;
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
void	set_map_height_width(char *map_dir, t_map *map)
{
	int		i;
	int		fd;
	int		height;
	int		width;
	char	*line;
	int		tmp;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		exit(ft_error("Failed To Open File\n"));
	width = 0;
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_converter(line);
		tmp = ft_strlen(line);
		if (tmp > width)
			width = tmp;
		i = 0;
		while (line[i])
		{
			if (line[i] == 'N' || line[i] == 'E' || line[i] == 'W' || line[i] == 'S')
				map->p_count++;
			i++;
		}
		free(line);
		height++;
	}
	if (map->p_count != 1)
		exit (ft_error("map error"));
	close(fd);
	map->w = width;
	map->h = height;
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

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	map;

	if (ac != 2)
		return (ft_error("Wrong arguments  [./cub3D] [*.cub]"));
	file_name = av[1];
	check_extension(file_name);
	map.p_count = 0;
	ft_memset(map.a_count, 0, sizeof(map.a_count));
	set_map_height_width(file_name, &map);
	map.map_info = malloc(sizeof(char *) * (map.h + 1));
	if (map.map_info == NULL)
		exit(1);
	map.map_info[map.h] = NULL;
	// set_map(file_name, &map);
	if (check_border(&map) || check_news(&map))
		return (ft_error("map error"));
	printf("Success\n");
	return (0);
}
