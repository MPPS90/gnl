/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 17:50:33 by mpena-so          #+#    #+#             */
/*   Updated: 2024/04/05 20:20:18 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line_bonus.h"
//#include "get_next_line.h"

/* 
//main bueno....
//igual de bueno como ignacio de partido (ignacio divido)
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/Users/mpena-so/Desktop/lord_rings.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
    printf("\n\nBUFFER_SIZE = %d\n", BUFFER_SIZE);
	system("leaks -q a.out");
	return (0);
} */