//
// Created by davepj007 on 22/09/18.
//

#ifndef MPOINTER_INSERTIONSORT_H
#define MPOINTER_INSERTIONSORT_H

#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"

class InsertionSort {
public:
    typedef ListaDoblementeEnlazada::nodoDoble nodoD;

    template <class T> static void insertionSort(ListaDoblementeEnlazada LDE){
        nodoD *i, *j;
        int* dato;
        for (i = LDE.cabeza->siguiente; i != NULL ; i = i->siguiente) {
            dato = ((MPointer<T>*)i->dato)->getPDato();
            j = i->anterior;

            while(j != NULL && *((MPointer<T>*)j->dato)->getPDato() > *dato){
                ((MPointer<T>*)j->siguiente->dato)->setPDato(((MPointer<T>*)j->dato)->getPDato());
                j = j->anterior;
            }

            if(j != NULL) ((MPointer<T>*)j->siguiente->dato)->setPDato(dato);
            else ((MPointer<T>*)LDE.cabeza->dato)->setPDato(dato);
        }
    }
};


#endif //MPOINTER_INSERTIONSORT_H
