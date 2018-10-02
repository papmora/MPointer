//
// Created by pablo on 16/09/18.
//

#include "ListaEnlazada.h"
#include <iostream>
#include <stdlib.h>

void ListaEnlazada::agregar(int* n) {
    nodoSimple *nuevo_nodo = new nodoSimple();
    nuevo_nodo->dato = n;

    nodoSimple *cola;

    if(cabeza == NULL){
        cabeza = nuevo_nodo;
    }
    else{
        cola = cabeza;
        while (cola->siguiente != NULL){
            cola = cola->siguiente;
        }
        cola->siguiente = nuevo_nodo;
    }
}

void ListaEnlazada::buscar(int* n) {
    bool band = false;
    nodoSimple *temp = cabeza;
    while (temp != NULL){
        if(temp->dato == n){
            band = true;
        }
        temp = temp->siguiente;
    }
    if(band == true){
        std::cout<< n <<" "<<"si se encuentra en la lista \n";
    }
    else{
        std::cout<< n <<" " << "no se encuentra en la lista \n";
    }
}

void ListaEnlazada::eliminar(int* dato) {
    if (cabeza != NULL){
        nodoSimple *temp_borrar;
        nodoSimple *temp_anterior=NULL;
        temp_borrar = cabeza;

        while ((temp_borrar != NULL)&&(temp_borrar->dato != dato)){
            temp_anterior = temp_borrar;
            temp_borrar = temp_borrar->siguiente;
        }
        if (temp_borrar == NULL){
            std::cout<<"elemento no se encuentra \n";
        }
            //si es primer elemento en la lista
        else if (temp_anterior == NULL){
            cabeza = cabeza->siguiente;
            delete temp_borrar;
        }
        else{
            temp_anterior->siguiente = temp_borrar->siguiente;
            delete temp_borrar;
        }
    }
    else{
        std::cout<<"la lista esta vacia";
    }
}