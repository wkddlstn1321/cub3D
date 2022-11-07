#include "includes/cub3d.h"

void	execute(t_map *map, t_dda *dda, int x)
{	
	double	dist;
	int		**texture;

	set_delta(map, dda);
	set_side(dda, map);
	check_hit(dda, map);
	dist = get_ray_dist(map, dda);
	set_sprite_col(&texture, map, dda, dist);
	draw_map(map, dist, x, dda);
}
