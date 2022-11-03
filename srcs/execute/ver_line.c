#include "includes/cub3d.h"


//draw_map.c 파일에서 static 함수로 선언해도 될 듯
// void	ver_line(int x, int draw_start, int draw_end, t_map *map, t_dda *dda)
// {
// 	int	i;
// 	int	s;

// 	i = 0;
// 	s = 0;
// 	while (i++ < SCREEN_HEIGHT)
// 	{
// 		if (i > draw_start && i < draw_end)
// 		{
// 			if (dda->check_wall == 0 && dda->ray_dir.x < 0)
// 			{
// 				int x_pos = dda->wall_hit_point * 64;
// 				x_pos = 64 - x_pos - 1;
// 				map->img.img_set[x + i * map->img.size_line / 4] = map->sprite_info[1][s * 64 / dda->line_h][x_pos];
// 				s++;
// 			}
// 			else
// 				map->img.img_set[x + i * map->img.size_line / 4] = 0x0FFF00;
// 		}
// 	}
// }
