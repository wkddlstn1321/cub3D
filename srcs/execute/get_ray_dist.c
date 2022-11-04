#include "includes/cub3d.h"

double	get_ray_dist(t_dda *dda)
{
	double	distan;

	if (dda->check_wall == 0)
	{
		distan = dda->side.x - dda->delta.x;
		distan *= 1 / sqrt(pow(dda->ray_dir.x, 2) + pow(dda->ray_dir.y, 2));
	}
	else
	{
		distan = dda->side.y - dda->delta.y;
		distan *= 1 / sqrt(pow(dda->ray_dir.x, 2) + pow(dda->ray_dir.y, 2));
	}
	distan *= (1 << 16);
	distan = round(distan);
	distan /= (1 << 16);
	return (distan);
}
