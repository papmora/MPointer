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
    void quickSort(LDE lde);
private:
    void swapping(int* x, int* y);
    nodoD* partition (nodoD* bajo, nodoD* alto);
    void recQuickSort(nodoD* izq, nodoD* der);
};


#endif //MPOINTER_QUICKSORT_H
