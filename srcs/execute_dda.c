#include "cub3d.h"

void *mlx_win;
void *mlx;
void *new_win;
void *img;
char *img_path = "/Users/hyunjung/cub3D/imgs/dogeye.XPM";
int x;
int y;

typedef struct s_new_img
{
	void	*img;
	int		*img_set;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
}	t_new_img;

t_new_img dog;

int bits_per_pixel = 0;
int size_line = 0;
int endian = 0;
int	*data;
int	*img_data;

int	stop_game(void)
{
	mlx_destroy_window(mlx, mlx_win);
	exit(1);
}

int	on_key_press(void)
{
	exit(EXIT_SUCCESS);
}

int		find_color(t_new_img *dog, int col, int row, int dis)
{
	(void)dis;
	int color;
	int height = dog->y;
	int width = dog->x;
	int result_row = (height * row) / SCREEN_HEIGHT;
	int result_col = (width * col) / SCREEN_WIDTH;
	
	color = dog->img_set[width * result_row + result_col];
	// color = dog->img_set[dog->y * ];
	return (color);
}

void	execute_mlx(double dis, int xpos)
{	
	// for (int j = 0 ; j < SCREEN_HEIGHT ; j++)
	// {
	// 	for (int i = 0; i < SCREEN_WIDTH ; i++)
	// 	{
	// 		if (j < SCREEN_HEIGHT / 2)
	// 			img_data[i + (j * size_line / 4)] = (220 << 16) + (90 << 8) + 15;
	// 		else
	// 			img_data[i + (j * size_line / 4)] = (225 * 255 * 255) + (30 * 255) + 0;
	// 	}
	// }
	printf("%d", xpos);
	dis *= 40;
	for (int i = SCREEN_HEIGHT / 2 - dis / 2 ; i < SCREEN_HEIGHT / 2 + dis / 2 ; i++)
	{
		// img_data[xpos + i * size_line / 4] = 213414;
		img_data[xpos + i * size_line / 4] = find_color(&dog, xpos, i, dis);
	}
	for (int j = 0 ; j < SCREEN_HEIGHT ; j++)
	{
		for (int i = 0; i < SCREEN_WIDTH ; i++)
			img_data[i + j * size_line / 4] = find_color(&dog, i, j, 0);
	}
	// mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);
	// mlx_hook(mlx_win, 17, 0, stop_game, 0);
	// mlx_hook(mlx_win, 3, 0, on_key_press, 0);
	// mlx_loop(mlx);
}


double	execute(t_map *map, t_vector ray_dir, int x)
{
	t_vector	delta;
	t_vector	between;
	t_vector	side;
	t_vector	step;
	int			hit;
	int			map_x;
	int			map_y;
	int			cc;

	// printf("ray x %f ray y %f\n", ray_dir.x, ray_dir.y);
	hit = 0;
	map_x = (int)(map->player.pos.x);
	map_y = (int)(map->player.pos.y);
	if (ray_dir.x == 0)
		delta.x = 0;
	else
		delta.x = fabs(sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2)) / ray_dir.x);
	if (ray_dir.y == 0)
		delta.y = 0;
	else
		delta.y = fabs(sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2)) / ray_dir.y);
	

	if (ray_dir.x > 0)
	{
		between.x = (map_x + 1) - map->player.pos.x;
		step.x = 1;
	}
	else
	{
		between.x = map_x - map->player.pos.x;
		step.x = -1;
	}
	if (ray_dir.y > 0)
	{
		between.y = (map_y + 1) - map->player.pos.y;
		step.y = 1;
	}
	else
	{
		between.y = map_y - map->player.pos.y;
		step.y = -1;
	}


	side.x = between.x * delta.x;
	side.y = between.y * delta.y;
	// printf("delx %f del y %f\n", delta.x, delta.y);
	while (hit == 0)
	{
		if (side.x <= side.y)
		{
			side.x += delta.x;
			map_x += step.x;
			cc = 0;
		}
		else
		{
			side.y += delta.y;
			map_y += step.y;
			cc = 1;
		}
		if (map->map_info[map_y][map_x] == '1')
		{
			hit = 1;
		}
	}
	if (cc == 0)
	{
		execute_mlx(side.x, x);
	}
	else if (cc == 1)
	{
		execute_mlx(side.y, x);
	}
	(void)x;
	return (0);
}

void	dda(t_map *map)
{
	//231312
	// t_new_img dog;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "insjang");
	dog.endian = 0;
	dog.size_line = 0;
	dog.bits_per_pixel = 0;
	dog.img = mlx_xpm_file_to_image(mlx, img_path, &dog.x, &dog.y);
	dog.img_set = (int *)mlx_get_data_addr(dog.img, &dog.bits_per_pixel, &dog.size_line, &dog.endian);
	new_win = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img_data = (int *)mlx_get_data_addr(new_win, &bits_per_pixel, &size_line, &endian);
	//testes
	t_vector	dir;
	t_vector	plane;
	t_vector	ray_dir;
	int			x;

	dir.x = -1;
	dir.y = 0;
	plane.x = 0;
	plane.y = 0.66;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		double camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir.x = camerax * plane.x + dir.x;
		ray_dir.y = camerax * plane.y + dir.y;
		printf("ray x %f\n",ray_dir.y);
		execute(map, ray_dir, x);
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);
	mlx_hook(mlx_win, 17, 0, stop_game, 0);
	mlx_hook(mlx_win, 3, 0, on_key_press, 0);
	mlx_loop(mlx);
}

