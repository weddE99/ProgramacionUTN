#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int resCal = 0, resp, respuestaS, respuestaR, respuestaM, respuestaF, respuestaF2, n1, n2;
int num1 = 0;
int num2 = 0;
int error;
int bandera = 0;
float respuestaD;

int main(){
    while(resCal != 5){
        system("cls");
        printf("1) Ingresar 1er operando (A = %d)",num1);
        printf("\n2) Ingresar 2do operando (B = %d)",num2);
        printf("\n3) Calcular todas las operaciones.");
        printf("\n4) Informar resultados.");

        if(resp == 1){
            printf("\n========================================");
            printf("\n   A = %d\n   B = %d\n",n1,n2);
            printf("\n   *El Resultado de A + B es %d",respuestaS);
            printf("\n   *El Resultado de A - B es %d",respuestaR);
            printf("\n   *El Resultado de A * B es %d",respuestaM);

            if(error == 3){
                printf("\n   *Error: No se puede dividir por cero!!!");
                error = 0;
            }
            else printf("\n   *El Resultado de A / B es %.2f",respuestaD);

            printf("\n   *El Factorial de A es %d",respuestaF);
            printf("\n   *El Factorial de B es %d",respuestaF2);
            printf("\n========================================");

            bandera = 0;
        }

        printf("\n5) Salir.");

        if(error == 1){
            printf("\n\nError: No ha ingresado una opcion valida!");
            error = 0;
        }
        if(error == 2){
            printf("\n\nError: No ha ingresado los dos digitos necesarios!");
            error = 0;
        }
        if(error == 4){
            printf("\n\nError: Necesita calcular los datos primeramente!");
            error = 0;
        }
        printf("\n\nOpcion: ");
        scanf("%d",&resCal);

        switch(resCal){
            case 1:
                system("cls");
                printf("Ingrese el numero A: ");
                scanf("%d",&num1);
                resp = 0;
                bandera++;
                break;
            case 2:
                system("cls");
                printf("Ingrese el numero B: ");
                scanf("%d",&num2);
                resp = 0;
                bandera++;
                break;
            case 3:
                if(bandera == 2){
                    respuestaS = suma(num1,num2);
                    respuestaR = resta(num1,num2);
                    respuestaM = multiplicacion(num1,num2);

                    if(num2 != 0) respuestaD = division(num1,num2);
                    else error = 3;

                    respuestaF = factorial(num1);
                    respuestaF2 = factorial(num2);
                    resp = 0;
                    bandera++;
                }
                else error = 2;
                break;
            case 4:
                if(bandera == 3){
                    resp = 1;
                    n1 = num1;
                    n2 = num2;
                    num1 = 0;
                    num2 = 0;
                }
                else error = 4;
                break;
            case 5:
                break;
            default:
                error = 1;
        }
    }
    return 0;
}
