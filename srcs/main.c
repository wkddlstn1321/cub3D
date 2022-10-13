#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	char	*file_name;
	int		fd;
	char	*line;
	t_map	map;

	if (ac != 2)
		return (ft_error("Wrong arguments  [./cub3D] [*.cub]"));
	file_name = av[1];
	check_extension(file_name);
	
	/*1. 확장자명 체크 (O)
	  2. open으로 뚜껑따기
	  3. gnl로 구조체에 담기
	  4. 들어온 맵 체크하기
	*/

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File open fail");
	
	while (1)
	{
		line = get_next_line(fd);


	}
	return (0);
}
