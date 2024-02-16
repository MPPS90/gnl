//fd: archivo a leer
//buffer: PUNTERO a la ubicación de almacenamiento de los datos leídos. Aquí guarda lo que va leyendo.
//buffer_size: Número de bytes a leer.
//read= devulve la cantidad de bytes leídos. Si ocurre erros devuelve -1 
//read del fd 4 en el buffer 5 bytes cada vez que se llama a la función
//read puede recordar la posición actual dentro de el archivo (cada vez que lee?)

//info importante read: https://learn.microsoft.com/es-es/cpp/c-runtime-library/reference/read?view=msvc-170

/* ssize_t read (int fd, void *buf, size_t nbytes)
{

    return
} */

#include "get_next_line.h"

void    detect_leaks(void)
{
    system("leaks a.out");
}


int main(void)
{
    int fd;
    char    *line;

    // atexit(detect_leaks);
    fd = open("txt.txt", O_RDONLY);

    line = "";
    while(line)
    {
        line = get_next_line(fd);
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}

/*
//MAIN GNL**
//el main debería llevar un while porque debe leer el archivo constantemente
int main(void)
{
    int fd;
    char    *line;
        
    fd = open("txt.txt", O_RDONLY);
    //Porque con line voy línea a línea (no carácter por carácter) y el NULL indica final de fichero en este caso.
    while ((line = get_next_line(fd)) != NULL)
    {
        //line = get_next_line(fd); 
        printf("%s\n", line);
        free(line);
       if(line == NULL)
       {
            printf("He llegao al final\n");
            break ;
        } 
    }
    close(fd);
    return 0;
}*/

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

//pendientes 14/02
//Me está impriendo saltos de línea de más, pero no sé por qué, quizás es el substr, estuve tratando de darle una condición que solo cuando lea /n meta un espacio más..
