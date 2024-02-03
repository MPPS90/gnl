/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/03 13:50:39 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *find(int fd)
{
    static char *read_line;
    char    *buffer;
    ssize_t num_bytes;
    char    *aux;//antes era line
    
    //para la primera lectura 
    //aux = no tengo que reservarle memoria porque apunta a lo que ya tiene apuntado read_line (es decir quee esa memoria ya se ha reservado)
    read_line = malloc(1);
    if(read_line == NULL)
        return (NULL);
    read_line[0] = '\0';
    //Quitar despues este printf:
    printf("PRIMERO: %s\n", read_line);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));//si vuelvo a ft_calloc cambiar el * por la ,
    if(buffer == NULL)
        return (NULL);
    num_bytes = 1;
    while(num_bytes > 0) //aquí podría poner que read_line[i] != '\n'??
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[num_bytes] = '\0';
        printf("comprobación buffer: >%s<\n", buffer);
        aux = read_line;
        read_line = ft_strjoin(read_line, buffer);
        free(aux);
        aux = NULL;
        printf("comprobación read_line:->%s<-\n", read_line);
        if(ft_strchr(read_line, '\n'))
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

/*char    *separate(char *read_line)
{
    
}*/


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