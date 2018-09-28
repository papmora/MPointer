//
// Created by davepj007 on 22/09/18.
//

#include "QuickSort.h"
#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"

void QuickSort::swapping(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

nodoD* QuickSort::partition(nodoD* bajo, nodoD* alto) {
    int pivot = *alto->dato;
    nodoD* i = bajo->anterior;

    for (nodoD* j = bajo; j != alto ; j = j->siguiente) {
        if(*j->dato <= pivot){
            i = (i == NULL)? bajo : i->siguiente;
            swapping(i->dato, j->dato);
        }
    }
    i = (i == NULL)? bajo : i->siguiente; // Similar to i++
    swapping((i->dato), (alto->dato));
    return i;
}

void QuickSort::recQuickSort(nodoD* bajo, nodoD* alto) {
    if(alto != NULL && bajo != alto && bajo != alto->siguiente){
        nodoD* p = partition(bajo, alto);
        recQuickSort(bajo,p->anterior);
        recQuickSort(p->siguiente, alto);
    }
}

void QuickSort::quickSort(LDE lde) {
    nodoD* cbza = lde.cabeza;
    nodoD* ultN = ListaDoblementeEnlazada::lastNode(cbza);
    recQuickSort(cbza, ultN);
}