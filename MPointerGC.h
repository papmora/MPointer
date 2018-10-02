//
// Created by pablo on 24/09/18.
//

#ifndef MPOINTER_MPOINTERGC_H
#define MPOINTER_MPOINTERGC_H

#include <iostream>
#include <string>

#include "Estructuras de Datos/ListaEnlazada.h"
#include "Estructuras de Datos/ListaDoblementeEnlazada.h"

typedef ListaEnlazada LE;
typedef ListaDoblementeEnlazada LDE;

template <class T> class MPointer;

class MPointerGC {
private:
    static MPointerGC MP;
    static LE lista;
    static LDE listaD;
    static int id;

    MPointerGC();
public:
    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator = (const MPointerGC&) = delete;

    ~MPointerGC();
    static void agregarDirecciones(int* dir);

    static MPointerGC& getInstance();
    static LE getLista();
    static LDE getListaD();
    static int getId();
};


#endif //MPOINTER_MPOINTERGC_H
