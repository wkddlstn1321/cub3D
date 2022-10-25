// #include "cub3d.h"

// void *mlx_win;
// void *mlx;
// void *new_win;
// void *img;
// char *img_path = "/Users/hyunjung/cub3D/imgs/dogeye.XPM";
// int x;
// int y;

// typedef struct s_new_img
// {
// 	void	*img;
// 	int		*img_set;
// 	int		bits_per_pixel;
// 	int		size_line;
// 	int		endian;
// 	int		x;
// 	int		y;
// }	t_new_img;

// int bits_per_pixel = 0;
// int size_line = 0;
// int endian = 0;
// int	*data;
// int	*img_data;

// int	stop_game(void)
// {
// 	mlx_destroy_window(mlx, mlx_win);
// 	exit(1);
// }

// int	on_key_press(void)
// {
// 	exit(EXIT_SUCCESS);
// }

// int		find_color(t_new_img *dog, int col, int row)
// {
// 	int color;
// 	int height = dog->y;
// 	int width = dog->x;
// 	int result_row = (height * row) / SCREEN_HEIGHT;
// 	int result_col = (width * col) / SCREEN_WIDTH;
	
// 	color = dog->img_set[width * result_row + result_col];
// 	return (color);
// }

// void	execute_mlx(double dis, int xpos)
// {
// 	t_new_img dog;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "insjang");
// 	dog.endian = 0;
// 	dog.size_line = 0;
// 	dog.bits_per_pixel = 0;
// 	dog.img = mlx_xpm_file_to_image(mlx, img_path, &dog.x, &dog.y);
// 	dog.img_set = (int *)mlx_get_data_addr(dog.img, &dog.bits_per_pixel, &dog.size_line, &dog.endian);
// 	new_win = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
// 	img_data = (int *)mlx_get_data_addr(new_win, &bits_per_pixel, &size_line, &endian);
	
// 	// for (int j = 0 ; j < SCREEN_HEIGHT ; j++)
// 	// {
// 	// 	for (int i = 0; i < SCREEN_WIDTH ; i++)
// 	// 	{
// 	// 		if (j < SCREEN_HEIGHT / 2)
// 	// 			img_data[i + (j * size_line / 4)] = (220 << 16) + (90 << 8) + 15;
// 	// 		else
// 	// 			img_data[i + (j * size_line / 4)] = (225 * 255 * 255) + (30 * 255) + 0;
// 	// 	}
// 	// }
// 	printf("x %f y %d\n", dis, dog.y);
// 	for (int i = SCREEN_HEIGHT / 2 - dis / 2 ; i < SCREEN_HEIGHT / 2 + dis / 2 ; i++)
// 	{
// 		printf("???\n");
// 		img_data[xpos + i * size_line / 4] = 213414;
// 		// img_data[xpos + i * size_line / 4] = find_color(&dog, xpos, i);
// 	}
// 	for (int j = 0 ; j < SCREEN_HEIGHT ; j++)
// 	{
// 		for (int i = 0; i < SCREEN_WIDTH ; i++)
// 			img_data[i + j * size_line / 4] = find_color(&dog, i, j);
// 	}
// }
