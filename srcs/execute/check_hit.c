#include "includes/cub3d.h"

void	check_hit(t_dda *dda, t_map *map)
{
	// t_vector	start_side_dis;
	int			hit;

	hit = 0;
	// start_side_dis.x = dda->side.x;
	// start_side_dis.y = dda->side.y;
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
