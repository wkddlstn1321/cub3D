#include "includes/cub3d.h"

void	set_text_x(int ***texture, t_map *map, t_dda *dda, double dis)
{
	double	wallx;

	if (dda->check_wall == 0)
	{
		if (dda->ray_dir.x < 0)
		{
			*texture = map->sprite_info[E_EA];
			dda->news = E_EA;
		}
		else
		{
			*texture = map->sprite_info[E_WE];
			dda->news = E_WE;
		}
		wallx = map->player.pos.y + dis * dda->ray_dir.y;
		dda->wall_hit_point = wallx - floor(wallx);
	}
	else
	{
		if (dda->ray_dir.y < 0)
		{
			*texture = map->sprite_info[E_SO];
			dda->news = E_SO;
		}
		else
		{
			*texture = map->sprite_info[E_NO];
			dda->news = E_NO;
		}
		wallx = map->player.pos.x + dis * dda->ray_dir.x;
		dda->wall_hit_point = wallx - floor(wallx);
	}
}

void	execute(t_map *map, t_dda *dda, int x)
{	
	double	distan;
	int		**texture;

	set_delta(map, dda);
	set_side(dda, map);
	check_hit(dda, map);
	distan = get_ray_dist(dda);
	set_text_x(&texture, map, dda, distan);
	draw_map(map, distan, x, dda);
}
