//fd: archivo a leer
//buffer: Ubicación de almacenamiento de los datos. Aquí guarda lo que va leyendo.
//buffer_size: Número de bytes a leer.
//read del fd 4 en el buffer 5 bytes cada vez que se llama a la función
//read puede recordar la posición actual dentro de el archivo (cada vez que lee?)

//info importante read: https://learn.microsoft.com/es-es/cpp/c-runtime-library/reference/read?view=msvc-170

/* ssize_t read (int fd, void *buf, size_t nbytes)
{

    return
} */

#include "get_next_line.h"


//esta funcion hace cosas
/*int funcion()
{

}*/

int main(void)
{
    int fd;
    int fd2;
    char    *line_read;
    
    fd = open("doc.txt", O_RDONLY);
    fd2 = open("doc2.txt", O_RDONLY);
    line_read = get_next_line(fd);
     
    //printf("%s\n", line_read);
    printf("%d\n", fd);
    //printf("\n%d", fd2);
    return 0;
    
}

/* pendientes:
-Tengo que meterlo while
-plantear la variable static, en esta se supone  que se guarda hasta donde leyó para que en el siguiente while sepa desde donde debe empezar
*/
