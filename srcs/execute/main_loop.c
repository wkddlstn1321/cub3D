#include "includes/cub3d.h"

int	main_loop(t_map *map)
{
	t_dda		dda;
	double		angle;
	int			x;

	draw_bg(map);
	map->player.dir.x = -1 * cos(map->player.angle);
	map->player.dir.y = -1 * sin(map->player.angle);
	map->player.plane.x = 0.66 * sin(map->player.angle);
	map->player.plane.y = -0.66 * cos(map->player.angle);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		angle = 2 * x / (double)SCREEN_WIDTH - 1;
		dda.ray_dir.x = angle * map->player.plane.x + map->player.dir.x;
		dda.ray_dir.y = angle * map->player.plane.y + map->player.dir.y;
		execute(map, &dda, x);
		x++;
	}
	mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.img, 0, 0);
	return (0);
}
