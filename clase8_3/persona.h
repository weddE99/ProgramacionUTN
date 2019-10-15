typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    int dni;
    char apellido[31];
    char nombre[31];
    int edad;
    eFecha fechaNac;
    int isEmpty;
    int ePais;// estructura 1 a *
}ePersona;

typedef struct{ // estructura 1 a *
    int id;
    char descripcion[31];
}ePais;

void menu(ePersona pers[], int cantidad);
void inicializacion(ePersona pers[], int cantidad);
void alta(ePersona pers[], ePais pais[], int cantidad, int id);
void baja(ePersona pers[], int cantidad);
void modificacion(ePersona pers[], int cantidad);
void mostrarUno(ePersona per, ePais pais);
void mostrarTodos(ePersona pers[], ePais pais[], int cantidad);
void ordenar(ePersona pers[], ePais pais[], int cantidad);
