#include "includes/cub3d.h"

void	set_side(t_dda *dda, t_map *map)
{
	t_vector	between;

	if (dda->ray_dir.x >= 0)
	{
		between.x = (dda->map_x + 1) - map->player.pos.x;
		dda->step.x = 1;
	}
	else
	{
		between.x = map->player.pos.x - dda->map_x;
		dda->step.x = -1;
	}
	if (dda->ray_dir.y >= 0)
	{
		between.y = (dda->map_y + 1) - map->player.pos.y;
		dda->step.y = 1;
	}
	else
	{
		between.y = map->player.pos.y - dda->map_y;
		dda->step.y = -1;
	}
	dda->side.x = between.x * dda->delta.x;
	dda->side.y = between.y * dda->delta.y;
}
