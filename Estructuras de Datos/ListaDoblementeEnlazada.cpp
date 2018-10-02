//
// Created by davepj007 on 21/09/18.
//

#include "ListaDoblementeEnlazada.h"
#include <iostream>
#include <stdlib.h>

typedef ListaDoblementeEnlazada LDE;

void LDE::agregarInicio(int* dato) {
    nodoDoble* nuevoNodo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevoNodo->dato = dato;

    if(cabeza == NULL){
        nuevoNodo->siguiente = nuevoNodo->anterior = NULL;
        cabeza = nuevoNodo;
    }
    else{
        nuevoNodo->siguiente = cabeza;
        cabeza->anterior = nuevoNodo;
        nuevoNodo->anterior = NULL;
        cabeza = nuevoNodo;
    }
}

void LDE::agregarFinal(int* dato) {
    nodoDoble* nuevoNodo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevoNodo->dato = dato;

    if(cabeza == NULL){
        nuevoNodo->anterior = nuevoNodo->siguiente = NULL;
        cabeza = nuevoNodo;
    }
    else{
        nodoDoble* cola = cabeza;
        while(cola->siguiente != NULL) cola = cola->siguiente;

        nuevoNodo->anterior = cola;
        cola->siguiente = nuevoNodo;
        nuevoNodo->siguiente = NULL;
    }
}

void LDE::agregarEspec(int index, int* dato) {
    nodoDoble* nuevoNodo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevoNodo->dato = dato;

    if(cabeza == NULL){
        nuevoNodo->anterior = nuevoNodo->siguiente = NULL;
        cabeza = nuevoNodo;
    }
    else{
        nodoDoble* temp = cabeza;
        for (int i = 0; i < index; ++i) {
            temp = temp->siguiente;
        }
        nuevoNodo->siguiente = temp;
        temp->anterior->siguiente = nuevoNodo;
        nuevoNodo->anterior = temp->anterior;
        temp->anterior = nuevoNodo;
    }
}

void LDE::eliminar(nodoDoble* aBorrar) {
    if(cabeza == NULL || aBorrar == NULL) return;

    if(cabeza == aBorrar){
        cabeza = aBorrar->siguiente;
    }
    if(aBorrar->siguiente != NULL){
        aBorrar->siguiente->anterior = aBorrar->anterior;
    }
    if(aBorrar->anterior != NULL){
        aBorrar->anterior->siguiente = aBorrar->siguiente;
    }

    free(aBorrar);
    return;
}

LDE::nodoDoble* LDE::buscar(int* dato) {
    nodoDoble* temp = cabeza;
    while(temp != NULL){
        if(temp->dato == dato){
            std::cout << "Encontrado!" << std::endl;
            return temp;
        }
        temp = temp->siguiente;
    }
    std::cout << "No encontrado!" << std::endl;
    return NULL;
}