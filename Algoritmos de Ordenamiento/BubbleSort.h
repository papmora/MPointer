//
// Created by davepj007 on 20/09/18.
//

#ifndef MPOINTER_BUBBLESORT_H
#define MPOINTER_BUBBLESORT_H

#include "../Estructuras de Datos/ListaDoblementeEnlazada.h"

typedef ListaDoblementeEnlazada LDE;

class BubbleSort {
public:
    void bubbleSort(LDE lde);
private:
    void swapping(int* x, int* y);
};


#endif //MPOINTER_BUBBLESORT_H
