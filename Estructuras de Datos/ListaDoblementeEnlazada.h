//
// Created by davepj007 on 21/09/18.
//

#ifndef MPOINTER_LISTADOBLEMENTEENLAZADA_H
#define MPOINTER_LISTADOBLEMENTEENLAZADA_H

#include <stdlib.h>

class ListaDoblementeEnlazada {
public:
    typedef struct Nodo tipoNodo;

    tipoNodo* cabeza = NULL;

    void agregarInicio(int dato);
    void agregarFinal(int dato);
    void agregarEspec(int index, int dato);
    void eliminar(tipoNodo* aBorrar);
    tipoNodo* buscar(int dato);
    void mostrar();
};


#endif //MPOINTER_LISTADOBLEMENTEENLAZADA_H
