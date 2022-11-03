#include "includes/cub3d.h"

void	execute(t_map *map, t_dda *dda, int x)
{	
	double	distan;
	int		**texture;

	set_delta(map, dda);
	set_side(dda, map);
	check_hit(dda, map);
	distan = get_ray_dist(dda);
	set_sprite_col(&texture, map, dda, distan);
	draw_map(map, distan, x, dda);
}
