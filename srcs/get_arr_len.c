#include "includes/cub3d.h"

int	get_arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr != NULL && arr[len] != NULL)
		len++;
	return (len);
}
