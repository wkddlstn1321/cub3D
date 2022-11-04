#include "includes/cub3d.h"

static void	check_arg_input_value(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->texture_path[i] == NULL)
			exit(ft_error("texture is null"));
		i++;
	}
	i = 0;
	while (i < 2)
	{
		if (map->rgb[i] == NULL)
			exit(ft_error("rgb is null"));
		i++;
	}
}

int	set_arg(char **contents, t_map *map)
{
	int		i;
	char	**arr;

	i = 0;
	while (contents[i] != NULL)
	{
		if (*(contents[i]) != '\0')
		{
			if (ft_isalpha(*(contents[i])) == 0)
				break ;
			arr = ft_split(contents[i], ' ');
			if (arr == NULL)
				exit(ft_error("malloc error"));
			check_type(map, arr);
			free(arr[0]);
			free(arr);
		}
		i++;
	}
	check_arg_input_value(map);
	return (i);
}
