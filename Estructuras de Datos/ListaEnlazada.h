//
// Created by pablo on 16/09/18.
//

#ifndef MPOINTER_LISTAENLAZADA_H
#define MPOINTER_LISTAENLAZADA_H
#include <iostream>
#include <stdlib.h>

class ListaEnlazada {
public:
    struct Nodo {
        int dato;
        Nodo *siguiente;
    };

    //Agregar al final
    void agregar(Nodo *&cabeza, int n);
    //Imprimir Lista
    void mostrar(Nodo *cabeza);
    //Buscar en la lista
    void buscar(Nodo *cabeza, int n);
    //Eliminar elemento de la lista
    void eliminar(Nodo *&cabeza, int dato);
};


#endif //MPOINTER_LISTAENLAZADA_H
