//
// Created by davepj007 on 21/09/18.
//

#ifndef MPOINTER_LISTADOBLEMENTEENLAZADA_H
#define MPOINTER_LISTADOBLEMENTEENLAZADA_H

#include <stdlib.h>

class ListaDoblementeEnlazada {
public:
    typedef struct Nodo{
        int dato;
        struct Nodo* anterior;
        struct Nodo* siguiente;
    }nodoDoble;

    static nodoDoble *lastNode(nodoDoble *temp){
        while (temp && temp->siguiente)
            temp = temp->siguiente;
        return temp;
    }

    nodoDoble* cabeza = NULL;

    void agregarInicio(int dato);
    void agregarFinal(int dato);
    void agregarEspec(int index, int dato);
    void eliminar(nodoDoble* aBorrar);
    nodoDoble* buscar(int dato);
    void mostrar();
};


#endif //MPOINTER_LISTADOBLEMENTEENLAZADA_H
