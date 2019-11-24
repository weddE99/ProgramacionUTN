#ifndef objeto_H_INCLUDED
#define objeto_H_INCLUDED

typedef struct{
    int id;
    char dominio[6];
    int anio;
    char tipo;
}Objeto;

Objeto* objeto_new();
Objeto* objeto_newParametros(char* idStr, char* dominioStr, char* anioStr);
int objeto_setId(Objeto* this, int id);
int objeto_getId(Objeto* this);
int objeto_setDominio(Objeto* this, char* dominio);
char* objeto_getDominio(Objeto* this);
int objeto_setAnio(Objeto* this, int anio);
int objeto_getAnio(Objeto* this);
int objeto_setTipo(Objeto* this, char tipo);
char objeto_getTipo(Objeto* this);

#endif // objeto_H_INCLUDED
