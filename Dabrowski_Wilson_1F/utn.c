#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 */
float getFloat(char mensaje[]){
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 */
int getInt(char mensaje[]){
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 */
char getChar(char mensaje[]){
    char auxiliar;
    do{
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%c",&auxiliar);
        auxiliar = toupper(auxiliar);
    }while((auxiliar != 'F') && (auxiliar != 'M'));
    return auxiliar;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[]){
    do{
        printf("%s",mensaje);
        fflush(stdin);
        scanf ("%[^\n]s", input);
    }while((strlen(input)<=0) || (strlen(input)>31));
}

/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 */
int esTelefono(char str[]){
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0'){
        if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9')){
           return 0;
        }
        if(str[i] == '-'){
            contadorGuiones++;
        }
        i++;
    }
    if(contadorGuiones ==1 || contadorGuiones == 0){// debe tener un guion
        return 1;
    }
    return 0;
}
