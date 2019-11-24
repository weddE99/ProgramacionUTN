#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

LinkedList* ll_newLinkedList(void){
    LinkedList* this = NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL){
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

int ll_len(LinkedList* this){
    int returnAux = -1;
    if(this != NULL){
        returnAux = this->size;
    }
    return returnAux;
}

Node* getNode(LinkedList* this, int nodeIndex){
    int i;
    Node *pNode = NULL;
    if(this != NULL && nodeIndex < ll_len(this) && nodeIndex >=0){
        pNode = this->pFirstNode;
        for(i=0; i<nodeIndex; i++){
            pNode = pNode->pNextNode;
        }
    }
    return pNode;
}

Node* test_getNode(LinkedList* this, int nodeIndex){
    return getNode(this, nodeIndex);
}

int addNode(LinkedList* this, int nodeIndex, void* pElement){
    int returnAux = -1;
    Node *pNode = NULL;
    Node *pNodeAnt = NULL;

    if(this != NULL && nodeIndex <= ll_len(this) && nodeIndex >=0){
        pNode = (Node*) malloc(sizeof(Node));
        if(pNode != NULL){
            pNode->pElement = pElement;

            if(nodeIndex == 0){
                if(this->pFirstNode == NULL){
                    pNode->pNextNode = NULL;
                }
                else if(this->pFirstNode != NULL){
                    pNode->pNextNode = this->pFirstNode;
                }
                this->pFirstNode = pNode;
            }
            else{
                pNodeAnt = getNode(this,(nodeIndex-1));
                pNode->pNextNode = pNodeAnt->pNextNode;
                pNodeAnt->pNextNode = pNode;
            }
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}

int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

int ll_add(LinkedList* this, void* pElement){
    int returnAux = -1;
    int nElem = 0;

    if(this != NULL){
        nElem = addNode(this,ll_len(this),pElement);
        if(nElem==0){
            returnAux = 0;
        }
    }
    return returnAux;
}

void* ll_get(LinkedList* this, int index){
    void* returnAux = NULL;
    Node* aux = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
        aux = getNode(this,index);
        if(aux != NULL){
            returnAux = aux->pElement;
        }
    }
    return returnAux;
}

int ll_set(LinkedList* this, int index,void* pElement){
    int returnAux = -1;
    Node* mod = NULL;

    if(this != NULL && index >= 0 && index <= ll_len(this)){
        mod = getNode(this,index);
        if(mod != NULL){
            mod->pElement = pElement;
            returnAux = 0;
        }
    }
    return returnAux;
}

int ll_remove(LinkedList* this,int index){
    int returnAux = -1;
    Node* pNodeAuxS = NULL;
    Node* pNodeAuxA = NULL;
    Node* pNodeAuxActual = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
        pNodeAuxS = getNode(this,index+1);
        pNodeAuxActual = getNode(this,index);
        pNodeAuxA = getNode(this,index-1);

        if(pNodeAuxActual != NULL && pNodeAuxA != NULL){
            pNodeAuxA->pNextNode = pNodeAuxS;
        }
        else{
            this->pFirstNode = pNodeAuxS;
        }
        free(pNodeAuxActual);
        this->size-=1;
        returnAux = 0;
    }
    return returnAux;
}

int ll_clear(LinkedList* this){
    int returnAux = -1;
    int i = 0;

    if(this != NULL){
        for(i=0; i<ll_len(this); i++){
            ll_remove(this,i);
        }
        returnAux = 0;
    }
    return returnAux;
}

int ll_deleteLinkedList(LinkedList* this){
    int returnAux = -1;

    if(this != NULL){
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

int ll_indexOf(LinkedList* this, void* pElement){
    int returnAux = -1;
    int i=0;
    Node* pNode = NULL;

    if(this != NULL){
        do{
            pNode = getNode(this,i);
            if(pNode->pElement == pElement){
                returnAux = 0;
                break;
            }
            i++;
        }while(i<ll_len(this));
    }
    return returnAux;
}

int ll_isEmpty(LinkedList* this){
    int returnAux = -1;
    Node* pNode = NULL;

    if(this != NULL){
        pNode = getNode(this,0);
        if(pNode == NULL){
            returnAux = 1;
        }
        else returnAux = 0;
    }

    return returnAux;
}

int ll_push(LinkedList* this, int index, void* pElement){
    int returnAux = -1;
    int aux = -1;

    if(this != NULL && index >= 0 && index <=ll_len(this)){
        aux = addNode(this,index,pElement);
        if(aux == 0){
            returnAux = 0;
        }
    }

    return returnAux;
}

void* ll_pop(LinkedList* this,int index){
    void* returnAux = NULL;
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index < ll_len(this)){
        pNode = getNode(this,index);
        ll_remove(this,index);
        returnAux = pNode->pElement;
    }

    return returnAux;
}

int ll_contains(LinkedList* this, void* pElement){
    int returnAux = -1;
    int i = 0;

    Node* pNode = NULL;

    if(this != NULL){
        for(i=0; i<=ll_len(this); i++){
            pNode = getNode(this,i);
            if(pNode != NULL && pNode->pElement == pElement){
                returnAux = 1;
                break;
            }
            else{
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

int ll_containsAll(LinkedList* this,LinkedList* this2){
    int returnAux = -1;
    int i = 0;
    Node* pNode = NULL;

    if(this != NULL && this2 != NULL){
        returnAux = 1;
        for(i=0; i<ll_len(this); i++){
            pNode = getNode(this2,i);
            if(ll_contains(this,pNode->pElement) == 0){
                returnAux = 0;
                break;
            }
            i++;
        }
    }
    return returnAux;
}

LinkedList* ll_subList(LinkedList* this, int from, int to){
    LinkedList* clonLl = NULL;
    Node* pNodeAux = NULL;

    int i;
    int aux = 0;

    if (this != NULL && from >= 0 && from <= ll_len(this) && to >= 0 && to <= ll_len(this)){
        clonLl = this;
        clonLl -> size=0;

        for(i=from; i<=to; i++){
            pNodeAux = getNode(this,i);

            if (pNodeAux != NULL){
                aux = addNode(clonLl, i, pNodeAux);

                if (aux == 0){
                    clonLl -> size++;
                }
            }
            else break;
        }
    }
    return clonLl;
}

LinkedList* ll_clone(LinkedList* this){
    LinkedList* clonLl = NULL;

    if(this != NULL){
        clonLl = ll_newLinkedList();
        clonLl = ll_subList(this, 0, ll_len(this));
    }
    return clonLl;
}

int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int returnAux = -1;
    int i, j, aux;
    void* puntero1;
    void* puntero2;
    void* punteroAux;

    if (this != NULL && pFunc != NULL && (order == 0 || order == 1)){
        for (i=0; i<ll_len(this)-1 ;i++){
            for (j=i+1; j<ll_len(this); j++){

                puntero1 = ((void* ) ll_get(this,i));
                puntero2 = ((void* ) ll_get(this,j));

                aux = pFunc(puntero1,puntero2);

                if ((order == 0 && aux == -1) || (order == 1 && aux == 1)){
                    punteroAux = puntero1;
                    ll_set(this, i, puntero2);
                    ll_set(this, j, punteroAux);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*)){
    LinkedList* filterList;

    if(this != NULL && pFunc != NULL){
        filterList = ll_newLinkedList();
        if(filterList != NULL){
            for(int i=0; i<ll_len(this); i++){
                if(pFunc(ll_get(this,i))){
                    ll_add(filterList, ll_get(this, i));
                }
            }
        }
    }
    return filterList;
}

void ll_map(LinkedList* this, void (*pFunc)(void *)){
    int i;

    if( this != NULL && pFunc != NULL ){
        for(i=0; i< ll_len(this) ; i++){
            pFunc(ll_get(this,i));
        }
    }
}
