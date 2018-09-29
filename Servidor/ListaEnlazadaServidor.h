#ifndef MPOINTER_LISTAENLAZADA_H
#define MPOINTER_LISTAENLAZADA_H

#include <iostream>
#include <stdlib.h>

class ListaEnlazada {
public:
    typedef struct Pagina {
        int id;
        int *offset;
        int lenght;
    } pagina;

    typedef struct Nodo {
        Pagina dato;
        Nodo *siguiente;
    } nodoSimple;

    nodoSimple *cabeza = nullptr;

    //Agregar al final
    void agregar(pagina n);

    //Imprimir Lista
    void mostrar();

    //Buscar en la lista
    int buscar(int n);
    //Eliminar elemento de la lista
    //void eliminar(pagina* n);
};


#endif //MPOINTER_LISTAENLAZADA_H