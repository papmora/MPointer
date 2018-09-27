//
// Created by pablo on 24/09/18.
//

#ifndef PROYECTO1_MPOINTERGC_H
#define PROYECTO1_MPOINTERGC_H

#include <iostream>
#include <string>
#include "ListaEnlazada.h"

class MPointerGC {
    static MPointerGC MP;
    std::string boss;
    bool existe=true;

    MPointerGC();

public:
    MPointerGC(const MPointerGC&)= delete;
    MPointerGC& operator =(const MPointerGC&)= delete;

    ~MPointerGC();

    static MPointerGC& getInstance();
    std::string getBoss();




};


#endif //PROYECTO1_MPOINTERGC_H
