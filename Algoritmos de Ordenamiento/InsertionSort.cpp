//
// Created by davepj007 on 22/09/18.
//

#include "InsertionSort.h"
#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"
#include <iostream>

typedef ListaDoblementeEnlazada::nodoDoble nodoD;

void InsertionSort::insertionSort(ListaDoblementeEnlazada LDE) {
    nodoD *i, *j;
    int dato;
    for (i = LDE.cabeza->siguiente; i != NULL ; i = i->siguiente) {
        dato = *i->dato;
        j = i->anterior;

        while(j != NULL && *j->dato > dato){
            *j->siguiente->dato = *j->dato;
            j = j->anterior;
        }

        if(j != NULL) *j->siguiente->dato = dato;
        else *LDE.cabeza->dato = dato;
    }
}