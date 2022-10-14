#include "includes/cub3d.h"

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

void set_map(char *map_dir, t_map *map)
{
	int		fd;
	char	*line;
	char	**maze;

	fd = open(map_dir, O_RDONLY);
	if (fd == -1)
		ft_error("File can't open this time\n");
	maze = map->map_info;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		*maze = malloc(sizeof(char) * (map->w + 1));
		if (*maze == NULL)
			exit(1);
		(*maze)[map->w] = '\0';
		ft_memset(*maze, ' ', map->w);
		ft_memcpy(*maze, line, ft_strlen(line));
		maze++;
	}
}

void	ft_converter(char *line)
{
	while (*line)
	{
		if (*line == '\n')
			*line = '\0';
		line++;
	}
}

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

int	main(int ac, char **av)
{
	char	*file_name;
	t_map	map;

	if (ac != 2)
		return (ft_error("Wrong arguments  [./cub3D] [*.cub]"));
	file_name = av[1];
	check_extension(file_name);
	map.p_count = 0;
	set_map_height_width(file_name, &map);
	map.map_info = malloc(sizeof(char *) * (map.h + 1));
	if (map.map_info == NULL)
		exit(1);
	map.map_info[map.h] = NULL;
	set_map(file_name, &map);
	if (check_border(&map) || check_news(&map))
		return (ft_error("map error"));
	return (0);
}
