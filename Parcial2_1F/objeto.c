#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "objeto.h"

Objeto* objeto_new(){
    Objeto *this = malloc(sizeof(Objeto));
    return this;
}

Objeto* objeto_newParametros(char* idStr, char* dominioStr, char* anioStr){
    int id, anio;
    id = atoi(idStr);
    anio = atoi(anioStr);

    Objeto *this = objeto_new();
    objeto_setId(this,id);
    objeto_setDominio(this,dominioStr);
    objeto_setAnio(this,anio);

    return this;
}

int objeto_setId(Objeto* this, int id){
    if(id >0) {
        this->id = id;
    }
    return 0;
}

int objeto_getId(Objeto* this){
    return this->id;
}

int objeto_setDominio(Objeto* this, char* dominio){
    strcpy(this->dominio,dominio);
    return 0;
}

char* objeto_getDominio(Objeto* this){
    return this->dominio;
}

int objeto_setAnio(Objeto* this, int anio){
    if(anio >0){
        this->anio = anio;
    }
    return 0;
}

int objeto_getAnio(Objeto* this){
    return this->anio;
}

int objeto_setTipo(Objeto* this, char tipo){
    this->tipo = tipo;
    return 0;
}

char objeto_getTipo(Objeto* this){
    return this->tipo;
}
