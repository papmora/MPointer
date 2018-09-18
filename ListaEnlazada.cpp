#include <iostream>
#include <stdlib.h>
using namespace std;

//Estructura del Nodo

struct Nodo{
    int dato;
    Nodo *siguiente;

};

//Funciones de la Lista


//agregar al final
void agregar(Nodo *&cabeza, int n){
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


//recorrer lista para imprimir
 void mostrar(Nodo *cabeza){
    Nodo *temp= new Nodo();
    temp= cabeza;
    while(temp!= NULL) {
        cout << temp->dato << "\n";
        temp = temp->siguiente;
    }

}


//buscar en lista
void buscar(Nodo *cabeza, int n){
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
        cout<< n <<" "<<"si se encuentra en la lista \n";

    }
    else{
        cout<< n<<" " <<"no se encuentra en la lista \n";
    }

}


//eliminar elemento de lista
void eliminar(Nodo *&cabeza, int dato){
    if (cabeza!=NULL){
        Nodo *temp_borrar;
        Nodo *temp_anterior=NULL;
        temp_borrar=cabeza;

        while ((temp_borrar !=NULL)&&(temp_borrar->dato != dato)){
            temp_anterior=temp_borrar;
            temp_borrar=temp_borrar->siguiente;

        }
        if (temp_borrar==NULL){
            cout<<"elemento no se encuentra \n";

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
        cout<<"la lista esta vacia";
    }
}


int main() {

    Nodo *cabeza = NULL;
    agregar(cabeza, 3);
    agregar(cabeza, 5);
    agregar(cabeza, 8);
    agregar(cabeza, 2);
    agregar(cabeza, 11);

    mostrar(cabeza);

    buscar(cabeza, 2);
    buscar(cabeza, 20);

    eliminar(cabeza, 8);
    mostrar(cabeza);
    eliminar(cabeza,30);
    mostrar(cabeza);










}



//
// Created by pablo on 16/09/18.
//

