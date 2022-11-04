#include "includes/cub3d.h"

static int	get_x_pos(t_dda *dda)
{
	int	x_pos;
	int	sprite_x_size;

	sprite_x_size = dda->xy[dda->spr_dir][0];
	x_pos = dda->wall_hit_point * sprite_x_size;
	if (dda->check_wall == 0)
	{
		if (dda->ray_dir.x < 0)
			x_pos = sprite_x_size - x_pos - 1;
	}
	if (dda->check_wall == 1)
	{
		if (dda->ray_dir.y > 0)
			x_pos = sprite_x_size - x_pos - 1;
	}
	return (x_pos);
}

static void	ver_line(int x, t_map *map, t_dda *dda)
{
	int	i;
	int	s;
	int	x_pos;

	i = 0;
	s = dda->spr_start;
	while (i < SCREEN_H)
	{
		if (i >= dda->draw_start && i < dda->draw_end)
		{
			x_pos = get_x_pos(dda);
			map->spr.img_set[x + i * map->spr.size_line / 4]
				= map->sprite_info[dda->spr_dir][s * dda->xy \
				[dda->spr_dir][1] / dda->line_h][x_pos];
			s++;
		}
		i++;
	}
}

void	asd(t_map *map, t_dda *dda)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 2)
		{
			dda->xy[i][j] = map->xy[i][j];
			j++;
		}
		i++;
	}
}

void	draw_map(t_map *map, double distan, int x, t_dda *dda)
{
	int	line_h;
	int	draw_start;
	int	draw_end;

	asd(map, dda);
	line_h = (int)(SCREEN_H / distan);
	dda->spr_start = 0;
	dda->line_h = line_h;
	draw_start = (SCREEN_H / 2) - (line_h / 2);
	if (draw_start < 0)
	{
		dda->spr_start = -draw_start;
		draw_start = 0;
	}
	draw_end = (SCREEN_H / 2) + (line_h / 2);
	if (draw_end > SCREEN_H)
		draw_end = SCREEN_H;
	dda->draw_start = draw_start;
	dda->draw_end = draw_end;
	ver_line(x, map, dda);
}
