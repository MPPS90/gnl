/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/09 23:52:07 by mpena-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start > (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sub_s = (char *)malloc(sizeof(char) * (len + 1));
	if (sub_s == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i++] = s[start++];
	}
	sub_s[i] = '\0';
	return (sub_s);
}

char    *read_till_character(int fd)
{
    static char *read_line;
    char    *buffer;
    ssize_t num_bytes;
    char    *aux;//aux = no tengo que reservarle memoria porque apunta a lo que ya tiene apuntado read_line (es decir quee esa memoria ya se ha reservado)
    
    read_line = malloc(sizeof(char));
    if(read_line == NULL)
        return (NULL);
    read_line[0] = '\0';
    printf("PRIMERO: %s\n", read_line);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(buffer == NULL)
        return (NULL);
    num_bytes = 1;
    while(num_bytes > 0 && !ft_strchr(read_line, '\n'))
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[num_bytes] = '\0';
        printf("comprobación buffer: >%s<\n", buffer);
        aux = read_line;
        read_line = ft_strjoin(read_line, buffer);
        free(aux);
        aux = NULL;
        printf("comprobación read_line:->%s<-\n", read_line);
    }  
    free(buffer);
    buffer = NULL;
    printf("return: %s\n", read_line); 
    printf("buffer: %s\n", buffer);
    printf("aux: %s\n", aux);
    return(read_line); //read_line no debo liberarlo, no??
}


char    *separate(int fd, char *read_line)
{
    //char    *keep_line;
    //int start;
    //int end;
    //int i;*/

    read_line = read_till_character(fd);
    printf("%s", read_line);
    
    //start = ft_strchr(read_line, '\n');
    
    /*
    i=0;
    while(read_line)
    {
        while(read_line[i] !='\n')
        {
            if(read_line[i] =='\n' || read_line[i] !='\0')
                i++;
            start = i;
            if (read_line[i] != '\n' || read_line[i] != '\0')
                i++;
            end = i;
        }
        keep_line = ft_substr(read_line, start, end-start);
        printf("%s\n", keep_line);
    }
    */
    
    return(read_line);
    
    /*i=0;
    while(read_line[i])
    {
        while 
    }*/
    //ft_strchr(read_line, '\n'); //me da la direccion de memoria donde encuentra el caracter
    //keep_line = ft_substr(find,);
}


/*char    *get_next_line(int fd)
{
    char    *final_line;
    char    *final;
    
    final_line = read_till_character(fd);
    while(final_line)
    {
        final=ft_strchr(final_line);
        final--;
        printf("%s\n", final);
    }
    return final;
}*/


//while (read_line == '\n')
    
  int main(void)
{
    int fd;
    char    *line;
    char    *line2;
    
    fd = open("doc.txt", O_RDONLY);
    //char *get_next_line(int fd);
    line = read_till_character(fd); //ojo que aquí en el main debo llamar es a get_next_line hice cambio mientras organizo el código
    printf("Line main: %s\n", line); 
    line2 = separate(fd, line);
    printf("Line main: %s\n", line2);
    return 0;
}

//el main debería llevar un while porque debe leer el archivo constantemente


        // if(read_line == NULL)
        // {
        //     read_line = malloc(1);
        //     if(read_line == NULL)
        //         return (NULL);
        //     read_line[0] = '\0';
        // }