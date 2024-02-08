#include "get_next_line.h"

char    *find(int fd)
{
    ssize_t num_bytes;
    char    buffer[BUFFER_SIZE];
    char    *line;

    line = (char *)malloc(1);
     if(line == NULL)
        return (NULL);
    line[0]='\0';
    num_bytes = 1;
    while(num_bytes > 0) //aquí podría poner que read_line[i] != '\n'??
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        printf("PRUEBA BUFFER: >>%s<<\n", buffer);
        line = ft_strjoin(line, buffer);
        printf("PRUEBA LINE: %s\n", line);
        if(strchr(line,'\n'))
            break;
        printf("PRUEBA SALTO: %c\n", line[num_bytes]);
    }
    
    return(line);
}

  int main(void)
{
    int fd;
    char    *line;
    
    fd = open("doc.txt", O_RDONLY);
    line = find(fd); //ojo que aquí en el main debo llamar es a get_next_line hice cambio a find mientras organizo el código
    printf("Line main: >%s<\n", line);    
    return 0;
}
