#include "includes/cub3d.h"

// int	check_border(char **map, int width, int height)
// {
// 	int		y;
// 	char	*line;

// 	y = 0;
// 	while (map[y] != NULL)
// 	{
// 		line = map[y];
// 		if (y == 0 || y == (height - 1))
// 		{
// 			while (*line != '\0')
// 			{
// 				if (*line != ' ' && *line != '1')
// 					return (1);
// 				line++;
// 			}
// 		}
// 		else
// 			if ((line[0] != '1' && line[0] != ' ')
// 				|| (line[width - 1] != '1' && line[width - 1] != ' '))
// 				return (1);
// 		line++;
// 		map[y];
// 	}
// 	return (0);
// }

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
	  2. open으로 뚜껑따기 (O)
	  3. gnl로 구조체에 담기
	  4. 들어온 맵 체크하기
	  (
		  1. 테두리 부분이 공백 or 1인지 확인
		  2. 0 or 플레이어 위치에서 동,서,남,북이 공백이 아니길 바라...
	  )
	*/

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File open fail");
	while (1)
	{
		line = get_next_line(fd);

	}
	/*TEST
	int	dirx[4] = {1, -1, 0, 0};
	int	diry[4] = {0, 0, 1, -1};
	for (int i = 0 ; i < 4 ; i++)
	{
		int new_x = x + dirx;
		int	new_y = y + diry;
		if (map[new_x][new_y] == ' ')
			error;
	}
	int path_check[4] = {0};
	int	cnt = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strnstr(line, "NO", ft_strlen(line) != NULL))
		{
			
		}

	}
	TEST*/

	return (0);
}
