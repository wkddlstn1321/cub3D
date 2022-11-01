#include "includes/cub3d.h"

void	set_mlx_win(t_map *map)
{
	t_new_img	*img;

	img = &map->img;
	img->mlx = mlx_init();
	img->win = mlx_new_window(img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	img->img = mlx_new_image(img->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->img_set = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	printf("%d %d %d\n", img->bits_per_pixel, img->size_line, img->endian);
	map->sprite_info = ft_calloc(4, sizeof(int **));
}
