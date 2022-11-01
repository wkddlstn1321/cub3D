#include "includes/cub3d.h"

void	execute(t_map *map, t_dda *dda, int x)
{	
	double	distan;

	set_delta(map, dda);
	set_side(dda, map);
	check_hit(dda, map);
	distan = get_ray_dist(dda);
	draw_map(map, distan, x);
}
