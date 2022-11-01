#include "includes/cub3d.h"

void	draw_map(t_map *map, double distan, int x)
{
	int	line_h;
	int	draw_start;
	int	draw_end;

	line_h = (int)(SCREEN_HEIGHT / distan);
	draw_start = SCREEN_HEIGHT / 2 - (line_h / 2);
	if (draw_start < 0)
		draw_start = 0;
	draw_end = SCREEN_HEIGHT / 2 + (line_h / 2);
	if (draw_end > SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT;
	ver_line(x, draw_start, draw_end, map);
}
