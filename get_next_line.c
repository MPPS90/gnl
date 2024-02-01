/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/01 19:15:50 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *read_line;
    char    *buffer;
    ssize_t num_bytes;
    char    *line;
    
    //para la primera lectura 
    //line = (char *)ft_calloc((strlen(buffer), sizeof(char)));
    read_line = malloc(1);
    num_bytes = 1;
    while(num_bytes > 0)
    {
        buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
        if(buffer == NULL)
            return (NULL);
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        line = read_line;
        read_line = ft_strjoin(read_line, buffer);
        free(buffer);
        buffer = NULL;
        free(line);
        line = NULL;
        if(ft_strrchr(read_line, '\n'))
        {
            break;
        }
    }   
        // line = read_line;

    printf("NUM BYTES: %zd\n", num_bytes);
    printf("BUF:%s\n", buffer);
    printf("read_line:%s\n", read_line);
    //printf("TAM BUFFER %lu\n", strlen(buffer));
    printf("TAM BUFFER_SIZE %d\n", BUFFER_SIZE);
    return(buffer);
    //free(buffer);
    
}
 
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
        // if(read_line == NULL)
        // {
        //     read_line = malloc(1);
        //     if(read_line == NULL)
        //         return (NULL);
        //     read_line[0] = '\0';
        // }