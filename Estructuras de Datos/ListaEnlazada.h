//
// Created by pablo on 16/09/18.
//

#ifndef MPOINTER_LISTAENLAZADA_H
#define MPOINTER_LISTAENLAZADA_H
#include <iostream>
#include <stdlib.h>

class ListaEnlazada {
public:
    typedef struct Nodo tipoNodo;

    //Agregar al final
    void agregar(tipoNodo *&cabeza, int n);
    //Imprimir Lista
    void mostrar(tipoNodo *cabeza);
    //Buscar en la lista
    void buscar(tipoNodo *cabeza, int n);
    //Eliminar elemento de la lista
    void eliminar(tipoNodo *&cabeza, int dato);
};


#endif //MPOINTER_LISTAENLAZADA_H
