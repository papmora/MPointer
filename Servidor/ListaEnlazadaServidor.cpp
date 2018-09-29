#include <iostream>
#include <string>
#include <stdlib.h>
#include "ListaEnlazadaServidor.h"

using namespace std;

//Funciones de la Lista
//agregar al final
void ListaEnlazada::agregar(Pagina n) {
    auto nuevo_nodo = new nodoSimple();
    nuevo_nodo->dato = n;

    nodoSimple *cola = cabeza;

    if ( cabeza == nullptr ) {
        cabeza = nuevo_nodo;
    } else {
        while (cola->siguiente != nullptr) {
            cola = cola->siguiente;
        }
        cola->siguiente = nuevo_nodo;
    }

}

//recorrer lista para imprimir
void ListaEnlazada::mostrar() {
    nodoSimple *temp = cabeza;
    while (temp != nullptr) {
        cout << "[El ID es : " + to_string(temp->dato.id) + ", El lenght es: " +
                to_string(temp->dato.lenght) + ", El offset es: "
             << temp->dato.offset << "]" << "\n";

        temp = temp->siguiente;
    }
}

//buscar en lista
int ListaEnlazada::buscar(int n) {
    bool band = false;
    nodoSimple *temp = cabeza;
    while (temp != nullptr) {
        if ( temp->dato.id == n ) {
            band = true;
            break;
        }
        temp = temp->siguiente;

    }
    if ( band ) {
        return temp->dato.lenght;

    } else {
        return -1;
    }

}

//eliminar elemento de lista
/*void eliminar(Nodo *&cabeza, int dato) {
    if ( cabeza != nullptr ) {
        Nodo *temp_borrar;
        temp_borrar = cabeza;

        while ((temp_borrar != nullptr) && (temp_borrar->dato.id != dato)) {
            temp_borrar = temp_borrar->siguiente;

        }
        if ( temp_borrar == nullptr ) {
            cout << "elemento no se encuentra \n";

        } else {
            temp_borrar->dato.id = 0;
        }


    } else {
        cout << "la lista esta vacia";
    }
}*/