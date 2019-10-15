#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "utn.h"

#define CANTEMPLEADOS 5
#define CANTJUEGOS 5
#define CANTALQUILERES 100

int main(){
    eJuegos juegos[] = {{0,"Pelotero",1000},
                        {1,"Inflable",1500},
                        {2,"Mazo de cartas",200},
                        {3,"Ping Pong",850},
                        {4,"Juego de mesa",500}};

    eClientes clientes[CANTEMPLEADOS];
    eAlquileres alquileres[CANTALQUILERES];
    iniciar(clientes, alquileres, CANTEMPLEADOS, CANTALQUILERES);
    menu(alquileres, clientes, juegos, CANTEMPLEADOS, CANTJUEGOS);
    return 0;
}
