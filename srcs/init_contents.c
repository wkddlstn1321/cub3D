#include "includes/cub3d.h"

static	int	count_contents(char	**strs)
{
	int	len;

	len = 0;
	if (strs == NULL)
		return (len);
	while (strs[len])
		len++;
	return (len);
}

static	void	add_line_back(char	**new_contents, char **contents, char *str)
{
	int	idx;

	idx = 0;
	while (contents != NULL && contents[idx] != NULL)
	{
		new_contents[idx] = contents[idx];
		idx++;
	}
	new_contents[idx] = str;
	new_contents[++idx] = NULL;
}

static	char	**join_contents(char **contents, char *line)
{
	char	**new_contents;

	new_contents = malloc(sizeof(char *) * (count_contents(contents) + 2));
	if (new_contents == NULL)
		exit(ft_error("malloc error"));
	add_line_back(new_contents, contents, line);
	free(contents);
	return (new_contents);
}

char	**init_contents(char *file_name)
{
	int		fd;
	char	*line;
	char	**contents;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit(ft_error("Failed To Open File"));
	contents = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_converter(line);
		contents = join_contents(contents, line);
	}
	close(fd);
	if (!contents)
		exit(ft_error("empty file"));
	return (contents);
}
