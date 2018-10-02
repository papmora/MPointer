//
// Created by davepj007 on 20/09/18.
//

#ifndef MPOINTER_BUBBLESORT_H
#define MPOINTER_BUBBLESORT_H

#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"

typedef ListaDoblementeEnlazada LDE;

class BubbleSort {
public:
    template <class T> static void bubbleSort(LDE lde){
        LDE::nodoDoble *ptr, *temp;

        if(lde.cabeza == NULL || lde.cabeza->siguiente == NULL) {
            return;
        }
        int swapped = 1;

        while(swapped){
            swapped = 0;
            ptr = lde.cabeza;
            while(ptr->siguiente != NULL){
                if(*((MPointer<T>*)ptr->dato)->getPDato() > *((MPointer<T>*)ptr->siguiente->dato)->getPDato()){
                    swapped = 1;
                    swapping(((MPointer<T>*)ptr->dato)->getPDato(), ((MPointer<T>*)ptr->siguiente->dato)->getPDato());
                }
                ptr = ptr->siguiente;
            }
        }
    }
private:
    static void swapping(int* x, int* y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }
};


#endif //MPOINTER_BUBBLESORT_H
