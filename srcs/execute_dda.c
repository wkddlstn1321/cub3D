#include "cub3d.h"

void *mlx_win;
void *mlx;
void *new_win;
char *img_path = "./imgs/dogeye.XPM";
int x;
int y;

int	main_loop(t_map *map);

t_new_img	dog;

int bits_per_pixel = 0;
int size_line = 0;
int endian = 0;
int	*data;
int	*img_data;

// int	stop_game(t_map *map)
// {
// 	mlx_destroy_window(map->img.mlx, map->img.win);
// 	exit(0);
// }

// void	key_wasd(int key, t_map *map)
// {
// 	if (key == E_D)
// 	{
// 		map->player.pos.x += get_move_x(map->player.dir, 90) * 0.1;
// 		map->player.pos.y += get_move_y(map->player.dir, 90) * 0.1;
// 	}
// 	if (key == E_A)
// 	{
// 		map->player.pos.x -= get_move_x(map->player.dir, 90) * 0.1;
// 		map->player.pos.y -= get_move_y(map->player.dir, 90) * 0.1;
// 	}
// 	if (key == E_W)
// 	{
// 		map->player.pos.x += map->player.dir.x * 0.1;
// 		map->player.pos.y += map->player.dir.y * 0.1;
// 	}
// 	if (key == E_S)
// 	{
// 		map->player.pos.x -= map->player.dir.x * 0.1;
// 		map->player.pos.y -= map->player.dir.y * 0.1;
// 	}
// }

// int	on_key_press(int key, t_map *map)
// {
// 	if (map->player.angle > 360 * (M_PI / 180))
// 		map->player.angle = 0;
// 	else if (map->player.angle < 0)
// 		map->player.angle = 360 * (M_PI / 180);
// 	if (key == E_RIGHT)
// 		map->player.angle += 0.1;
// 	if (key == E_LEFT)
// 		map->player.angle -= 0.1;
// 	if (key == E_EXIT)
// 	{
// 		mlx_destroy_window(map->img.mlx, map->img.win);
// 		exit(0);
// 	}
// 	key_wasd(key, map);
// 	return (0);
// }

// void	ver_line(int x, int draw_start, int draw_end, t_map *map)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < SCREEN_HEIGHT)
// 	{
// 		if (i > draw_start && i < draw_end)
// 			map->img.img_set[x + i * map->img.size_line / 4] = 0x0FFF00;
// 	}
// }

// void	set_delta(t_map *map, t_dda *dda)
// {
// 	double	ray_dist;

// 	ray_dist = sqrt(pow(dda->ray_dir.x, 2) + pow(dda->ray_dir.y, 2));
// 	dda->map_x = (int)(map->player.pos.x);
// 	dda->map_y = (int)(map->player.pos.y);
// 	dda->delta.x = fabs(ray_dist / dda->ray_dir.x);
// 	dda->delta.y = fabs(ray_dist / dda->ray_dir.y);
// }

// void	check_hit(t_dda *dda, t_map *map)
// {
// 	t_vector	start_side_dis;
// 	int			hit;

// 	hit = 0;
// 	start_side_dis.x = dda->side.x;
// 	start_side_dis.y = dda->side.y;
// 	while (hit == 0)
// 	{
// 		if (dda->side.x <= dda->side.y)
// 		{
// 			dda->side.x += dda->delta.x;
// 			dda->map_x += dda->step.x;
// 			dda->check_wall = 0;
// 		}
// 		else
// 		{
// 			dda->side.y += dda->delta.y;
// 			dda->map_y += dda->step.y;
// 			dda->check_wall = 1;
// 		}
// 		if (map->map_info[dda->map_y][dda->map_x] == '1')
// 			hit = 1;
// 	}
// }

// void	set_side(t_dda *dda, t_map *map)
// {
// 	t_vector	between;

// 	if (dda->ray_dir.x >= 0)
// 	{
// 		between.x = (dda->map_x + 1) - map->player.pos.x;
// 		dda->step.x = 1;
// 	}
// 	else
// 	{
// 		between.x = map->player.pos.x - dda->map_x;
// 		dda->step.x = -1;
// 	}
// 	if (dda->ray_dir.y >= 0)
// 	{
// 		between.y = (dda->map_y + 1) - map->player.pos.y;
// 		dda->step.y = 1;
// 	}
// 	else
// 	{
// 		between.y = map->player.pos.y - dda->map_y;
// 		dda->step.y = -1;
// 	}
// 	dda->side.x = between.x * dda->delta.x;
// 	dda->side.y = between.y * dda->delta.y;
// }

// double	get_ray_dist(t_dda *dda)
// {
// 	double	distan;

// 	if (dda->check_wall == 0)
// 	{
// 		distan = dda->side.x - dda->delta.x;
// 		distan *= 1 / sqrt(pow(dda->ray_dir.x, 2) + pow(dda->ray_dir.y, 2));
// 	}
// 	else
// 	{
// 		distan = dda->side.y - dda->delta.y;
// 		distan *= 1 / sqrt(pow(dda->ray_dir.x, 2) + pow(dda->ray_dir.y, 2));
// 	}
// 	distan *= (1 << 16);
// 	distan = round(distan);
// 	distan /= (1 << 16);
// 	return (distan);
// }

// void	draw_map(t_map *map, double distan, int x)
// {
// 	int	line_h;
// 	int	draw_start;
// 	int	draw_end;

// 	line_h = (int)(SCREEN_HEIGHT / distan);
// 	draw_start = SCREEN_HEIGHT / 2 - (line_h / 2);
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	draw_end = SCREEN_HEIGHT / 2 + (line_h / 2);
// 	if (draw_end > SCREEN_HEIGHT)
// 		draw_end = SCREEN_HEIGHT;
// 	ver_line(x, draw_start, draw_end, map);
// }

// void	execute(t_map *map, t_dda *dda, int x)
// {	
// 	double	distan;

// 	set_delta(map, dda);
// 	set_side(dda, map);
// 	check_hit(dda, map);
// 	distan = get_ray_dist(dda);
// 	draw_map(map, distan, x);
// }

// int	main_loop(t_map *map)
// {
// 	t_dda		dda;
// 	double		angle;
// 	int			x;

// 	draw_bg(map);
// 	map->player.dir.x = -1 * cos(map->player.angle);
// 	map->player.dir.y = -1 * sin(map->player.angle);
// 	map->player.plane.x = 0.66 * sin(map->player.angle);
// 	map->player.plane.y = -0.66 * cos(map->player.angle);
// 	x = 0;
// 	while (x < SCREEN_WIDTH)
// 	{
// 		angle = 2 * x / (double)SCREEN_WIDTH - 1;
// 		dda.ray_dir.x = angle * map->player.plane.x + map->player.dir.x;
// 		dda.ray_dir.y = angle * map->player.plane.y + map->player.dir.y;
// 		execute(map, &dda, x);
// 		x++;
// 	}
// 	mlx_put_image_to_window(map->img.mlx, map->img.win, map->img.img, 0, 0);
// 	return (0);
// }

void	execute_dda(t_map *map)
{
	// t_new_img dog;
	// dog.endian = 0;
	// dog.size_line = 0;
	// dog.bits_per_pixel = 0;
	// dog.img = mlx_xpm_file_to_image(mlx, img_path, &dog.x, &dog.y);
	// dog.img_set = (int *)mlx_get_data_addr(dog.img, &dog.bits_per_pixel, &dog.size_line, &dog.endian);
	mlx_hook(map->img.win, 17, 0, stop_game, map);
	mlx_hook(map->img.win, 2, 0, on_key_press, map);
	mlx_loop_hook(map->img.mlx, &main_loop, map);
	mlx_loop(map->img.mlx);
}
