//
// Created by davepj007 on 21/09/18.
//

#ifndef MPOINTER_LISTADOBLEMENTEENLAZADA_H
#define MPOINTER_LISTADOBLEMENTEENLAZADA_H

#include <iostream>
#include <stdlib.h>

template <class T> class MPointer;

class ListaDoblementeEnlazada {
public:
    typedef struct Nodo{
        int* dato;
        struct Nodo* anterior;
        struct Nodo* siguiente;
    }nodoDoble;

    static nodoDoble *lastNode(nodoDoble *temp){
        while (temp && temp->siguiente)
            temp = temp->siguiente;
        return temp;
    }

    nodoDoble* cabeza = NULL;

    void agregarInicio(int* dato);
    void agregarFinal(int* dato);
    void agregarEspec(int index, int* dato);
    void eliminar(nodoDoble* aBorrar);
    nodoDoble* buscar(int* dato);

    template <class T> void mostrar(){
        nodoDoble* temp = cabeza;
        std::cout << "[";
        while(temp->siguiente != NULL){
            std::cout << *((MPointer<T>*)temp->dato)->getPDato() << ",";
            temp = temp->siguiente;
        }
        std::cout << *((MPointer<T>*)temp->dato)->getPDato() << "]" << std::endl;
    }
};


#endif //MPOINTER_LISTADOBLEMENTEENLAZADA_H
