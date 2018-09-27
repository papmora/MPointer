//
// Created by pablo on 21/09/18.
//

#ifndef PROYECTO1_MPOINTER_H
#define PROYECTO1_MPOINTER_H

#include <iostream>
#include <typeinfo>
#include "MPointerGC.h"

using namespace std;

template <class T>
class MPointer {
private:
    T* PDato= new T; //puntero del dato que se va a usar
    int ID;

public:
    typedef T element_type;
public:
    //Constructor de la clase MPointer
    explicit MPointer(T *dato) throw() {
        if (PDato) {
            PDato = dato;
        }
        else{
            PDato=NULL;
        }
    }



    //Destructor de la clase MPointer
    ~MPointer(){
        if (PDato){
            delete(PDato);
        }

    }


    T operator & (){
        return *getPDato();

    }


    T& operator* (){
        return *PDato ;

    }


    void operator = ( MPointer<T> &MP){

        MP.ID=this->ID;
        MP.PDato=this->PDato;


    }

    void operator = (T t){

        *PDato=t;


    }

    void operator =(const T* t){
        this->setPDato(t);
    }




    void New(){
        //agregar direccion de memoria (int) a la lista de MPointerGC
        //malloc para MPointer size of T



    }

    T *getPDato() const {
        return PDato;
    }

    void setPDato(T *PDato) {
        MPointer::PDato = PDato;
    }


};


#endif //PROYECTO1_MPOINTER_H