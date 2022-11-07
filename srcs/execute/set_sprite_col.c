#include "includes/cub3d.h"

void	get_hit_wall_col(int ***texture, t_map *map, t_dda *dda, double dist)
{
	double	wallx;

	if (dda->ray_dir.x < 0)
	{
		*texture = map->sprite_info[EA];
		dda->spr_dir = EA;
	}
	else
	{
		*texture = map->sprite_info[WE];
		dda->spr_dir = WE;
	}
	wallx = map->player.pos.y + dist * dda->ray_dir.y;
	dda->wall_hit_point = wallx - floor(wallx);
}

void	get_hit_wall_row(int ***texture, t_map *map, t_dda *dda, double dist)
{
	double	wallx;

	if (dda->ray_dir.y < 0)
	{
		*texture = map->sprite_info[SO];
		dda->spr_dir = SO;
	}
	else
	{
		*texture = map->sprite_info[NO];
		dda->spr_dir = NO;
	}
	wallx = map->player.pos.x + dist * dda->ray_dir.x;
	dda->wall_hit_point = wallx - floor(wallx);
}

void	set_sprite_col(int ***texture, t_map *map, t_dda *dda, double dist)
{
	if (dda->check_wall == 0)
		get_hit_wall_col(texture, map, dda, dist);
	else
		get_hit_wall_row(texture, map, dda, dist);
}
