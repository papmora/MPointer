//
// Created by pablo on 16/09/18.
//

#ifndef MPOINTER_LISTAENLAZADA_H
#define MPOINTER_LISTAENLAZADA_H
#include <iostream>
#include <stdlib.h>

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
    void mostrar();
    //Buscar en la lista
    void buscar(int* n);
    //Eliminar elemento de la lista
    void eliminar(int* dato);
};


#endif //MPOINTER_LISTAENLAZADA_H
