/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/01 16:53:11 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    ssize_t num_bytes;
    static char *read_line;
    char    *line;
    
    buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    if(buffer == NULL)
        return (NULL);
    //para la primera lectura 
    //line = (char *)ft_calloc((strlen(buffer), sizeof(char)));
    num_bytes = read(fd, buffer, BUFFER_SIZE);
    while(num_bytes > 0)
    {
        if(read_line == NULL)
        {
            read_line = malloc(1);
            if(read_line == NULL)
                return (NULL);
            read_line[0] = '\0';
        }
        line = read_line;
        read_line = ft_strjoin(read_line, buffer);
        num_bytes = read(fd, buffer, BUFFER_SIZE);
    }   

    printf("NUM BYTES: %zd\n", num_bytes);
    printf("BUF:%s\n", buffer);
    printf("read_line:%s\n", read_line);
    printf("TAM BUFFER %lu\n", strlen(buffer));
    printf("TAM BUFFER_SIZE %d\n", BUFFER_SIZE);
    return(buffer);
    //free(buffer);
    
}
    //line = 
    //while (read_line == '\n')
    
  int main(void)
{
    int fd;
    char    *line;
    
    fd = open("doc.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("Line main: %s\n", line);    
    return 0;
}