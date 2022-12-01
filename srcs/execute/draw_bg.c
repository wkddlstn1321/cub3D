#include "includes/cub3d.h"

void	draw_bg(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_H)
	{
		j = 0;
		while (j < SCREEN_W)
		{
			if (i < SCREEN_H / 2)
				map->spr.img_set[j + (i * map->spr.size_line / 4)]
					= (map->rgb[1][0] << 16)
					+ (map->rgb[1][1] << 8) + map->rgb[0][2];
			else
				map->spr.img_set[j + (i * map->spr.size_line / 4)]
					= (map->rgb[0][0] << 16)
					+ (map->rgb[0][1] << 8) + map->rgb[1][2];
			j++;
		}
		i++;
	}
}
