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
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(buffer == NULL)
        return (NULL);
    num_bytes = 1;
    while(num_bytes > 0 && !ft_strchr(read_line, '\n'))
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        if (num_bytes < 0)
        {
            free(buffer);
            return (NULL);
        }
        if(num_bytes == 0 && read_line == NULL)
        {
            return (NULL);
        }
        buffer[num_bytes] = '\0';
        aux = read_line;
        read_line = ft_strjoin(read_line, buffer);
        free(aux);
        aux = NULL; 
    }  
    free(buffer);
    buffer = NULL;
    return(read_line); 
 }
char    *separate(char *read_line)
{
    char    *keep_line;
    int start;
    int end;
    int i;
    i=0;
    if (!read_line[0])
        return (NULL);
    while(read_line[i] != '\n' && read_line[i] !='\0')
        i++;
    while(read_line[i] == '\n' && read_line[i] !='\0')
        i++;
    start = i;
    while(read_line[i] != '\n' && read_line[i] !='\0')
    {
        i++;
        if (read_line[i] == '\n' || read_line[i] == '\0')
            end = i;
    }
    keep_line = ft_substr(read_line, start, (start-end));
     return(keep_line);
}
char    *get_next_line(int fd)
{
    static char *read_line;
    char    *final_line;
    int start;
    int end;
    int i;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)//ojo con esta última condición, revisar quizas ni va aquí porque ya lo pongo en el get_next_line si num_bytes < 0
    {
        free(read_line);
        return (NULL);
    }
    read_line = read_till_character(fd, read_line);
    start = 0;
    i = 0;

    if (!read_line[0] || !read_line)
        return (NULL);
    while(read_line[i] != '\n' && read_line[i] != '\0')
        i++;
    while (read_line[i] == '\n')
        i++;
    end = i;      
    final_line = ft_substr(read_line, start, (end-start));
    read_line = separate(read_line);
    return(final_line);
}
