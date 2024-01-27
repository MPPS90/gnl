/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/01/27 14:17:46 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    ssize_t num_bytes;
    char    *read_line;
    
    
    buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if(buffer == NULL)
        return (NULL);
    
    num_bytes = 1;
    while(num_bytes > 0)
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        read_line = ft_strjoin(read_line, buffer);
    }
    
    
    printf("NUM %zd\n", num_bytes);
    printf("BUF %s\n", buffer);
    printf("read_line:%s", read_line);
    printf("TAM BUFFER %lu\n", strlen(buffer));
    printf("TAM BUFFER_SIZE %d\n", BUFFER_SIZE);
    return(buffer);
    //free(buffer);
}
int main(void)
{
    int fd;
    char    *line;
    
    fd = open("doc.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);    
    return 0;
}


/*
char    *get_next_line(fd)
{
    static char	*buffer;
    //char		*line;
	int			bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1), sizeof(char));
    num_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[num_bytes] = '\0';
	return(buffer);
}
*/