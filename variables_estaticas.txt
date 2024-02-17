//VARIABLES ESTÁTICAS:

//esta sí es estática
/*
#include <stdio.h>
	
void func() {
    static int x = 0; // x es inicializada solo una vez durante las tres llamadas a func()
    printf("%d\n", x); // muestra el valor de x
    x = x + 1;
}

int main(int argc, char * const argv[]) {
    func(); // muestra 0
    func(); // muestra 1
    func(); // muestra 2
    return 0;
}
*/

//esta no es estática, para diferenciar como funciona:

/* void funcion() {
    int x = 0; // x es inicializada solo una vez durante las tres llamadas a func()
    printf("%d\n", x); // muestra el valor de x
    x = x + 1;
}

int main(int argc, char * const argv[]) {
    funcion(); // muestra 0
    funcion(); // muestra 0
    funcion(); // muestra 0
    return 0;
*/