//
// Created by pablo on 16/09/18.
//

#include "ListaEnlazada.h"
#include <iostream>
#include <stdlib.h>

void ListaEnlazada::agregar(ListaEnlazada::Nodo *&cabeza, int n) {
    Nodo *nuevo_nodo= new Nodo();
    nuevo_nodo->dato =n;

    Nodo *cola= new Nodo();

    if(cabeza==NULL){
        cabeza= nuevo_nodo;
    }
    else{
        cola=cabeza;
        while (cola->siguiente!=NULL){
            cola= cola->siguiente;

        }
        cola->siguiente=nuevo_nodo;
    }
}

void ListaEnlazada::mostrar(ListaEnlazada::Nodo *cabeza) {
    Nodo *temp= new Nodo();
    temp= cabeza;
    while(temp!= NULL) {
        std::cout << temp->dato << "\n";
        temp = temp->siguiente;
    }
}

void ListaEnlazada::buscar(ListaEnlazada::Nodo *cabeza, int n) {
    bool band= false;
    Nodo *temp= new Nodo();
    temp=cabeza;
    while (temp!=NULL){
        if(temp->dato==n){
            band= true;
        }
        temp=temp->siguiente;
    }
    if(band==true){
        std::cout<< n <<" "<<"si se encuentra en la lista \n";
    }
    else{
        std::cout<< n<<" " <<"no se encuentra en la lista \n";
    }
}

void ListaEnlazada::eliminar(ListaEnlazada::Nodo *&cabeza, int dato) {
    if (cabeza!=NULL){
        Nodo *temp_borrar;
        Nodo *temp_anterior=NULL;
        temp_borrar=cabeza;

        while ((temp_borrar !=NULL)&&(temp_borrar->dato != dato)){
            temp_anterior=temp_borrar;
            temp_borrar=temp_borrar->siguiente;
        }
        if (temp_borrar==NULL){
            std::cout<<"elemento no se encuentra \n";
        }
            //si es primer elemento en la lista
        else if (temp_anterior==NULL){
            cabeza=cabeza->siguiente;
            delete temp_borrar;
        }
        else{
            temp_anterior->siguiente=temp_borrar->siguiente;
            delete temp_borrar;
        }
    }
    else{
        std::cout<<"la lista esta vacia";
    }
}