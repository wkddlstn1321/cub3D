#include "includes/cub3d.h"

void	ver_line(int x, int draw_start, int draw_end, t_map *map)
{
	int	i;

	i = 0;
	while (i++ < SCREEN_HEIGHT)
	{
		if (i > draw_start && i < draw_end)
			map->img.img_set[x + i * map->img.size_line / 4] = 0x0FFF00;
	}
}
