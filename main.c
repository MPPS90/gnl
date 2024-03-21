//#include "get_next_line_bonus.h"
#include "get_next_line.h"

// void	detect_leaks(void)
// {
// 	system("leaks a.out");
// }

int	main(void)
{
	int		fd;
	char	*line;

	//atexit(detect_leaks);
	fd = open("gnl/lord_rings.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("ACEDEEEEE\n");
	while (line)
	{
		printf("%s", line);
		//fflush(NULL); //esto es por el uso del printf porque el printf lee hasta que se encuentra el salto de línea el texto que se le pasa, no tiene salto de línea al final por lo tanto no detecta ese final e imprime lo de los leaks entre medias
		free(line);
		line = get_next_line(fd);
	}
	free(line);//este free es porque en caso de que no entre en el while, line ya tiene algo y debe liberarse.
	printf("\n\n");
	close(fd);
	return (0);
}

//main sin bonus con null al final
/*int	main(void)
{
	int		fd;
	char	*line;

	atexit(detect_leaks);
	fd = open("lord_rings.txt", O_RDONLY);
	line= "";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/

 //main sin bonus sin null al final
/*  int	main(void)
{
	int		fd;
	char	*line;

	atexit(detect_leaks);
	fd = open("lord_rings.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}  */



//main con bonus 
/*
int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	atexit(detect_leaks);
	fd1 = open("the_lord_of_the_rings.txt", O_RDONLY);
	fd2 = open("txt.txt", O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd1);
		printf("fd1: %s", line);
		free(line);
		printf("\n-------------------------------\n");
		line = get_next_line(fd2);
		printf("fd2: %s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	return (0);
}*/