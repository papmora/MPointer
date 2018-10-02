//
// Created by davepj007 on 22/09/18.
//

#ifndef MPOINTER_QUICKSORT_H
#define MPOINTER_QUICKSORT_H

#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"

typedef ListaDoblementeEnlazada LDE;
typedef ListaDoblementeEnlazada::nodoDoble nodoD;

class QuickSort {
public:
    template <class T> static void quickSort(LDE lde){
        nodoD* cbza = lde.cabeza;
        nodoD* ultN = ListaDoblementeEnlazada::lastNode(cbza);
        recQuickSort<T>(cbza, ultN);
    }
private:
    static void swapping(int* x, int* y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    template <class T> static nodoD* partition (nodoD* bajo, nodoD* alto){
        int pivot = *((MPointer<T> *) alto->dato)->getPDato();
        nodoD *i = bajo->anterior;
        for (nodoD *j = bajo; j != alto && j->siguiente != NULL; j = j->siguiente) {
            if (*((MPointer<T> *) j->dato)->getPDato() <= pivot) {
                i = (i == NULL) ? bajo : i->siguiente;
                swapping(((MPointer<T> *) i->dato)->getPDato(), ((MPointer<T> *) j->dato)->getPDato());
            }
        }
        i = (i == NULL) ? bajo : i->siguiente; // Similar to i++
        swapping(((MPointer<T> *) i->dato)->getPDato(), ((MPointer<T> *) alto->dato)->getPDato());
        return i;
    }

    template <class T> static void recQuickSort(nodoD* alto, nodoD* bajo) {
        if(alto != NULL && bajo != NULL && bajo != alto && bajo != alto->siguiente){
            nodoD* p = partition<T>(bajo, alto);
            recQuickSort<T>(bajo,p->anterior);
            recQuickSort<T>(p->siguiente, alto);
        }
    }
};


#endif //MPOINTER_QUICKSORT_H
