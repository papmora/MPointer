//
// Created by pablo on 24/09/18.
//

#include "MPointerGC.h"
#include "ListaEnlazada.h"
#include <thread>
#include <chrono>





MPointerGC MPointerGC::MP;



MPointerGC::MPointerGC(): boss("pap")
{


}

MPointerGC::~MPointerGC() {
    existe= false;

}

MPointerGC& MPointerGC::getInstance() {
    return MP;

    //while (existe==true){

        //std::this_thread::sleep_for (std::chrono::seconds(1));



}

std::string MPointerGC::getBoss() {

    return boss;
}


