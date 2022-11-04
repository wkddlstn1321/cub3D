#include "includes/cub3d.h"

void	set_delta(t_map *map, t_dda *dda)
{
	double	ray_dist;

	ray_dist = sqrt(pow(dda->ray_dir.x, 2) + pow(dda->ray_dir.y, 2));
	dda->map_x = (int)(map->player.pos.x);
	dda->map_y = (int)(map->player.pos.y);
	dda->delta.x = fabs(ray_dist / dda->ray_dir.x);
	dda->delta.y = fabs(ray_dist / dda->ray_dir.y);
}
