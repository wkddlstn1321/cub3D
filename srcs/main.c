#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	char	*file_name;
	char	**contents;
	t_map	map;
	void	*mlx;

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
	mlx = mlx_init();
	save_sprite_data(&map, mlx);
	execute_dda(&map);
	return (0);
}
