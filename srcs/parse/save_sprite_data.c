#include "includes/cub3d.h"

void	set_img(t_new_img *img, int	**sprite)
{
	int		i;
	int		j;

	img->img_set = (int *)mlx_get_data_addr(img->mlx, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	i = 0;
	while (i < img->y)
	{
		j = 0;
		sprite[i] = malloc(sizeof(int) * img->x);
		if (sprite[i] == NULL)
			exit(ft_error("malloc error"));
		while (j < img->x)
		{
			sprite[i][j] = img->img_set[j + i * img->size_line / 4];
			j++;
		}
		i++;
	}
}

void	save_sprite_data(t_map *map)
{
	int			i;
	t_new_img	img;

	i = 0;
	while (i < 1)
	{
		img.mlx = mlx_init();
		img.img
			= mlx_xpm_file_to_image
			(img.mlx, map->texture_path[i], &img.x, &img.y);
		if (img.img == NULL)
			exit(ft_error("wrong texture_path path"));
		map->sprite_info[i] = malloc(sizeof(int *) * img.y);
		if (map->sprite_info[i] == NULL)
			exit(ft_error("malloc error"));
		set_img(&img, map->sprite_info[i]);
		mlx_destroy_image(img.mlx, img.img);
		i++;
	}
}
