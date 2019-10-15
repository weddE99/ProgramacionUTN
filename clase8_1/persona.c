#include <stdio.h>
#include <stdlib.h>
#include "persona.h"

ePersona alta(ePersona per){
    printf("Apellido: ");
    fflush(stdin);
    scanf("%s", per.apellido);

    printf("Nombre: ");
    fflush(stdin);
    scanf("%s", per.nombre);

    printf("Edad: ");
    scanf("%d", &per.edad);

    per.isEmpty = 0;

    return per;
}

void mostrar(ePersona per){
    printf("%s\t%s\t%d\t%d\n", per.apellido, per.nombre, per.edad, per.isEmpty);
}
