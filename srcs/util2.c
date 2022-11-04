#include "includes/cub3d.h"

double	get_move_x(t_vector dir, double degree)
{
	double	rad;

	rad = ft_dtor(degree);
	return (dir.x * cos(rad) - dir.y * sin(rad));
}

double	get_move_y(t_vector dir, double degree)
{
	double	rad;

	rad = ft_dtor(degree);
	return (dir.x * sin(rad) + dir.y * cos(rad));
}
