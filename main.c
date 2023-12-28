//fd: archivo a leer
//buffer: Ubicación de almacenamiento de los datos.
//Número máximo de bytes que se pueden leer.
//read del fd 4 en el buffer 5 bytes cada vez que se llama a la función
//read puede recordar la posición actual dentro de el archivo (cada vez que lee?)

//info importante read: https://learn.microsoft.com/es-es/cpp/c-runtime-library/reference/read?view=msvc-170

/* ssize_t read (int fd, void *buf, size_t nbytes)
{

    return
} */

//esto va en el .h 
#ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 1

#endif
//hasta aquí va en el .h

#include <unistd.h> //lirería de read
#include <stddef.h> 
#include <fcntl.h> //librería de open
#include <stdlib.h> //librería de calloc
#include <stdio.h> //librería printf
#include "get_next_line.h"


//esta funcion hace cosas
/*int funcion()
{

}*/

int main(void)
{
    int fd;
    int fd2;
    //char *line_read;
    
    fd = open("doc.txt", O_RDONLY);
    fd2 = open("doc2.txt", O_RDONLY);
    //line_read = get_next_line(fd);
     
    //printf("%s\n", line_read);
    printf("%d", fd);
    printf("\n%d", fd2);
    return 0;

    //char *line; 
    //line = get_next_line(0);
    //funcion()
    //close()??? tengo que usarlo??
}
