typedef struct{
    char apellido[31];
    char nombre[31];
    int edad;
    int isEmpty;
}ePersona;

void alta( ePersona pers[], int cantidad );

void mostrar( ePersona pers[], int cantidad );
