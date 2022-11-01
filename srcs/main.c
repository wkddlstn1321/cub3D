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
		mlx_init(img.mlx);
		img.img = mlx_xpm_file_to_image(img.mlx, map->texture_path[i], &img.x, &img.y);
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
	// map->sprite_info = ft_calloc(4, sizeof(int **));
}

int	main(int ac, char **av)
{
	char	*file_name;
	char	**contents;
	t_map	map;

	if (ac != 2)
		return (ft_error("Wrong arguments  [./cub3D] [*.cub]"));
	file_name = av[1];
	check_extension(file_name);
	contents = init_contents(file_name);
	set_map(&map, contents);
	check_border(&map);
	check_news(map.map_info, map.w, map.h);
	set_player_pos(&map);
	set_mlx_win(&map);
	// save_sprite_data(&map);
	printf("Success\n");
	dda(&map);
	// execute_mlx();
	return (0);
}
