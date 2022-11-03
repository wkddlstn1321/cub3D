#include "includes/cub3d.h"

static int	get_x_pos(t_dda *dda)
{
	int	x_pos;

	x_pos = dda->wall_hit_point * 64;
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
	return (x_pos);
}

static void	ver_line(int x, t_map *map, t_dda *dda)
{
	int	i;
	int	s;
	int	x_pos;

	i = 0;
	s = dda->texture_start;
	while (i++ < SCREEN_HEIGHT)
	{
		if (i > dda->draw_start && i < dda->draw_end)
		{
			x_pos = get_x_pos(dda);
			map->img.img_set[x + i * map->img.size_line / 4]
				= map->sprite_info[dda->news][s * 64 / dda->line_h][x_pos];
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
	dda->texture_start = 0;
	dda->line_h = line_h;
	draw_start = (SCREEN_HEIGHT / 2) - (line_h / 2);
	if (draw_start < 0)
	{
		dda->texture_start = -draw_start;
		draw_start = 0;
	}
	draw_end = (SCREEN_HEIGHT / 2) + (line_h / 2);
	if (draw_end > SCREEN_HEIGHT)
		draw_end = SCREEN_HEIGHT;
	dda->draw_start = draw_start;
	dda->draw_end = draw_end;
	ver_line(x, map, dda);
}
