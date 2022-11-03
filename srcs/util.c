#include "includes/cub3d.h"

int	ft_error(char *str)
{
	printf("Error\n");
	printf("%s\n", str);
	return (1);
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

void	check_extension(char *dir)
{
	char	*extension;
	int		extension_len;
	int		idx;

	idx = ft_strlen(dir) - ft_strlen(MAP_EXTENSION);
	if (idx < 0)
		exit(ft_error("Map Extension Is Wrong"));
	extension = &dir[idx];
	extension_len = ft_strlen(extension);
	if (*extension == '.')
		if (!ft_strncmp(extension, MAP_EXTENSION, extension_len))
			return ;
	exit(ft_error("Map Extension Is Wrong"));
}

int	get_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr != NULL && arr[len] != NULL)
		len++;
	return (len);
}

double	ft_dtor(double degree)
{
	return (degree * M_PI / 180);
}
