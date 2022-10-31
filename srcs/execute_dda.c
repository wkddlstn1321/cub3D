#include "cub3d.h"

void *mlx_win;
void *mlx;
void *new_win;
char *img_path = "./imgs/dogeye.XPM";
int x;
int y;

int	main_loop(t_map *map);


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
	if (map->player.angle > 360 * (M_PI / 180))
		map->player.angle = 0;
	else if (map->player.angle < 0)
		map->player.angle = 360 * (M_PI / 180);
	if (key == E_D)
	{
		map->player.pos.x += get_move_x(map->player.dir, 90) * 0.1;
		map->player.pos.y += get_move_y(map->player.dir, 90) * 0.1;
	}
	if (key == E_A)
	{
		map->player.pos.x -= get_move_x(map->player.dir, 90) * 0.1;
		map->player.pos.y -= get_move_y(map->player.dir, 90) * 0.1;
	}
	if (key == E_W)
	{
		map->player.pos.x += map->player.dir.x * 0.1;
		map->player.pos.y += map->player.dir.y * 0.1;
	}
	if (key == E_S)
	{
		map->player.pos.x -= map->player.dir.x * 0.1;
		map->player.pos.y -= map->player.dir.y * 0.1;
	}
	if (key == E_RIGHT)
		map->player.angle += 0.1;
	if (key == E_LEFT)
		map->player.angle -= 0.1;
	if (key == E_EXIT)
	{
		mlx_destroy_window(mlx, mlx_win);
		exit(0);
	}
	mlx_clear_window(mlx, mlx_win);
	main_loop(map);
	return (0);
}

void	verLine(int x, int drawStart, int drawEnd)
{
	int a = 0;
	for (int i = 0 ; i < SCREEN_HEIGHT ; i++)
	{
		if (i > drawStart && i < drawEnd)
		{
			// img_data[x + i * size_line / 4] = find_color(&dog, w, line_h, a);
			img_data[x + i * size_line / 4] = 0x0FFF00;
			a++;
		}
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

	hit = 0;
	map_x = (int)(map->player.pos.x);
	map_y = (int)(map->player.pos.y);
	delta.x = fabs(sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2)) / ray_dir.x);
	delta.y = fabs(sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2)) / ray_dir.y);
	if (ray_dir.x >= 0)
	{
		between.x = (map_x + 1) - map->player.pos.x;
		step.x = 1;
	}
	else
	{
		between.x = map->player.pos.x - map_x;
		step.x = -1;
	}
	if (ray_dir.y >= 0)
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

	double distan;
	double new_dis;
	if (cc == 0)
	{
		distan = side.x - delta.x;
		distan *= 1 / sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2));
		new_dis = (map_x - map->player.pos.x + (1 - step.x) / 2) / ray_dir.x;
	}
	else
	{
		distan = side.y - delta.y;
		distan *= 1 / sqrt(pow(ray_dir.x, 2) + pow(ray_dir.y, 2));
		new_dis = (map_y - map->player.pos.y + (1 - step.y) / 2) / ray_dir.y;
	}
	distan *= (1 << 16);
	distan = round(distan);
	distan /= (1 << 16);
	int	line_h = (int)(SCREEN_HEIGHT / distan);
	int drawStart = SCREEN_HEIGHT / 2 - (line_h / 2);
	if (drawStart < 0)
		drawStart = 0;
	int drawEnd = SCREEN_HEIGHT / 2 + (line_h / 2);
	if (drawEnd > SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT;
	verLine(x, drawStart, drawEnd);
	(void)x;
	return (0);
}

int	main_loop(t_map *map)
{
	t_vector	ray_dir;
	int			x;

	map->player.dir.x = -1 * cos(map->player.angle);
	map->player.dir.y = -1 * sin(map->player.angle);
	map->player.plane.x = 0.66 * sin(map->player.angle);
	map->player.plane.y = -0.66 * cos(map->player.angle);
	
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		double camerax = 2 * x / (double)SCREEN_WIDTH - 1;
		ray_dir.x = camerax * map->player.plane.x + map->player.dir.x;
		ray_dir.y = camerax * map->player.plane.y + map->player.dir.y;
		execute(map, ray_dir, x);
		x++;
	}
	mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);
	return (0);
}

void	dda(t_map *map)
{
	// t_new_img dog;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	dog.endian = 0;
	dog.size_line = 0;
	dog.bits_per_pixel = 0;
	dog.img = mlx_xpm_file_to_image(mlx, img_path, &dog.x, &dog.y);
	dog.img_set = (int *)mlx_get_data_addr(dog.img, &dog.bits_per_pixel, &dog.size_line, &dog.endian);
	new_win = mlx_new_image(mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img_data = (int *)mlx_get_data_addr(new_win, &bits_per_pixel, &size_line, &endian);
	main_loop(map);
	mlx_loop_hook(mlx, &main_loop, map);
	mlx_hook(mlx_win, 17, 0, stop_game, 0);
	mlx_hook(mlx_win, 2, 0, on_key_press, map);
	mlx_put_image_to_window(mlx, mlx_win, new_win, 0, 0);
	mlx_loop(mlx);
}
