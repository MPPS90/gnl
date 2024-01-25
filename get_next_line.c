/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/01/25 19:45:23 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char    *get_next_line(int fd)
{
    char *buffer;
    ssize_t num_bytes;
    
    buffer = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
    if(buffer == NULL)
        return (NULL);
    num_bytes = read(fd, buffer, BUFFER_SIZE);
    printf("%zd\n", num_bytes);
    printf("%s\n", buffer);
    printf("%lu\n", strlen(buffer));
    return(buffer);
    //free(buffer);
}
/*int main(void)
{
    int fd = 3;
    get_next_line(fd);
    return 0;
}*/