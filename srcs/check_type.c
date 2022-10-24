#include "includes/cub3d.h"

static void	check_comma(char *str)
{
	int	flag;

	flag = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) != 1)
		{
			if (flag == 0)
				flag = 1;
			else
				exit(ft_error("more comma very comma !!"));
		}
		else
			flag = 0;
		str++;
	}
	if (flag == 1)
		exit(ft_error("more comma very comma !!"));
}

static void	set_texture(char **arr, char **texture, t_texture_types type)
{
	if (get_arr_len(arr) != 2)
		exit(ft_error("len error"));
	if (texture[type] == NULL)
	{
		texture[type] = arr[1];
		return ;
	}
	else
		exit(ft_error("texture dup error"));
	return ;
}

static void	set_rgb(char **arr, int **rgb, t_rgb_types type)
{
	char	**split;
	int		i;

	i = 0;
	if (get_arr_len(arr) != 2)
		exit(ft_error("len error"));
	if (rgb[type] == NULL)
	{
		check_comma(arr[1]);
		rgb[type] = malloc(sizeof(int) * 3);
		split = ft_split(arr[1], ',');
		if (get_arr_len(split) != 3)
			exit(ft_error("rgb value error"));
		while (i < 3)
		{
			rgb[type][i] = ft_atoi(split[i]);
			if (rgb[type][i] < 0 || rgb[type][i] > 255)
				exit(ft_error("rgb value error"));
			free(split[i++]);
		}
		free(split);
		free(arr[1]);
	}
	else
		exit(ft_error("dup error"));
}

void	check_type(t_map *map, char **arr)
{
	if (ft_strcmp("NO", arr[0]) == 0)
		set_texture(arr, map->texture, E_NO);
	else if (ft_strcmp("SO", arr[0]) == 0)
		set_texture(arr, map->texture, E_SO);
	else if (ft_strcmp("EA", arr[0]) == 0)
		set_texture(arr, map->texture, E_EA);
	else if (ft_strcmp("WE", arr[0]) == 0)
		set_texture(arr, map->texture, E_WE);
	else if (ft_strncmp(arr[0], "F", 2) == 0)
		set_rgb(arr, map->rgb, E_F);
	else if (ft_strcmp("C", arr[0]) == 0)
		set_rgb(arr, map->rgb, E_C);
}
