#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit){
    int aux;
    int flag = 0;
    int res = -1;

    printf("%s",message);

    while(flag == 0){
        fflush(stdin);

        if(scanf("%d",&aux) == 1){
            if(aux >= lowLimit && aux <= hiLimit){
                res = 0;
                break;
            }
        }
        printf("%s",eMessage);
        break;
    }
    *input = aux;
    return res;
}

int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit){
    float aux;
    int flag = 0;
    int res = -1;

    printf("%s",message);

    while(flag == 0){
        fflush(stdin);

        if (scanf("%f",&aux)==1){
            if (aux >= lowLimit && aux <= hiLimit){
                res = 0;
                break;
            }
        }
        printf("%s",eMessage);
    }
    *input = aux;
    return res;
}

int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit){
    char aux;
    int flag = 0;
    int res = -1;

    printf("%s",message);

    while(flag == 0){
        fflush(stdin);

        if(scanf("%s",&aux) == 1){
            if (aux>lowLimit && aux<hiLimit){
                res = 0;
                break;
            }
        }
        printf("%s",eMessage);
    }
    *input = aux;
    return res;
}

int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit){
    char aux[hiLimit];
    int flag = 0;
    int res = -1;

    printf("%s",message);

    while(flag == 0){
        fflush(stdin);

        if(scanf("%s",aux) == 1){
            if (strlen(aux)>lowLimit && strlen(aux)<hiLimit){
                res = 0;
                break;
            }
        }
        printf("%s",eMessage);
    }
    strcpy(input,aux);
    return res;
}
