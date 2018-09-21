//
// Created by pablo on 16/09/18.
//

#include "ListaEnlazada.h"
#include <iostream>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} nodoSimple;

void ListaEnlazada::agregar(nodoSimple *&cabeza, int n) {
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

void ListaEnlazada::mostrar(nodoSimple *cabeza) {
    nodoSimple *temp = cabeza;
    std::cout << "[";
    while(temp->siguiente != NULL) {
        std::cout << temp->dato << ",";
        temp = temp->siguiente;
    }
    std::cout << temp->dato << "]" << std::endl;
}

void ListaEnlazada::buscar(nodoSimple *cabeza, int n) {
    bool band = false;
    nodoSimple *temp = new nodoSimple();
    temp = cabeza;
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

void ListaEnlazada::eliminar(nodoSimple *&cabeza, int dato) {
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