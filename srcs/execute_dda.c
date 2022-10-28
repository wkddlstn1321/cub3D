#include "cub3d.h"

void *mlx_win;
void *mlx;
void *new_win;
void *img;
char *img_path = "/Users/insjang/cub3D/imgs/dogeye.XPM";
int x;
int y;
double rotSpeed;

int	main_loop(t_map *map);

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

int	on_key_press(int key, t_map *map)
{
	if (rotSpeed > 360)
		rotSpeed = 0;
	if (key == E_D)
		rotSpeed += 0.1;
	if (key == E_A)
		rotSpeed -= 0.1;
	if (key == E_W)
		map->player.pos.x += 0.1;
	if (key == E_S)
		map->player.pos.x -= 0.1;
	mlx_clear_window(mlx, mlx_win);
	main_loop(map);
	return(0);
}

int		find_color(t_new_img *dog, int w, int row, int h)
{
	int color;
	int height = dog->y;
	int width = dog->x;
	int result_row = (height * row) / h;
	// int result_col = (width * w) / SCREEN_WIDTH;
	(void)w;
	color = dog->img_set[width * result_row + w];
	// color = dog->img_set[dog->y * ];
	return (color);
}

void	execute_mlx(double dis, int xpos, double hit_po)
{
	(void)dis;
	double	w;
	while (hit_po > 1)
	{
		hit_po -= 1;
	}
	(void)xpos;
	w = hit_po * 64;
	printf("w %f\n", w);
	dis *= (1/sqrt(12*12+16*16))*SCREEN_HEIGHT;
	// (void)xpos;
	int	text_h = SCREEN_HEIGHT - dis * 2;
	if (text_h < 0)
		text_h = 0;
	int h = 0;
	for (int i = 0 ; i < SCREEN_HEIGHT ; i++)
	{
		if (i < SCREEN_HEIGHT - dis && i > dis)
		{	
			// img_data[xpos + i * size_line / 4] = find_color(&dog, w, h, text_h + 1);
			h++;
		}
			// img_data[xpos + i * size_line / 4] = 0xaFFF00FF;
	}
	// for (int j = 0 ; j < SCREEN_HEIGHT ; j++)
	// {
	// 	for (int i = 0; i < SCREEN_WIDTH ; i++)
	// 		img_data[i + j * size_line / 4] = find_color(&dog, i, j, 0);
	// }
	// mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);
	// mlx_hook(mlx_win, 17, 0, stop_game, 0);
	// mlx_hook(mlx_win, 3, 0, on_key_press, 0);
	// mlx_loop(mlx);
}

//made by insjang test func
void	verLine(int x, int drawStart, int drawEnd)
{
	// printf("%d %d\n", drawStart, drawEnd);
	int a = 0;
	for (int i = 0 ; i < SCREEN_HEIGHT ; i++)
	{
		if (i >= drawStart && i <= drawEnd)
		{
			img_data[x + i * size_line / 4] = 0x0FFF00;
			// img_data[x + i * size_line / 4] = find_color(&dog, x, a, drawEnd - drawStart);
			a++;
		}
		// if (i < SCREEN_HEIGHT - dis && i > dis)
		// {	
			// img_data[xpos + i * size_line / 4] = find_color(&dog, w, h, text_h + 1);
		// }
	}
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
	// delta.x = 1;
	// delta.y = 1;
	delta.x = fabs(sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2)) / ray_dir.x);
	delta.y = fabs(sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2)) / ray_dir.y);
	if (ray_dir.y == INFINITY)
		ray_dir.y = 0;
	if (ray_dir.x == INFINITY)
		ray_dir.x = 0;
	if (ray_dir.x > 0)
	{
		between.x = (map_x + 1) - map->player.pos.x;
		step.x = 1;
	}
	else
	{
		between.x = map->player.pos.x - map_x;
		step.x = -1;
	}
	if (ray_dir.y > 0)
	{
		between.y = (map_y + 1) - map->player.pos.y;
		step.y = 1;
	}
	else
	{
		between.y = map->player.pos.y - map_y;
		step.y = -1;
	}
	side.x = between.x * delta.x;
	side.y = between.y * delta.y;

	t_vector	start_side_dis;
	start_side_dis.x = side.x;
	start_side_dis.y = side.y;
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
	//test made in insjang
	// double	perp_dist;
	// if (cc == 0)
	// {
	// 	perp_dist = (map_x - map->player.pos.x + (1 - step.x) / 2) / ray_dir.x;
	// 	if (perp_dist < 0)
	// 	{
	// 		printf("%d - %.10f + (1 - %.10f)/2 / %.10f = ",map_x, map->player.pos.x, step.x, ray_dir.x);
	// 	}
	// }
	// else
	// {
	// 	perp_dist = (map_y - map->player.pos.y + (1 - step.y) / 2) / ray_dir.y;
	// 	if (perp_dist < 0)
	// 	{
	// 		printf("%d - %.10f + (1 - %.10f)/2 / %.10f = ", map_y, map->player.pos.y, step.y, ray_dir.y);
	// 	}
	// }
	// printf("%f\n", perp_dist);
	// int	line_h = (int)(SCREEN_HEIGHT / perp_dist);
	// int drawStart = -line_h / 2 + SCREEN_HEIGHT / 2;
	// if (drawStart < 0)
	// 	drawStart = 0;
	// int drawEnd = line_h / 2 + SCREEN_HEIGHT / 2;
	// if (drawEnd >= SCREEN_HEIGHT)
	// 	drawEnd = SCREEN_HEIGHT - 1;
	// verLine(x, drawStart, drawEnd);
	//test made in insjang


	double distan;
	// double hit_po;
	if (cc == 0)
	{
		distan = side.x - delta.x;
		distan *= 1 / sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2));
		// printf("%f\n", distan);
	}
	else
	{
		distan = side.y - delta.y;
		distan *= 1 / sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2));
		// printf("Y : %f * %f / %f = ", distan, ray_dir.y, sqrt(ray_dir.x*ray_dir.x+ray_dir.y*ray_dir.y));
		// printf("%f\n", distan);
		// printf("Y : (%d - %f + (1 - %f)/2) / %f = %f\n", map_y, map->player.pos.y, step.y, ray_dir.y, distan);
	}
	if (ray_dir.y == 0)
	{
		printf("%f %d %d\n", map->player.pos.x, map_y, map_x);
		if (step.x == -1)
			distan = map->player.pos.x - map_x;
	}
	// printf("%f\n", distan);
		// distan = 10;
	// }	// hit_po = map->player.pos.y;
	// if (distan == 1)
	// 	printf("it is 1\n");
	int	line_h = (int)(SCREEN_HEIGHT / distan);
	int drawStart = -line_h / 2 + SCREEN_HEIGHT / 2;
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = line_h / 2 + SCREEN_HEIGHT / 2;
	if (drawEnd > SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT;
	verLine(x, drawStart, drawEnd);
			// hit_po = side.x * between.y / start_side_dis.y + map->player.pos.y;
		// printf("y -> %f * %f / %f + %f === %f\n",side.x, between.y, start_side_dis.y, map->player.pos.y,hit_po);
		// printf("map x : %d map : y %d distanx %f\n", y, map_y, side.x);
// 	execute_mlx(side.x, x, hit_po);
	// }
	// else if (cc == 1)
	// {
	// 	side.y -= delta.y;
	// 	if (start_side_dis.y == 0)
	// 		hit_po = map->player.pos.x;
	// 	else
	// 		hit_po = side.y * between.x / start_side_dis.x + map->player.pos.x;
	// 	printf("x -> %f * %f / %f + %f === %f\n",side.x, between.y, start_side_dis.y, map->player.pos.y,hit_po);
	// 	// printf("map x : %d map : y %d distany %f\n", map_x, map_y, side.y);
	// 	execute_mlx(side.y, x, hit_po);
	// }
	(void)x;
	return (0);
}

int	main_loop(t_map *map)
{
	mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);
	for (int j = 0 ; j < SCREEN_HEIGHT ; j++)
	{
		for (int i = 0; i < SCREEN_WIDTH ; i++)
		{
			if (j < SCREEN_HEIGHT / 2)
				img_data[i + (j * size_line / 4)] = (220 << 16) + (90 << 8) + 15;
			else
				img_data[i + (j * size_line / 4)] = (225 * 255 * 255) + (30 * 255) + 0;
		}
	}
	//testes
	t_vector	dir;
	t_vector	plane;
	t_vector	ray_dir;
	int			x;

	dir.x = -1;
	dir.y = 0;
	plane.x = 0;
	plane.y = 0.66;

	//rotate
	dir.x = dir.x * cos(rotSpeed) - dir.y * sin(rotSpeed);
	dir.y = -1 * sin(rotSpeed) + dir.y * cos(rotSpeed);
	plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
	plane.y = 0 * sin(rotSpeed) + plane.y * cos(rotSpeed);
	//rotate
	
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		double camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir.x = camerax * plane.x + dir.x;
		ray_dir.y = camerax * plane.y + dir.y;
		// printf("ray x %f ray y %f\n",ray_dir.x, ray_dir.y);
		execute(map, ray_dir, x);
		x++;
	}
	
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
	// //testes
	// t_vector	dir;
	// t_vector	plane;
	// t_vector	ray_dir;
	// int			x;

	// dir.x = -1;
	// dir.y = 0;
	// plane.x = 0;
	// plane.y = 0.66;

	// //rotate
	// double rotSpeed = 90;
	// dir.x = dir.x * cos(rotSpeed) - dir.y * sin(rotSpeed);
	// dir.y = -1 * sin(rotSpeed) + dir.y * cos(rotSpeed);
	// plane.x = plane.x * cos(rotSpeed) - plane.y * sin(rotSpeed);
	// plane.y = 0 * sin(rotSpeed) + plane.y * cos(rotSpeed);
	// //rotate
	
	// x = 0;
	// while (x < SCREEN_WIDTH)
	// {
	// 	double camerax = 2 * x / (double)SCREEN_WIDTH - 1;
	// 	ray_dir.x = camerax * plane.x + dir.x;
	// 	ray_dir.y = camerax * plane.y + dir.y;
	// 	// printf("ray x %f ray y %f\n",ray_dir.x, ray_dir.y);
	// 	execute(map, ray_dir, x);
	// 	x++;
	// }
	main_loop(map);
	mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);

	// mlx_loop_hook(mlx, &main_loop, map);
	mlx_hook(mlx_win, 17, 0, stop_game, 0);
	mlx_hook(mlx_win, 2, 0, on_key_press, map);
	mlx_loop(mlx);
}

