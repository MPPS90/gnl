/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/01/31 17:35:26 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
	{
		return (j);
	}
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}*/

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
    num_bytes = read(fd, buffer, BUFFER_SIZE);
    while(num_bytes > 0)
    {
        if(read_line == NULL)
        {
            read_line = "";    
        }
        read_line = ft_strjoin(read_line, buffer);
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        
                
    }
    //line = 
    
    printf("NUM BYTES: %zd\n", num_bytes);
    printf("BUF:%s\n", buffer);
    printf("read_line:%s\n", read_line);
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
    printf("Line main: %s\n", line);    
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