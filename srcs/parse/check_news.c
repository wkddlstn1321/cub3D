#include "includes/cub3d.h"

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
