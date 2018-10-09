//
// Created by pablo on 24/09/18.
//
#include <thread>
#include <chrono>
#include <iostream>
#include "cliente.h"

#include "Estructuras de Datos/ListaEnlazada.h"
#include "MPointerGC.h"

using namespace std;

MPointerGC MPointerGC::MP;
LE MPointerGC::lista;
LDE MPointerGC::listaD;
int MPointerGC::id;

MPointerGC::MPointerGC(){
    lista = LE();
    listaD = LDE();
    id = 0;
}

MPointerGC::~MPointerGC() {
}

void MPointerGC::agregarDirecciones(int* dir) {
    lista.agregar(dir);
    listaD.agregarFinal(dir);
}

MPointerGC& MPointerGC::getInstance() {
    cliente socket;
    cout << "Ingrese IP del servidor" << endl;
    string ip;
    cin >> ip;
    socket.setServer(ip);
    cout << "Ingrese puerto del servidor" << endl;
    int puerto;
    cin >> puerto;
    socket.setPuerto(puerto);
    return MP;
}

LE MPointerGC::getLista() {
    return lista;
}

LDE MPointerGC::getListaD() {
    return listaD;
}

int MPointerGC::getId() {
    id = id + 1;
    return id;
}