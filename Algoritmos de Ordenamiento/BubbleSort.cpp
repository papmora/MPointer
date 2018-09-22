//
// Created by davepj007 on 20/09/18.
//

#include "BubbleSort.h"
#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"
#include <iostream>
#include <stdlib.h>

typedef ListaDoblementeEnlazada LDE;

void BubbleSort::swapping(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void BubbleSort::bubbleSort(LDE lde) {
    LDE::nodoDoble *ptr, *temp;

    if(lde.cabeza == NULL || lde.cabeza->siguiente == NULL) {
        return;
    }
    int swapped = 1;

    while(swapped){
        swapped = 0;
        ptr = lde.cabeza;
        while(ptr->siguiente != NULL){
            if(ptr->dato > ptr->siguiente->dato){
                swapped = 1;
                swapping(&ptr->dato, &ptr->siguiente->dato);
            }
            ptr = ptr->siguiente;
        }
    }
}