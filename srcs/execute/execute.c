#include "includes/cub3d.h"

static void	set_side(t_dda *dda, t_map *map)
{
	dda->map_x = (int)(map->player.pos.x);
	dda->map_y = (int)(map->player.pos.y);
	dda->delta.x = fabs(1 / dda->ray_dir.x);
	dda->delta.y = fabs(1 / dda->ray_dir.y);
	if (dda->ray_dir.x >= 0)
	{
		dda->side.x = ((dda->map_x + 1) - map->player.pos.x) * dda->delta.x;
		dda->step.x = 1;
	}
	else
	{
		dda->side.x = (map->player.pos.x - dda->map_x) * dda->delta.x;
		dda->step.x = -1;
	}
	if (dda->ray_dir.y >= 0)
	{
		dda->side.y = ((dda->map_y + 1) - map->player.pos.y) * dda->delta.y;
		dda->step.y = 1;
	}
	else
	{
		dda->side.y = (map->player.pos.y - dda->map_y) * dda->delta.y;
		dda->step.y = -1;
	}
}

static void	check_hit(t_dda *dda, t_map *map)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (dda->side.x <= dda->side.y)
		{
			dda->side.x += dda->delta.x;
			dda->map_x += dda->step.x;
			dda->check_wall = 0;
		}
		else
		{
			dda->side.y += dda->delta.y;
			dda->map_y += dda->step.y;
			dda->check_wall = 1;
		}
		if (map->map_info[dda->map_y][dda->map_x] == '1')
			hit = 1;
	}
}

static double	get_ray_dist(t_map *map, t_dda *dda)
{
	double	dist;

	if (dda->check_wall == 0)
	{
		dist = (dda->map_x - map->player.pos.x \
		+ (1 - dda->step.x) / 2) / dda->ray_dir.x;
	}
	else
	{
		dist = (dda->map_y - map->player.pos.y \
		+ (1 - dda->step.y) / 2) / dda->ray_dir.y;
	}
	return (dist);
}

static void	set_sprite_col(t_map *map, t_dda *dda, double dist)
{
	double	wallx;

	if (dda->check_wall == 0)
	{
		if (dda->ray_dir.x < 0)
			dda->spr_dir = EA;
		else
			dda->spr_dir = WE;
		wallx = map->player.pos.y + dist * dda->ray_dir.y;
		dda->wall_hit_point = wallx - floor(wallx);
	}
	else
	{
		if (dda->ray_dir.y < 0)
			dda->spr_dir = SO;
		else
			dda->spr_dir = NO;
		wallx = map->player.pos.x + dist * dda->ray_dir.x;
		dda->wall_hit_point = wallx - floor(wallx);
	}
}

void	execute(t_map *map, t_dda *dda, int x)
{	
	double	dist;

	set_side(dda, map);
	check_hit(dda, map);
	dist = get_ray_dist(map, dda);
	set_sprite_col(map, dda, dist);
	draw_map(map, dist, x, dda);
}
