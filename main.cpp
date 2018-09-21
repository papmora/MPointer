//
// Created by davepj007 on 20/09/18.
//

#include "Estructuras de Datos/ListaEnlazada.h"
#include "Estructuras de Datos/ListaDoblementeEnlazada.h"

int main() {

    std::cout << "LISTA ENLAZADA SIMPLE: " << std::endl;
    ListaEnlazada LE = ListaEnlazada();
    ListaEnlazada::tipoNodo *cabeza = NULL;
    LE.agregar(cabeza, 3);
    LE.agregar(cabeza, 5);
    LE.agregar(cabeza, 8);
    LE.agregar(cabeza, 2);
    LE.agregar(cabeza, 11);

    std::cout << "Primer iteracion: " << std::endl;
    LE.mostrar(cabeza);

    LE.buscar(cabeza, 2);
    LE.buscar(cabeza, 20);

    LE.eliminar(cabeza, 8);
    std::cout << "Segunda iteracion: " << std::endl;
    LE.mostrar(cabeza);

    LE.eliminar(cabeza,30);
    std::cout << "Tercera iteracion: " << std::endl;
    LE.mostrar(cabeza);

    std::cout << "LISTA DOBLEMENTE ENLAZADA: " << std::endl;
    ListaDoblementeEnlazada LDE = ListaDoblementeEnlazada();
    LDE.agregarInicio(12);
    LDE.agregarInicio(7);
    LDE.agregarInicio(9);
    LDE.agregarInicio(24);

    std::cout << "Primer iteracion: " << std::endl;
    LDE.mostrar();

    LDE.agregarEspec(3, 15);
    LDE.agregarEspec(2, 22);
    std::cout << "Segunda iteracion: " << std::endl;
    LDE.mostrar();

    ListaDoblementeEnlazada::tipoNodo* aBorrar = LDE.buscar(15);
    LDE.eliminar(aBorrar);

    std::cout << "Tercera iteracion: " << std::endl;
    LDE.mostrar();

    return 0;
}