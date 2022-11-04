#include "includes/cub3d.h"

void	set_mlx_win(t_map *map)
{
	t_mlx_info	*screen;

	screen = &map->spr;
	screen->mlx = mlx_init();
	screen->win = mlx_new_window(screen->mlx, \
		SCREEN_W, SCREEN_H, "cub3D");
	screen->img = mlx_new_image(screen->mlx, SCREEN_W, SCREEN_H);
	screen->img_set = (int *)mlx_get_data_addr(screen->img, \
		&screen->bits_per_pixel,
			&screen->size_line, &screen->endian);
	map->sprite_info = ft_calloc(4, sizeof(int **));
}
