#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int main()
{
    int vMark[MAX];
    int vect[MAX];
    int i,j,tem;
    for (i=0;i<MAX;i++){vect[i]=0;}
    for (i=0;i<MAX;i++){vMark[i]=1;}
    int opcion=1;

    while(opcion!=3){

        printf("1)ingresar nuevo valor\n2)inprimir valores \n3)Salir\n4)Ordenar");
        scanf("%d",&opcion);
        system("cls");
        switch (opcion){

    case 1:
        for(i=0;i<MAX;i++){
            if(vMark[i]==1){
                printf("ingrese valor entero");
                scanf("%d",&vect[i]);
                vMark[i]=0;
                break; //preguntar;
                }


            }


    break;

    case 2:
        for(i=0;i<MAX;i++){printf("%d  %d\n",i,vect[i]);}
        for(i=0;i<MAX;i++){printf("%d  %d\n",i,vMark[i]);}
        break;




    case 4:
        for(i=0;i<MAX;i++){
            tem=vect[i];
            j=i-1;
            while(j>=0&&tem>vect[j]){
             vect[j+1]=vect[j];
             j--;
            }
            vect[j+1]=tem;

        }
     break;
    }


    }
return 0;
}
