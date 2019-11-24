#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "linkedList.h"
#include "objeto.h"
#include "dominio.h"

struct Auxiliar{
    int id;
    char dominio[6];
    int anio;
    char tipo;
};

void dominio_printfMenu(){
    printf("\t** MENU **");
    printf("\n=========================");
    printf("\n1) Carga del archivo.\n2) Vista de datos cargados.\n3) Guardar datos cargados.\n4) Salir.\n");
    printf("=========================\n");
}

void dominio_lecturaNombreArchivo(char *nombreArchivo){
    int aux;
    do{
        aux = getString(nombreArchivo,"Nombre del archivo: ","El largo debe ser entre 2 y 50",2,50);
        if(aux != 0) printf("\n");
    }while(aux != 0);
}

int dominio_loadFromText(char* path, LinkedList* pArrayList){
    FILE *pFile;
    int r;
    char var1[50],var2[50],var3[50];

    pFile = fopen(path,"r");

    if(pFile == NULL){
        return -1;
    }

    r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",var1,var2,var3);
        if(r==3){
            Objeto *this = objeto_newParametros(var1, var2, var3);
            ll_add(pArrayList,this);
        }
        else{
            break;
        }
    }while(!feof(pFile));
    fclose(pFile);
    return 1;
}

int dominio_saveAsText(char* path, LinkedList* pArrayList){
    int i=0;
    FILE *pFile;
    Objeto *pers;

    if((pFile = fopen(path,"w"))==NULL){
		printf("No se pudo abrir el archivo");
	}

	fprintf(pFile,"id,dominio,anio,tipo");

	for(i=0; i<ll_len(pArrayList); i++){
        pers = ll_get(pArrayList,i);
        fprintf(pFile,"\n%d,%s,%d,%c",objeto_getId(pers),objeto_getDominio(pers),
                                        objeto_getAnio(pers),objeto_getTipo(pers));
	}
	fclose(pFile);
    return 1;
}

int dominio_ListObjeto(LinkedList* pArrayListEmployee){
    Objeto *pers;
    int i;

    printf(" * Elementos cargados en la LinkedList *");
    printf("\n=========================================\n");
    for(i=0; i<ll_len(pArrayListEmployee); i++){
        pers = ll_get(pArrayListEmployee,i);
        printf("%d - %s - %d - %c\n",objeto_getId(pers),objeto_getDominio(pers),
                                        objeto_getAnio(pers),objeto_getTipo(pers));
	}
	printf("=========================================\n\n");
    return 1;
}

void dominio_mapTipo(void* pObjeto){
    char aux[10];

    if (pObjeto!= NULL){
        strcpy(aux,objeto_getDominio(pObjeto));

        if (isdigit(aux[0])==0){
            objeto_setTipo(pObjeto,'A');
        }
        else{
            objeto_setTipo(pObjeto,'M');
        }
    }
}

int dominio_filtrarMotos(void* p){
    int ok = 0;
    Objeto* motos;

    if(p != NULL){
        motos = (Objeto*) p;
        if(motos->tipo == 'M'){
            ok = 1;
        }
    }
    return ok;
}

int dominio_filtrarAutos(void* p){
    int ok = 0;
    Objeto* autos;

    if(p != NULL){
        autos = (Objeto*) p;
        if(autos->tipo == 'A'){
            ok = 1;
        }
    }
    return ok;
}

void dominio_menuInicio(){
    LinkedList* auxiliar = ll_newLinkedList();
    LinkedList* listaMotos = ll_newLinkedList();
    LinkedList* listaAutos = ll_newLinkedList();
    int option = 0;
    int aux;
    char nombreArchivo[51];
    do{
        dominio_printfMenu();

        do{
            aux = getInt(&option,"\nOpcion: ","Rango valido [1 - 4]",1,4);
            if(aux != 0) printf("\n");
        }while(aux != 0);

        switch(option){
            case 1:
                system("cls");
                dominio_lecturaNombreArchivo(nombreArchivo);
                aux = dominio_loadFromText(nombreArchivo,auxiliar);
                ll_map(auxiliar, dominio_mapTipo);
                listaMotos = ll_filter(auxiliar, dominio_filtrarMotos);
                listaAutos = ll_filter(auxiliar, dominio_filtrarAutos);

                system("cls");
                if(aux == 1) printf("Cantidad de elementos en la linkedList: %d\n\n",ll_len(auxiliar));
                else printf("ERROR!. Ese archivo no existe o no se pudieron cargar los datos.\n\n");
                break;
            case 2:
                system("cls");
                dominio_ListObjeto(auxiliar);
                system("pause");
                system("cls");
                break;
            case 3:
                dominio_saveAsText("auto.csv",listaAutos);
                dominio_saveAsText("moto.csv",listaMotos);
                break;
            case 4:
                break;
        }
    }while(option != 4);
}

/*

// ordenamiento para usar en el ll_sort

int ordenaPorId(void* emp1, void* emp2){
    int retorno=0;
    Employeauxiliare* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1 = (Employee*) emp1;
        p2 = (Employee*) emp2;


        if(p1->id > p2->id)
            retorno = 1;
        else if(p1->id < p2->id)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}
*/
