//
// Created by pablo on 24/09/18.
//

#ifndef PROYECTO1_MPOINTERGC_H
#define PROYECTO1_MPOINTERGC_H

#include <iostream>
#include <string>
#include "Estructuras de Datos/ListaEnlazada.h"

typedef ListaEnlazada LE;

class MPointerGC {
private:
    static MPointerGC MP;
    static LE lista;
    static int id;

    MPointerGC();

public:
    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator = (const MPointerGC&) = delete;

    ~MPointerGC();

    static void agregarDirecciones(int* dir);
    static MPointerGC& getInstance();
    static LE getLista();
    static int getId();
};


#endif //PROYECTO1_MPOINTERGC_H
