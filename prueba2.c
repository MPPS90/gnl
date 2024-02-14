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
    //char    *aux;//aux = no tengo que reservarle memoria porque apunta a lo que ya tiene apuntado read_line (es decir quee esa memoria ya se ha reservado)
    
    if(read_line == NULL)
        read_line = malloc(sizeof(char));
        //return (NULL);
    read_line[0] = '\0';
    printf(">>>>ptr: %p\n", &read_line);
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));//en el malloc tiene sentido hacer el casteo inicial que tengo??
    if(buffer == NULL)
        return (NULL);
    num_bytes = 1;
    while(num_bytes > 0 && !ft_strchr(read_line, '\n'))
    {
        num_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[num_bytes] = '\0';
        //printf("comprobación buffer: >%s<\n", buffer);
        //aux = read_line;
        //printf("comprobación q llega aux: %s\n", aux);
        read_line = ft_strjoin(read_line, buffer);
        printf("ptr: %p\n", &read_line);
        //free(aux);
        //aux = NULL; 
        //printf("comprobación auxilar: %s\n",  aux);
        //printf("comprobación read_line:->%s<-\n", read_line);
    }  
    free(buffer);
    buffer = NULL;
    //printf("return: %s\n", read_line); 
    //printf("buffer: %s\n", buffer);
    //printf("aux: %s\n", aux);
    return(read_line); //read_line no debo liberarlo, no??
    
    //AQUI HAY QUE LLAMAR A SEPARATE Y GNL LLAMA A READ_TILL_CHARACTER
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
    //int start;
    int end;
    int i;
    //start = ft_strchr(read_line, '\n'); strchr devuelve un puntero (variable que almacena una dirección de memoria)a la primera ocurrencia del caracter especificado
    i=0;
    while(read_line[i] != '\n' && read_line[i] !='\0')
        i++;
    //RECORDAR ESTO, QUE SIEMPRE LO PONGO SIN [i] Y HAGO UN BUCLE INFINITO
    while(read_line[i] == '\n' && read_line[i] !='\0')
        i++;
    //start = i;
    while(read_line[i] != '\n' && read_line[i] !='\0')
    {
        i++;
        if (read_line[i] == '\n' || read_line[i] == '\0')
            end = i;
    }
    keep_line = ft_substr(read_line, i, (ft_strlen(read_line)-i));
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
    
    read_line = read_till_character(fd, read_line);
    printf("Devuelve read_till_line en main: %s\n", read_line);
    start = 0;
    i = 0;

    while(read_line[i] != '\n' && read_line[i] != '\0') 
        i++;
    end = i;      
    //final_line = ft_substr(read_line, start, (end-start));
    final_line = read_line;
    printf("La linea final: %s\n", final_line);
    read_line = separate(read_line);
    printf("Lo de despues: %s\n", read_line);

    //printf("%c\n", read_line[0]);
    //printf("%c\n", (i-(read_line[0])));
    //printf("%s\n", final_line);
    return(final_line);
}
    
    
//**MAIN GNL**
//el main debería llevar un while porque debe leer el archivo constantemente
int main(void)
{
    int fd;
    char    *line;
    char    *line2;
        
    fd = open("doc.txt", O_RDONLY);
    line = get_next_line(fd); 
    printf("Line main: %s\n", line);
    line2 = get_next_line(fd); 
    printf("Line main: %s\n", line2);
    //system("leaks a.out");
    return 0;
}

//**MAIN SEPARATE**
/*int main(void)
{
    char	*s;
	char	c;
    char    *new_s;

    c = ',';
    s = "hola,HOLIWI,hello";
    new_s = separate(s, c);
    printf("%s\n", new_s);
    return 0;   
}*/