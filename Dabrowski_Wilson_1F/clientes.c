#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clientes.h"
#include "utn.h"

void iniciar(eClientes clientes[], eAlquileres alquileres[], int cantidad, int cantAlquileres){
    int i;
    for(i=0; i<cantidad; i++){
        clientes[i].isEmpty = 1;
    }
    for(i=0; i<cantAlquileres; i++){
        alquileres[i].isEmpty = 1;
    }
}

void modificar(eClientes clientes[], int cantidad, int codigo){
    int flag = 0;
    int i;
    int opcion;
    char conf;
    system("cls");

    for(i=0; i<cantidad; i++){
        if(codigo == clientes[i].codigoCliente){
            if(clientes[i].isEmpty == 0){
                printf("Datos encontrados: \n");
                printf("=============================================================\n");
                printf("%d\t%s\t%s\t%c\t%s\n", clientes[i].codigoCliente,
                        clientes[i].apellido, clientes[i].nombre, clientes[i].sexo,
                        clientes[i].domicilio);
                printf("=============================================================\n");

            do{
                printf("Confirma que desea modificar los datos? (S/N): ");
                fflush(stdin);
                scanf("%c",&conf);
                conf = tolower(conf);
            }while(conf != 's' && conf != 'n');

            if(conf == 's'){
                do{
                    system("cls");
                    printf("Datos encontrados: \n");
                    printf("==========================================================================\n");
                    printf("Codigo\tApellido\tNombre\tSexo\tDomicilio\tTelefono\n");
                    printf("%d\t%s\t%s\t%c\t%s\t%s\n", clientes[i].codigoCliente,
                    clientes[i].apellido, clientes[i].nombre, clientes[i].sexo,
                    clientes[i].domicilio, clientes[i].telefono);
                    printf("==========================================================================\n");
                    printf("\n");

                    printf("1)Modificar Apellido.\n2)Modificar Nombre.\n3)Modificar Sexo.\n");
                    printf("4)Modificar Direccion.\n5)Salir.\nOpcion: ");
                    scanf("%d",&opcion);

                    switch(opcion){
                        case 1:
                            system("cls");
                            getString("Apellido: ",clientes[i].apellido);
                            break;
                        case 2:
                            system("cls");
                            getString("Nombre: ",clientes[i].nombre);
                            break;
                        case 3:
                            system("cls");
                            clientes[i].sexo = getChar("Sexo(F/M): ");
                            break;
                        case 4:
                            system("cls");
                            getString("Domicilio: ",clientes[i].domicilio);
                            break;
                        case 5:
                            break;
                        default:
                            system("cls");
                            printf("\nOpcion Incorrecta!\n");
                        }
                    }while(opcion != 5);
                    flag = 1;
                }
            }
            break;
            system("cls");
        }
    }
    if(flag != 1){
        printf("No se ha encontrado dicho id!\n\n");
    }
}

void baja(eClientes clientes[], int cantidad){
    int auxId;
    int flag=0;
    int i;
    char confirmacion;
    imprimirClientes(clientes,cantidad);

    auxId = getInt("Ingrese el codigo del cliente a dar de baja: ");

    for(i=0; i<cantidad; i++){
        if(auxId == clientes[i].codigoCliente){
            if(clientes[i].isEmpty == 0){
                do{
                    printf("Confirma que desea borrar los datos? (S/N): ");
                    fflush(stdin);
                    scanf("%c",&confirmacion);
                    confirmacion = toupper(confirmacion);
                }while(confirmacion != 'S' && confirmacion != 'N');

                if(confirmacion == 'S'){
                    clientes[auxId-1].isEmpty = 1;
                    flag = 1;
                    system("cls");
                    printf("Los datos se han borrado exitosamente!\n\n");
                }
                if(confirmacion == 'N'){
                    flag = 1;
                }
                break;
            }
        }
    }
    if(flag == 0){
        printf("No se ha encontrado dicho codigo!\n\n");
    }
}

void listar(eClientes clientes[], int cantidad){
    int i,j;
    eClientes auxClientes;

    for(i=0; i<cantidad-1; i++){
        if(clientes[i].isEmpty == 0){
            for(j=i+1; j<cantidad; j++){
                if(clientes[j].isEmpty == 0){
                    if(strcmp(clientes[i].apellido,clientes[j].apellido)>0){
                        auxClientes = clientes[i];
                        clientes[i] = clientes[j];
                        clientes[j] = auxClientes;
                    }

                    if(strcmp(clientes[i].apellido,clientes[j].apellido)==0){
                        if(strcmp(clientes[i].nombre,clientes[j].nombre)>0){
                            auxClientes = clientes[i];
                            clientes[i] = clientes[j];
                            clientes[j] = auxClientes;
                        }
                    }
                }
            }
        }
    }
}

void altaAlquileres(eAlquileres alquileres[], eJuegos juegos[], eClientes clientes[], int cantidad, int cantJuegos){
    int i;
    int j;
    int k;
    int auxCodJuegos;
    int auxCodCliente;
    int auxDia;
    int auxMes;
    int auxAnio;
    int contador = 0;
    imprimirClientes(clientes, cantidad);
    ordenarJuegos(juegos, cantJuegos);
    imprimirJuegos(juegos, cantJuegos);
    for(i=0; i<cantidad; i++){
        if(alquileres[i].isEmpty == 1){
            alquileres[i].codigoAlquileres = i;

            do{
                auxCodCliente = getInt("* Codigo de Cliente: ");
                for(j=0; j<cantidad; j++){
                    if(auxCodCliente == clientes[j].codigoCliente){
                        contador = 1;
                        alquileres[i].codigoClientes = clientes[j];
                    }
                }
                if(contador != 1){
                    printf("Error: codigo no encontrado!\n");
                }
            }while(contador == 0);

            contador = 0;

            do{
                auxCodJuegos = getInt("* Codigo de Juego: ");
                for(k=0; k<cantidad; k++){
                    if(auxCodJuegos == juegos[k].codigoJuego){
                        contador = 1;
                        alquileres[i].codigoJuegos = juegos[k];
                    }
                }
                if(contador != 1){
                    printf("Error: codigo no encontrado!\n");
                }
            }while(contador == 0);

            printf("\n");

            do{
                auxDia = getInt("* Dia: ");
            }while(auxDia >30 || auxDia <0);
            do{
                auxMes = getInt("* Mes: ");
            }while(auxMes >12 || auxMes <=0);
            do{
                auxAnio = getInt("* Anio: ");
            }while(auxAnio >2019 || auxAnio <1900);

            alquileres[i].fecha.dia = auxDia;
            alquileres[i].fecha.mes = auxMes;
            alquileres[i].fecha.anio = auxAnio;
            alquileres[i].isEmpty = 0;
            system("cls");
            break;
        }
    }
}

void altaClientes(eClientes clientes[], int cantidad){
    int i;
    int flag=0;
    int aux;
    char auxTelefono[21];
    for(i=0; i<cantidad; i++){
        if(clientes[i].isEmpty == 1){
            clientes[i].codigoCliente = i+1;

            getString("Nombre: ",clientes[i].nombre);
            getString("Apellido: ",clientes[i].apellido);
            clientes[i].sexo = getChar("Sexo(F/M): ");
            do{
                getString("Telefono: ",clientes[i].telefono);
                strcpy(auxTelefono,clientes[i].telefono);
                aux = esTelefono(auxTelefono);
            }while(aux != 1);
            getString("Domicilio: ",clientes[i].domicilio);

            flag = 1;
            clientes[i].isEmpty = 0;
            system("cls");
            break;
        }
    }
    if(flag == 0){
        printf("NO HAY MAS LUGAR PARA GUARDAR DATOS!!\n\n");
    }
}

void ordenarJuegos(eJuegos juegos[], int cantidadJ){
    int i;
    int j;
    eJuegos auxJuegos;

    for(i=0; i<cantidadJ-1; i++){
        for(j=i+1; j<cantidadJ; j++){
            if(strcmp(juegos[i].descripcion,juegos[j].descripcion)>0){
                auxJuegos = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = auxJuegos;
            }
        }
    }
}

void imprimirClienteIndiv(eClientes clientes[], int i){
    printf("%d\t%s\t%s\t%c\t%s\t%s\n", clientes[i].codigoCliente,
                   clientes[i].apellido, clientes[i].nombre, clientes[i].sexo,
                   clientes[i].domicilio, clientes[i].telefono);
}

void imprimirClientes(eClientes clientes[], int cantidad){
    int i;
    printf("==========================================================================\n");
    printf("Codigo\tApellido\tNombre\tSexo\tDomicilio\tTelefono\n");
    for(i=0; i<cantidad; i++){
        if(clientes[i].isEmpty == 0){
            imprimirClienteIndiv(clientes,i);
        }
    }
    printf("==========================================================================\n");
    printf("\n");
}

void informesExtra(eAlquileres alquileres[], eClientes clientes[], eJuegos juegos[], int cantidad, int cantAlquileres, int cantJuegos){
    int i;
    int auxDia, auxMes, auxAnio;
    float auxSumaImportes = 0;
    float auxPromedioImportes = 0;
    int contador = 0;
    int contadorA = 0;
    char auxJuego[51];
    char auxNombre[31];

    imprimirClientes(clientes, cantidad);
    imprimirJuegos(juegos, cantidad);

    for(i=0; i<cantAlquileres; i++){
        if(alquileres[i].isEmpty == 0){
            auxSumaImportes += alquileres[i].codigoJuegos.importe;
            contador++;
        }
    }
    auxPromedioImportes = auxSumaImportes / contador;
    printf("\n **INFORMES** \n\n");
    printf("El total de los importes de los juegos alquilados es de: %.2f\n",auxSumaImportes);
    printf("El promedio de los importes de los juegos alquilados es de: %.2f\n",auxPromedioImportes);

    for(i=0; i<cantJuegos; i++){
        if(juegos[i].importe < auxPromedioImportes){
            contadorA++;
        }
    }

    printf("La cantidad de juegos cuyo importe no supera el promedio es de: %d\n",contadorA);
    printf("==========================================================================\n");
    getString("\nIngrese el nombre del cliente que desea saber si se ha alquilado: ",auxNombre);

    contador = 0;
    for(i=0; i<cantAlquileres;i++){
        if(alquileres[i].isEmpty == 0){
            if(strcmp(alquileres[i].codigoClientes.nombre,auxNombre)==0){
                printf("\nEl usuario ha alquilado: \n");
                printf("* %s\n",alquileres[i].codigoJuegos.descripcion);
                contador = 1;
            }
        }
    }
    if(contador == 0){
        printf("El cliente no ha alquilado ningun juego!\n");
    }
    printf("==========================================================================\n");
    getString("\nIngrese el nombre del juego que desea saber si se ha alquilado: ",auxJuego);

    contador = 0;
    for(i=0; i<cantAlquileres;i++){
        if(alquileres[i].isEmpty == 0){
            if(strcmp(alquileres[i].codigoJuegos.descripcion,auxJuego)==0){
                printf("\nEl juego  ha sido alquilado por: \n");
                printf("* %s\t",alquileres[i].codigoClientes.nombre);
                printf(" %s \n",alquileres[i].codigoClientes.apellido);
                contador = 1;
            }
        }
    }
    if(contador == 0){
        printf("El juego no ha sido alquilado por ningun cliente!\n");
    }
    printf("==========================================================================\n");
    printf("\nLos juegos alquilados en una fecha especifica: ");
    printf("\nIngresar fecha: \n");

    do{
        auxDia = getInt("* Dia: ");
    }while(auxDia >30 || auxDia <0);
    do{
        auxMes = getInt("* Mes: ");
    }while(auxMes >12 || auxMes <=0);
    do{
        auxAnio = getInt("* Anio: ");
    }while(auxAnio >2019 || auxAnio <1900);

    contador = 0;

    for(i=0; i<cantAlquileres;i++){
        if(alquileres[i].isEmpty == 0){
            if(alquileres[i].fecha.dia == auxDia && alquileres[i].fecha.mes == auxMes
               && alquileres[i].fecha.anio == auxAnio){
                printf("\n* %s\n",alquileres[i].codigoJuegos.descripcion);
                contador++;
            }
        }
    }
    if(contador == 0){
        printf("No se ha alquilado ningun juego en esa fecha!\n");
    }

    printf("==========================================================================\n");
    printf("\nAveriguar quien alquilo en la siguiente fecha: \n");
    do{
        auxDia = getInt("* Dia: ");
    }while(auxDia >30 || auxDia <0);
    do{
        auxMes = getInt("* Mes: ");
    }while(auxMes >12 || auxMes <=0);
    do{
        auxAnio = getInt("* Anio: ");
    }while(auxAnio >2019 || auxAnio <1900);
    contador = 0;

    for(i=0; i<cantAlquileres;i++){
        if(alquileres[i].isEmpty == 0){
            if(alquileres[i].fecha.dia == auxDia && alquileres[i].fecha.mes == auxMes
               && alquileres[i].fecha.anio == auxAnio){
                printf("\n* %s \t",alquileres[i].codigoClientes.nombre);
                printf(" %s *\n",alquileres[i].codigoClientes.apellido);
                contador++;
            }
        }
    }
    if(contador == 0){
        printf("Nadie alquilo en esa fecha!\n");
    }

    printf("==========================================================================\n");
    printf("\nJuegos ordenados por importe(descendente):\n");
    bubbleSort(juegos, cantJuegos);
    imprimirJuegos(juegos, cantJuegos);

    printf("\n\n\n");
}

void imprimirJuegos(eJuegos juegos[], int cantJuegos){
    int i;
    printf("==========================================\n");
    printf("CodigoJuego\tDescripcion\tImporte\n");
    printf("==========================================\n");
    for(i=0; i<cantJuegos; i++){
            printf("%d\t\t%s\t%.0f\n", juegos[i].codigoJuego,
                   juegos[i].descripcion, juegos[i].importe);
    }
    printf("==========================================\n");
}

void bubbleSort(eJuegos juegos[], int cantJuegos){
    int j;
    eJuegos auxJuegos;
    int flagNoEstaOrdenado = 1;
    while(flagNoEstaOrdenado == 1){
        flagNoEstaOrdenado = 0;
        for (j=1; j<5; j++){
            if (juegos[j].importe < juegos[j-1].importe){
                auxJuegos = juegos[j];
                juegos[j] = juegos[j-1];
                juegos[j-1] = auxJuegos;
                flagNoEstaOrdenado = 1;
            }
        }
    }
}

void menu(eAlquileres alquileres[], eClientes clientes[], eJuegos juegos[], int cantidad, int cantJuegos){
    int opc;
    int codigo;
    int contador = 0;
    do{
        printf("1)Alta Clientes\n2)Alta Alquileres.\n3)Modificar Clientes.\n4)listar Clientes.\n5)Listar Juegos.\n6)Borrar Clientes\n");
        printf("7)Informes Extra.\n8)Salir.");
        printf("\n===========\nOpcion: ");
        scanf("%d",&opc);

        switch(opc){
            case 1:
                system("cls");
                altaClientes(clientes, cantidad);
                contador++;
                break;
            case 2:
                if(contador != 0){
                    system("cls");
                    altaAlquileres(alquileres, juegos, clientes, cantidad, cantJuegos);
                }
                else{
                    system("cls");
                    printf("No se han ingresado clientes!\n\n");
                }
                break;
            case 3:
                if(contador != 0){
                    system("cls");
                    listar(clientes, cantidad);
                    imprimirClientes(clientes, cantidad);
                    codigo = getInt("Ingrese el codigo de cliente a modificar: ");
                    modificar(clientes, cantidad, codigo);
                    system("cls");
                }
                else{
                    system("cls");
                    printf("No se han ingresado clientes!\n\n");
                }
                break;
            case 4:
                if(contador != 0){
                    system("cls");
                    listar(clientes, cantidad);
                    imprimirClientes(clientes,cantidad);
                    printf("\n");
                }
                else{
                    system("cls");
                    printf("No se han ingresado clientes!\n\n");
                }
                break;
            case 5:
                system("cls");
                printf("==========================================\n");
                ordenarJuegos(juegos, cantJuegos);
                imprimirJuegos(juegos, cantJuegos);
                printf("==========================================\n\n");
                break;
            case 6:
                if(contador != 0){
                    system("cls");
                    baja(clientes, cantidad);
                }else{
                    system("cls");
                    printf("No se han ingresado clientes!\n\n");
                }
                break;
            case 7:
                if(contador != 0){
                        system("cls");
                    informesExtra(alquileres,clientes,juegos,cantidad,100,cantJuegos);
                }
                else{
                    system("cls");
                    printf("No se han ingresado clientes!\n\n");
                }
                break;
            case 8:
                break;
            default:
                printf("No se ha ingresado una opcion correcta!.\n");
        }
    }while(opc != 8);
}
