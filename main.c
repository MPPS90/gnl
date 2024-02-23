#include "get_next_line.h"

void	detect_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	int		fd;
	char	*line;

	atexit(detect_leaks);
	fd = open("the_lord_of_the_rings.txt", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
