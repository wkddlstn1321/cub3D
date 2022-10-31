#include "includes/cub3d.h"

// void	set_img(t_new_img img, int	**texture)
// {
// 	void	*img_set;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	texture = ft_calloc(sizeof(int *), img.y);
// 	if (texture == NULL)
// 		exit(ft_error("malloc error"));
// 	img_set = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line, &img.endian);
// 	while (i < img.y)
// 	{
// 		j = 0;
// 		texture[i] = malloc(sizeof(int) * img.x);
// 		while (j < img.x)
// 		{
// 			texture[i][j] = 456;
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	save_img_data(t_map *map)
{
	int			i;
	t_new_img	img;
	
	i = 0;
	while (i < 4)
	{
		img.img = mlx_xpm_file_to_image(map->mlx, map->texture_path[i], &img.x, &img.y);
		if (img.img == NULL)
			exit(ft_error("wrong texture_path path"));
		// set_img(img, map->texture_path[i]);
		mlx_destroy_image(map->mlx, img.img);
		i++;
	}
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
	// save_img_data(&map);
	printf("Success\n");
	dda(&map);
	// execute_mlx();
	return (0);
}
