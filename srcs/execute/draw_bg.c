#include "includes/cub3d.h"

//	map에 이미지 데이터 추가하기
void	draw_bg(t_map *map)
{
	for(int j = 0 ; j < SCREEN_HEIGHT ; j++)
	{
		for (int i = 0; i < SCREEN_WIDTH ; i++)
		{
			if (j < SCREEN_HEIGHT / 2)
				map->img.img_set[i + (j * map->img.size_line / 4)]
					= (220 << 16) + (90 << 8) + 15;
			else
				map->img.img_set[i + (j * map->img.size_line / 4)]
					= (225 * 255 * 255) + (30 * 255) + 0;
		}
	}
}
