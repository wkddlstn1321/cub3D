#include "includes/cub3d.h"

char	**init_contents(char *file_name)
{
	int		fd;
	char	*line;
	char	**contents;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(ft_error("Failed To Open File\n"));
	contents = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		contents = join_contents(contents, line);
	}
	if (!contents)
		exit(ft_error("empty file"));
	return (contents);
}
