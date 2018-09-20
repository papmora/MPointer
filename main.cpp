//
// Created by davepj007 on 20/09/18.
//

#include "Estructuras de Datos/ListaEnlazada.h"


int main() {

    ListaEnlazada LE = ListaEnlazada();
    ListaEnlazada::Nodo *cabeza = NULL;
    LE.agregar(cabeza, 3);
    LE.agregar(cabeza, 5);
    LE.agregar(cabeza, 8);
    LE.agregar(cabeza, 2);
    LE.agregar(cabeza, 11);

    LE.mostrar(cabeza);

    LE.buscar(cabeza, 2);
    LE.buscar(cabeza, 20);

    LE.eliminar(cabeza, 8);
    LE.mostrar(cabeza);
    LE.eliminar(cabeza,30);
    LE.mostrar(cabeza);

    return 0;
}