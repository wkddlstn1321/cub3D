#include "includes/cub3d.h"

static void	set_img(t_mlx_info *img, int	**sprite)
{
	int		i;
	int		j;

	img->img_set = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	i = 0;
	while (i < img->y)
	{
		sprite[i] = malloc(sizeof(int) * img->x);
		if (sprite[i] == NULL)
			exit(ft_error("malloc error"));
		j = 0;
		while (j < img->x)
		{
			sprite[i][j] = img->img_set[j + i * img->size_line / 4];
			j++;
		}
		i++;
	}
}

void	save_sprite_data(t_map *map, void *mlx)
{
	int			i;
	t_mlx_info	img;

	img.mlx = mlx;
	i = 0;
	while (i < 4)
	{
		img.img
			= mlx_xpm_file_to_image
			(img.mlx, map->texture_path[i], &img.x, &img.y);
		if (img.img == NULL)
			exit(ft_error("wrong texture_path path"));
		map->sprite_info[i] = malloc(sizeof(int *) * img.y);
		if (map->sprite_info[i] == NULL)
			exit(ft_error("malloc error"));
		set_img(&img, map->sprite_info[i]);
		map->xy[i][0] = img.x;
		map->xy[i][1] = img.y;
		mlx_destroy_image(img.mlx, img.img);
		i++;
	}
}
