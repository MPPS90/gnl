/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:24:38 by mpena-so          #+#    #+#             */
/*   Updated: 2024/01/25 19:42:01 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(fd)
{
    static char	*buffer;
    //char		*line;
	int			bytes;

	buffer = malloc(sizeof(char));
	bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes] = '\0';
	return(buffer);
}

int main(void)
{
    int     fd;
    char    *line;
    
    fd = open("doc.txt", O_RDONLY);
    line = get_next_line(fd);
	printf("%s", line);
    return (0);
}


/*fd = 0 entrada
fd = 1 salida
fd = 2 error
fd = 3*/

/*read = (fd, buffer, BUFFER_SIZE)
bytes = 0 final del archivo
bytes = -1 error de lectura*/



