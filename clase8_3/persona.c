#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#define CPAIS 6

void menu(ePersona pers[], int cant){
    ePais pais[6] = {{0,"Argentina"},{1,"Uruguay"},{2,"Brasil"},{3,"Chile"},{4,"Peru"}, {5,"Paraguay"}};
    int opc;
    do{
        printf("1)Ingresar alta de una persona.\n2)Dar de baja a una persona.\n3)Mostrar todos los ingresados.\n");
        printf("4)Ordenarlos por edad.\n5)Modificar datos de una persona.\n6)Salir.\n\nOpcion: ");
        scanf("%d",&opc);
        switch(opc){
            case 1:
                system("cls");
                alta(pers, pais, cant, 6);
                break;
            case 2:
                system("cls");
                baja(pers, cant);
                break;
            case 3:
                system("cls");
                printf("Mostrar todos los ingresados: \n");
                mostrarTodos(pers, pais, cant);
                printf("\n");
                break;
            case 4:
                system("cls");
                printf("Ordenados por edad: \n");
                ordenar(pers, pais, cant);
                printf("\n");
                break;
            case 5:
                system("cls");
                modificacion(pers,cant);
                break;
            case 6:
                break;
            default:
                printf("Se ha ingresado una opcion incorrecta!");
        }
    }while(opc != 6);
}

void inicializacion(ePersona pers[], int cant){
    int i;
    for(i=0; i< cant; i++){
        pers[i].isEmpty = 1;
    }
}

void baja(ePersona pers[], int cant){
    int auxId, flag = 0, i;
    char confirmacion;
    printf("Ingrese el dni a dar de baja: ");
    scanf("%d",&auxId);

    for(i=0; i<cant;i++){
        if(auxId == pers[i].dni){
            printf("Datos encontrados: \n");
            printf("====================================================\n");
            printf("%d\t%s\t%s\t%d\t%d:%d:%d\t%d\t%d\n", pers[i].dni, pers[i].apellido, pers[i].nombre, pers[i].edad,
            pers[i].fechaNac.dia, pers[i].fechaNac.mes, pers[i].fechaNac.anio, pers[i].ePais, pers[i].isEmpty);
            printf("====================================================\n");

            do{
                printf("Confirma que desea borrar los datos? (S/N): ");
                fflush(stdin);
                scanf("%c",&confirmacion);
                toupper(confirmacion);
            }while(confirmacion != 's' && confirmacion != 'n');

            if(confirmacion == 's'){
                pers[i].isEmpty = 1;
                flag = 1;
                printf("\nLos datos se han borrado exitosamente!\n\n");
            }
        break;
        }
    }
    if(flag == 0){
        printf("No se ha encontrado dicho dni!\n\n");
    }
}

void modificacion(ePersona pers[], int cant){
    int auxId, flag = 0, i, opc2;
    char confirmacion;
    printf("Ingrese el dni a modificar: ");
    scanf("%d",&auxId);

    for(i=0; i<cant;i++){
        if(auxId == pers[i].dni){
            printf("Datos encontrados: \n");
            printf("====================================================\n");
            printf("%d\n%s\n%s\n%d\n%d:%d:%d\n%d\n%d\n", pers[i].dni, pers[i].apellido, pers[i].nombre, pers[i].edad,
            pers[i].fechaNac.dia, pers[i].fechaNac.mes, pers[i].fechaNac.anio, pers[i].ePais, pers[i].isEmpty);
            printf("====================================================\n");

            do{
                printf("Confirma que desea modificar los datos? (S/N): ");
                fflush(stdin);
                scanf("%c",&confirmacion);
                toupper(confirmacion);
            }while(confirmacion != 's' && confirmacion != 'n');

            if(confirmacion == 's'){
                do{
                    system("cls");
                    printf("Datos encontrados: \n");
                    printf("====================================================\n");
                    printf("%d\n%s\n%s\n%d\n%d:%d:%d\n%d\n%d\n", pers[i].dni, pers[i].apellido, pers[i].nombre, pers[i].edad,
                    pers[i].fechaNac.dia, pers[i].fechaNac.mes, pers[i].fechaNac.anio, pers[i].ePais, pers[i].isEmpty);
                    printf("====================================================\n\n");
                    printf("1) Modificar nombre.\n2) Modificar apellido.\n3) Modificar edad.\n3) Modificar F.Nac.\n");
                    printf("4) Modificar nacionalidad.\n5) Salir.");
                    printf("\nOpcion: ");
                    scanf("%d",&opc2);

                    switch(opc2){
                        case 1:
                            system("cls");
                            printf("Nombre: ");
                            fflush(stdin);
                            scanf("%s", pers[i].nombre);
                            break;
                        case 2:
                            system("cls");
                            printf("Apellido: ");
                            fflush(stdin);
                            scanf("%s", pers[i].apellido);
                            break;
                        case 3:
                            system("cls");
                            printf("Edad: ");
                            fflush(stdin);
                            scanf("%s", pers[i].edad);
                            break;
                        case 4:
                            system("cls");
                            printf("Fecha Nacimiento: ");
                            fflush(stdin);
                            scanf("%s", pers[i].fechaNac);
                            break;
                        case 5:
                            break;
                        default:
                            printf("Opcion Incorrecta!");
                    }
                }while(opc2 != 5);
                flag = 1;
            }
        break;
        }
    }
    if(flag == 0){
        printf("No se ha encontrado dicho dni!\n\n");
    }
}

void alta(ePersona pers[], ePais pais[], int cantidad, int id){
    int i,j,flag = 0;

    for(i=0; i< cantidad; i++){
        printf("%d",pers[i].isEmpty);
        printf("\n\n");
        if(pers[i].isEmpty == 1){
            printf("Dni: ");
            scanf("%d", &pers[i].dni);

            printf("Apellido: ");
            fflush(stdin);
            scanf("%s", pers[i].apellido);

            printf("Nombre: ");
            fflush(stdin);
            scanf("%s", pers[i].nombre);

            printf("Edad: ");
            scanf("%d", &pers[i].edad);
            printf("\n");

            printf("Fecha Nacimiento\n\tDia: ");
            scanf("%d",&pers[i].fechaNac.dia);
            printf("\tmes: ");
            scanf("%d",&pers[i].fechaNac.mes);
            printf("\tanio: ");
            scanf("%d",&pers[i].fechaNac.anio);

            printf("\nIngrese nacionalidad: \n");

            for(j=0;j<CPAIS;j++){
                printf("\t%d %s\n",pais[j].id, pais[j].descripcion);
            }
            printf("\n");
            printf("Opcion: ");
            scanf("%d",&pers[i].ePais);

            for(i=0; i<CPAIS; i++){
                if(pais[i].id == pers[i].ePais){
                    for(j=0; j<CPAIS; j++){
                        if(pers[j].ePais == pers[i].ePais){
                            printf("%s %s",pers[j].nombre, pais[i].descripcion);
                        }
                    }
                    break;
                }
            }

            flag = 1;
            pers[i].isEmpty = 0;
            //system("cls");
            break;
        }
    }
    if(flag == 0){
        printf("NO HAY MAS LUGAR PARA GUARDAR DATOS!!\n\n");
    }
}

void mostrarTodos(ePersona pers[], ePais pais[], int cantidad){
    int i,j;
    for(i=0; i< cantidad; i++){
        if(pers[i].isEmpty == 0){
            mostrarUno(pers[i], pais[i]);
        }
    }
}

void mostrarUno(ePersona pers, ePais pais){
    printf("%d\t%s\t%s\t%d\t%d:%d:%d\t%d\t%d\n", pers.dni, pers.apellido, pers.nombre, pers.edad,
           pers.fechaNac.dia, pers.fechaNac.mes, pers.fechaNac.anio, pers.ePais, pers.isEmpty);
}

void ordenar(ePersona pers[], ePais pais[], int cant){
    ePersona auxPer;
    int i,j;
    for(i=0;i<cant-1;i++){
		for(j=i+1;j<cant;j++){
			if(pers[i].edad > pers[j].edad){
				auxPer = pers[i];
				pers[i] = pers[j];
				pers[j] = auxPer;
			}
		}
	}
    mostrarTodos(pers, pais, cant);
}
