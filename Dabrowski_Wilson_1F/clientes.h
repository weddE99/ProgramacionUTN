typedef struct{
    int dia,mes,anio;
}eFecha;

typedef struct{
    int codigoJuego;
    char descripcion[51];
    float importe;
    int isEmpty;
}eJuegos;

typedef struct{
    int codigoCliente;
    char apellido[31];
    char nombre[31];
    char sexo;
    char domicilio[51];
    char telefono[21];
    int isEmpty;
}eClientes;

typedef struct{
    int codigoAlquileres;
    eJuegos codigoJuegos;
    eClientes codigoClientes;
    eFecha fecha;
    int isEmpty;
}eAlquileres;

/**
 * \brief Funcion que muestra un menu principal con las opciones del programa e invoca al resto de las funciones.
 * \param eAlquileres alquileres[] estructura que se le pasa al resto de las funciones.
 * \param eClientes clientes[] estructura que se le pasa al resto de las funciones.
 * \param eJuegos juegos[] estructura que se le pasa al resto de las funciones.
 * \param int cantidad entero que da la cantidad de clientes/alquileres.
 * \param int cantJuegos entero que da la cantidad de juegos.
 * \return void
 *
 */
void menu(eAlquileres alquileres[], eClientes clientes[], eJuegos juegos[], int cantidad, int cantJuegos);

/**
 * \brief Funcion que da de alta a los clientes.
 * \param eClientes clientes[] estructura en la cual se inicializaran los datos.
 * \param int cantidad entero que da la cantidad de clientes.
 * \return void
*/
void altaClientes(eClientes clientes[], int cantidad);

/**
 * \brief Funcion que da de alta a los alquileres.
 * \param eAlquileres alquileres[] estructura en la cual se inicializaran los datos.
 * \param eClientes clientes[] estructura que se le pasa al resto de las funciones.
 * \param eJuegos juegos[] estructura que se le pasa al resto de las funciones.
 * \param int cantidad entero que da la cantidad de clientes/alquileres.
 * \param int cantJuegos entero que da la cantidad de juegos.
 * \return void
*/
void altaAlquileres(eAlquileres alquileres[], eJuegos juegos[], eClientes clientes[], int cantidad, int cantJuegos);

/**
 * \brief Funcion que da de baja a los clientes.
 * \param eClientes clientes[] estructura en la cual se eliminaran los datos.
 * \param int cantidad entero que da la cantidad de clientes.
 * \return void
*/
void baja(eClientes clientes[], int cantidad);

/**
 * \brief Funcion que modificara los datos de los clientes.
 * \param eClientes clientes[] estructura en la cual se modificaran los datos.
 * \param int cantidad entero que da la cantidad de clientes.
 * \param int codigo entero que indica cual cliente se quiere modificar.
 * \return void
*/
void modificar(eClientes clientes[], int cantidad, int codigo);

/**
 * \brief Funcion que ordena de forma ascendente a los clientes.
 * \param eClientes clientes[] estructura de la cual se leeran los datos.
 * \param int cantidad entero que da la cantidad de clientes.
 * \return void
*/
void listar(eClientes clientes[], int cantidad);

/**
 * \brief Funcion que inicializa tanto a los clientes y alquileres de forma logica. seteo de isEmpty = 0;
 * \param eClientes clientes[] estructura en la cual se iniciaran los datos.
 * \param eAlquileres alquileres[] estructura en la cual se iniciaran los datos.
 * \param int cantidad entero que da la cantidad de clientes.
 * \return void
*/
void iniciar(eClientes clientes[], eAlquileres alquileres[], int cantidad, int cantAlquileres);

/**
 * \brief Funcion que imprime en pantalla a los clientes.
 * \param eClientes clientes[] estructura de la cual se leeran los datos.
 * \param int cantidad entero que da la cantidad de clientes.
 * \return void
*/
void imprimirClientes(eClientes clientes[], int cantidad);

/**
 * \brief Funcion que imprime a un cliente en particular en pantalla.
 * \param eClientes clientes[] estructura de la cual se leeran los datos.
 * \param int codigo entero que da el codigo de cliente a imprimir.
 * \return void
*/
void imprimirClienteIndiv(eClientes clientes[], int codigo);

/**
 * \brief Funcion que imprime a los juegos en pantalla.
 * \param eJuegos juegos[] estructura de la cual se leeran los datos.
 * \param int cantJuegos entero que da la cantidad de juegos a imprimir.
 * \return void
*/
void imprimirJuegos(eJuegos juegos[], int cantJuegos);

/**
 * \brief Funcion que realiza los informes adicionales.
 * \param eAlquileres alquileres[] estructura en la cual se inicializaran los datos.
 * \param eClientes clientes[] estructura que se le pasa al resto de las funciones.
 * \param eJuegos juegos[] estructura que se le pasa al resto de las funciones.
 * \param int cantidad entero que da la cantidad de clientes/alquileres.
 * \param int cantAlquileres entero que da la cantidad de alquileres.
 * \param int cantJuegos entero que da la cantidad de juegos.
 * \return void
*/
void informesExtra(eAlquileres alquileres[], eClientes clientes[], eJuegos juegos[], int cantidad, int cantAlquileres, int cantJuegos);

/**
 * \brief Funcion que ordena a la estructura juegos de forma descendente.
 * \param eJuegos juegos[] estructura de la cual se leeran los datos.
 * \param int cantJuegos entero que da la cantidad de juegos a imprimir.
 * \return void
*/
void bubbleSort(eJuegos juegos[], int cantJuegos);

/**
 * \brief Funcion que ordena a la estructura juegos por descripcion.
 * \param eJuegos juegos[] estructura de la cual se leeran los datos.
 * \param int cantJuegos entero que da la cantidad de juegos a imprimir.
 * \return void
*/
void ordenarJuegos(eJuegos juegos[], int cantJuegos);
