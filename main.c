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

#include <unistd.h>

//esta funcion hace cosas
int funcion()
{

}


int main(int argc, char const *argv[])
{
    read();
    funcion()
    return 0;
}
