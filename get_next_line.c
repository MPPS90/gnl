/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2023/12/28 14:28:29 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char *buffer;
    ssize_t num_bytes;
    
    buffer = (char *)calloc((BUFFER_SIZE + 1), sizeof(char));
    if(buffer == NULL)
        return (NULL);
        
    num_bytes = read(fd, buffer, BUFFER_SIZE);

    //free(buffer);
}
