#include "includes/cub3d.h"

static	int	get_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr != NULL && arr[len] != NULL)
		len++;
	return (len);
}

void	set_texture(char **arr, char **texture, t_texture_types type)
{
	if (get_arr_len(arr) != 2)
		exit(ft_error("len error"));
	if (texture[type] == NULL)
	{
		ft_converter(arr[1]);
		texture[type] = arr[1];
		return ;
	}
	else
		exit(ft_error("texture dup error"));
	return ;
}

void	set_rgb(char **arr, int **rgb, t_rgb_types type)
{
	char	**split;
	int		i;

	i = 0;
	if (get_arr_len(arr) != 2)
		exit(ft_error("len error"));
	if (rgb[type] == NULL)
	{
		rgb[type] = malloc(sizeof(int) * 3);
		split = ft_split(arr[1], ',');
		if (get_arr_len(split) != 3)
			exit(ft_error("rgb value error"));
		while (i < 3)
		{
			rgb[type][i] = ft_atoi(split[i]);
			// rgb 언더플로우, 부호만, -1 반환
			if (rgb[type][i] < 0 || rgb[type][i] > 255)
				exit(ft_error("rgb value error"));
			i++;
		}
		free(split[0]);
		free(split[1]);
		free(split[2]);
		free(split);
		free(arr[1]);
		return ;
	}
	else
		exit(ft_error("dup error"));
	return ;
}

int	set_arg(char **contents, t_map *map)
{
	int		i;
	char	**arr;

	i = 0;
	while (contents[i] != NULL)
	{
		if (*(contents[i]) != '\n')
		{
			if (ft_isalpha(*(contents[i])) == 0)
				break ;
			arr = ft_split(contents[i], ' ');
			printf("arr[i], %s\n", arr[0]);
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
			free(arr[0]);
			free(arr);
		}
		i++;
	}
	// 값이 개수 체크
	return (i);
}

// while 컨텐츠
// 	if 개행만 있는 경우
// 		넘김
// 	while(맞는 값인가?)
// 		값을 세팅(값이 제대로 들어왔는가?)
// 		j++
// 	j == 6 이라면
// 		break
// 	6이 아니라면 i++
// 값이 6개인가?
// 	i return
// 그외 exit