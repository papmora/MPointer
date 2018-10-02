//
// Created by pablo on 16/09/18.
//

#ifndef MPOINTER_LISTAENLAZADA_H
#define MPOINTER_LISTAENLAZADA_H
#include <iostream>
#include <stdlib.h>


template <class T> class MPointer;

class ListaEnlazada {

public:
    typedef struct Nodo {
        int* dato;
        struct Nodo *siguiente;
    } nodoSimple;

    nodoSimple* cabeza = NULL;

    //Agregar al final
    void agregar(int* n);

    //Imprimir Lista
    template <class T> void mostrar(){
        nodoSimple *temp = cabeza;
        std::cout << "[";
        while(temp->siguiente != NULL) {
            std::cout << *((MPointer<T>*)temp->dato)->getPDato() << ",";
            temp = temp->siguiente;
        }
        std::cout << *((MPointer<T>*)temp->dato)->getPDato() << "]" << std::endl;
    }

    //Buscar en la lista
    void buscar(int* n);
    //Eliminar elemento de la lista
    void eliminar(int* dato);
};


#endif //MPOINTER_LISTAENLAZADA_H
