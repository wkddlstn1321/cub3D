#include "includes/cub3d.h"

static void	ver_line(int x, int draw_start, int draw_end, t_map *map, t_dda *dda)
{
	int	i;
	int	s;

	i = 0;
	s = dda->texture_start;
	// printf("start %d\n", s);
	while (i++ < SCREEN_HEIGHT)
	{
		if (i > draw_start && i < draw_end)
		{
			int x_pos = dda->wall_hit_point * 64;
			if (dda->check_wall == 0)
			{
				if (dda->ray_dir.x < 0)
					x_pos = 64 - x_pos - 1;
			}
			if (dda->check_wall == 1)
			{
				if (dda->ray_dir.y > 0)
					x_pos = 64 - x_pos - 1;
			}
			if (s < 0)
				s *= -1;
			map->img.img_set[x + i * map->img.size_line / 4] = map->sprite_info[dda->news][s * 64 / dda->line_h][x_pos];
			s++;
		}
	}
}

void	draw_map(t_map *map, double distan, int x, t_dda *dda)
{
	int	line_h;
	int	draw_start;
	int	draw_end;

	line_h = (int)(SCREEN_HEIGHT / distan);
	dda->tex_step = line_h / 64;
	dda->texture_start = 0;
	dda->line_h = line_h;
	draw_start = (SCREEN_HEIGHT / 2) - (line_h / 2);
	if (draw_start < 0)
	{
		dda->texture_start = draw_start / dda->tex_step;		
		// printf("start %d\n", dda->texture_start);
		draw_start = 0;
	}
	draw_end = (SCREEN_HEIGHT / 2) + (line_h / 2);
	if (draw_end > SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT;
	ver_line(x, draw_start, draw_end, map, dda);
}
