/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/03 12:23:17 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"







char    *find(int fd)
{
    static char *read_line;
    char    *buffer;
    ssize_t num_bytes;
    char    *line;
    
    //para la primera lectura 
    //line = no tengo que reservarle memoria porque apunta a lo que ya tiene apuntado read_line (es decir quee esa memoria ya se ha reservado)
    read_line = malloc(1);
    if(read_line == NULL)
        return (NULL);
    read_line[0] = '\0';
    //Quitar despues este printf:
    printf("PRIMERO: %s\n", read_line);
    num_bytes = 1;
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));//si vuelvo a ft_calloc cambiar el * por la ,
    if(buffer == NULL)
        return (NULL);
    while(num_bytes > 0)
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[num_bytes] = '\0';
        line = read_line;
        read_line = ft_strjoin(read_line, buffer);
        free(line);
        line = NULL;
        printf("->%s<-\n", read_line);
        if(ft_strrchr(read_line, '\n'))
        {
            break;
        }
    }  
    free(buffer);
    buffer = NULL;
    

    printf("NUM BYTES: %zd\n", num_bytes);
    printf("BUF:%s\n", buffer);
    printf("read_line:%s\n", read_line);
    printf("TAM BUFFER_SIZE %d\n", BUFFER_SIZE);
    return(read_line);   
}
/*char    *get_next_line(int fd)
{
    
}*/
 
    //while (read_line == '\n')
    
  int main(void)
{
    int fd;
    char    *line;
    
    fd = open("doc.txt", O_RDONLY);
    line = find(fd); //ojo que aquí en el main debo llamar es a get_next_line hice cambio a find mientras organizo el código
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