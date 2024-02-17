/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_copia.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpena-so <mpena-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:04:56 by mpena-so          #+#    #+#             */
/*   Updated: 2024/02/17 10:38:56 by mpena-so         ###   ########.fr       */
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

char    *read_till_character(int fd, char *read_line)
{
    char    *buffer;
    ssize_t num_bytes;
    char    *aux;
        
    if(read_line == NULL)
    {
        read_line = malloc(sizeof(char));
        if(read_line == NULL)
            return (NULL);
        read_line[0] = '\0';
    }       
    //printf("\n\nLa estatica es  en readddd   %s\n\n", read_line);
    //printf(">>>>ptr: %p\n", &read_line);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));//en el malloc tiene sentido hacer el casteo inicial que tengo??
    if(buffer == NULL)
        return (NULL);
    num_bytes = 1;
    while(num_bytes > 0 && !ft_strchr(read_line, '\n'))
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        if (num_bytes < 0)
        {
            free(buffer);
            free(read_line); // <------------------
            return (NULL);
        }
        if(num_bytes == 0) // <------------------------
        {
            free(buffer);
            return (read_line);
        }
        // if(num_bytes == 0 && read_line == NULL)
        // {
        //     return (NULL);
        // }
        buffer[num_bytes] = '\0';
        aux = read_line;
        read_line = ft_strjoin(read_line, buffer);
        free(aux);
        aux = NULL; 
    }  
    free(buffer);
    buffer = NULL;
    //printf("return: %s\n", read_line); 
    //printf("buffer: %s\n", buffer);
    //printf("aux: %s\n", aux);
    return(read_line); //read_line no debo liberarlo, no??
 }

//**SEPARATE**
//Aquí debería conectar de alguna manera lo que devuelve return con lo que sigue leyendo read
//substr hace un malloc hay que liberarlo
//en lugar de esta función podría usar el split??? Devuelve todas las cadenas separadas según el caracter delimitador.
//PARA PREGUNTAR:
//En separate, debería pasar algo si c (o sea '\n') es un \0, entiendo que no porque quiere decir que no está el caracter entonces debería pasarme toda la cadena, n0?
char    *separate(char *read_line)
{
    char    *keep_line;
    int start;
    int end;
    int i;
    //start = ft_strchr(read_line, '\n'); strchr devuelve un puntero (variable que almacena una dirección de memoria)a la primera ocurrencia del caracter especificado
    i=0;
    if (!read_line[0]) // POR VER
        return (NULL);
    while(read_line[i] && read_line[i] != '\n') // <------------------------------------------------------------------sgfault
        i++;
    //RECORDAR ESTO, QUE SIEMPRE LO PONGO SIN [i] Y HAGO UN BUCLE INFINITO
    while(read_line[i] && read_line[i] == '\n')// <---------------------------------------------------------sgfault
        i++;
    start = i;
    while( read_line[i] != '\n')// <-----------------------------------------------------------------sgfault
    {
        i++;
        if (read_line[i] == '\0' && read_line[i] == '\n')// <--------------------------------------------sgfault
            end = i;
    }
    keep_line = ft_substr(read_line, start, (start-end));//esto debería fuera o dentro del bucle, da iguel, no?
    //printf("%s\n", keep_line);
    return(keep_line);
}

char    *get_next_line(int fd)
{
    static char *read_line;
    char    *final_line;
    int start;
    int end;
    int i;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(read_line);
        return (NULL);
    }
    //printf("La estatica es %s\n", read_line);
    read_line = read_till_character(fd, read_line);
    //printf("Devuelve read_till_line en main: %s\n", read_line);
    start = 0;
    i = 0;

    if (!read_line[0] || !read_line)
        return (NULL);
    while(read_line[i] != '\n' && read_line[i] != '\0')
        i++;
    while (read_line[i] && read_line[i] == '\n')  // <-------------------------sgfault
        i++;
    end = i;
    final_line = ft_substr(read_line, start, (end-start));//TO SEE FOR UPDATES
    read_line = separate(read_line);
    //printf("Lo de despues: %s\n", read_line);

    //printf("%c\n", read_line[0]);
    //printf("%c\n", (i-(read_line[0])));
    //printf("%s\n", final_line);
    return(final_line);
}

//ARCHIVO MAIN 
