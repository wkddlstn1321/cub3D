#include "includes/cub3d.h"

static	void	init_map_info(char **contents, t_map *map)
{
	int		i;

	i = 0;
	if (map->h == 0)
		exit(ft_error("no map"));
	map->map_info = calloc(sizeof(char *), (map->h + 1));
	if (map->map_info == NULL)
		exit(ft_error("malloc error"));
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

static	int	get_p_count(char **contents)
{
	int	x;
	int	y;
	int	p_count;

	y = 0;
	p_count = 0;
	while (contents[y] != NULL)
	{
		x = 0;
		while (contents[y][x])
		{
			if (contents[y][x] == 'N' || contents[y][x] == 'E'
				|| contents[y][x] == 'W' || contents[y][x] == 'S')
				p_count++;
			x++;
		}
		y++;
	}
	if (p_count != 1)
		exit(ft_error("too many players"));
	return (p_count);
}

static	int	get_max_width(char **contents)
{
	int	idx;
	int	line_len;
	int	tmp;

	idx = 0;
	line_len = 0;
	tmp = 0;
	while (contents[idx] != NULL)
	{
		tmp = ft_strlen(contents[idx]);
		if (tmp > line_len)
			line_len = tmp;
		idx++;
	}
	return (line_len);
}

void	set_map(t_map *map, char **contents)
{
	int	map_start_idx;

	map->texture_path = ft_calloc(sizeof(char *), 5);
	map->rgb = ft_calloc(sizeof(int *), 2);
	map_start_idx = set_arg(contents, map);
	map->h = get_arr_len(&(contents[map_start_idx]));
	map->w = get_max_width(&(contents[map_start_idx]));
	map->p_count = get_p_count(&(contents[map_start_idx]));
	init_map_info(&(contents[map_start_idx]), map);
	
	//test
	// map->mlx = mlx_init();
	// map->mlx_win = mlx_new_window(map->mlx,
	// 		SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	//test
}
