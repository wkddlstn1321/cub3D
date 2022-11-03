#include "includes/cub3d.h"

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
	save_sprite_data(&map);
	printf("Success\n");
	execute_dda(&map);
	// execute_mlx();
	return (0);
}
