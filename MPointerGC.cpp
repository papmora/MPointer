//
// Created by pablo on 24/09/18.
//
#include "MPointerGC.h"
#include "Estructuras de Datos/ListaEnlazada.h"
#include <thread>
#include <chrono>

MPointerGC MPointerGC::MP;
LE MPointerGC::lista;
int MPointerGC::id;

MPointerGC::MPointerGC(){
    lista = LE();
    id = 0;
}

MPointerGC::~MPointerGC() {

}

void MPointerGC::agregarDirecciones(int* dir) {
    lista.agregar(dir);
}

MPointerGC& MPointerGC::getInstance() {
    MP.id += 1;
    return MP;
}

LE MPointerGC::getLista() {
    return lista;
}

int MPointerGC::getId() {
    return id;
}


