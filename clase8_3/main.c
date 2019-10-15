#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

#define CANT 10
int main(){

    /*
    ePersona pers[CANT];
    alta(pers, CANT);
    system("cls");
    printf("Ordenados por ingreso: \n");
    mostrarTodos(pers, CANT);
    printf("\nOrdenados por edad: \n");
    ordenar(pers, CANT);

    ePersona pers[3] = {{"ape1","nom1",1,0,1,1,1999},
                        {"ape2","nom2",2,0,2,2,1999},
                        {"ape3","nom3",3,0,3,3,1999}};

    */

    ePersona pers[CANT];
    inicializacion(pers, CANT);
    menu(pers, CANT);

    return 0;
}
