#include "includes/cub3d.h"

void	get_hit_wall_col(int ***texture, t_map *map, t_dda *dda, double dis)
{
	double	wallx;

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

void	get_hit_wall_row(int ***texture, t_map *map, t_dda *dda, double dis)
{
	double	wallx;

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

void	set_sprite_col(int ***texture, t_map *map, t_dda *dda, double dis)
{
	if (dda->check_wall == 0)
		get_hit_wall_col(texture, map, dda, dis);
	else
		get_hit_wall_row(texture, map, dda, dis);
}
