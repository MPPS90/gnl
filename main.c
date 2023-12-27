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
#  define BUFFER_SIZE 10

#endif
//hasta aquí va en el .h

#include <unistd.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


//esta funcion hace cosas
/*int funcion()
{

}*/

int main(int argc, char const *argv[])
{
    int fd;
    char *buffer;
    ssize_t num_bytes;

    fd = open("doc.txt", O_RDONLY);
    
    buffer = calloc((15+1), sizeof(char));
    num_bytes = read(fd, buffer, BUFFER_SIZE);

    printf("%s\n", buffer);
    printf("%zu", num_bytes);
    return 0;

    //char *line; 
    //line = get_next_line(0);
    //funcion()
}
