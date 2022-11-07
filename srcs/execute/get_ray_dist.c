#include "includes/cub3d.h"

double	get_ray_dist(t_map *map, t_dda *dda)
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
