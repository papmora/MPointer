//
// Created by pablo on 24/09/18.
//
#include <thread>
#include <chrono>

#include "Estructuras de Datos/ListaEnlazada.h"
#include "MPointerGC.h"

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
    MP.id += 1;
    return MP;
}

LE MPointerGC::getLista() {
    return lista;
}

LDE MPointerGC::getListaD() {
    return listaD;
}

int MPointerGC::getId() {
    return id;
}