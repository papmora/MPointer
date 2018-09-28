//
// Created by pablo on 21/09/18.
//

#ifndef PROYECTO1_MPOINTER_H
#define PROYECTO1_MPOINTER_H

#include <iostream>
#include <typeinfo>
#include "MPointerGC.h"

#include "RC.h"

using namespace std;

template <class T>
class MPointer {
private:
    T* PDato= new T; ///puntero del dato que se va a usar
    int ID;

    RC* reference; /// puntero de contador de referencias

public:
    typedef T element_type;
public:

    ///Constructor por defecto
    MPointer() : PDato(NULL), reference(NULL)
    {
        /// Crea nueva referencia
        reference = new RC();
        /// Incrementa el conteo de referencias
        reference->AddRef();
    }

    ///Constructor con datos
    MPointer(T* pValue) : PDato(pValue), reference(0)
    {
        /// Crea nueva referencia
        reference = new RC();
        /// Incrementa el conteo de referencias
        reference->AddRef();
    }

    ///Constructor copia
    MPointer(const MPointer<T>& sp) : PDato(sp.PDato), reference(sp.reference)
    {
        /// Copia el constructor
        /// Copia el PDato y el conteo de referencias
        /// incrementa el conteo de referencias
        reference->AddRef();
    }

    ~MPointer()
    {
        /// Destructor
        /// Disminuye el conteo de referencias
        /// si conteo de refencias es igual a cero, elimina la data
        if(reference->Release() == 0)
        {
            delete PDato;
            delete reference;
        }
    }

///sobre carga del operador &
    T operator & (){
        return *getPDato();

    }

///sobre carga del operador *
    T& operator* (){
        return *PDato ;

    }

///sobre carga del operador = (igualdad de MPointer)
    MPointer<T>& operator = ( MPointer<T> &MP){
        // Assignment operator
       if (*this->PDato != &MP) { // Avoid self assignment

           // Decrement the old reference count
           // if reference become zero delete the old data
           if (reference->Release() == 0) {
               delete PDato;
               delete reference;
           }
           // Copy the data and reference pointer
           // and increment the reference count
           this->ID=MP.ID ;
           this->PDato=MP.PDato;
           reference->AddRef();

       }
       return *this;


    }

///sobre carga del operador = (igualdad entre Mpointer y tipo T) guarda dato en espacio
    void operator = (T t){

        *PDato=t;


    }

    ///sobre carga del operador = (igualdad entre *Mpointer y tipo T) guarda dato en espacio
    void operator =(const T* t){
        this->setPDato(t);
    }




///Metodo New para crear MPointer
    void New(){
        //agregar direccion de memoria (int) a la lista de MPointerGC
        //malloc para MPointer size of T



    }

    ///Metodo get de PDato
    T *getPDato() const {
        return PDato;
    }

    ///Metodo set de PDato
    void setPDato(T *PDato) {
        MPointer::PDato = PDato;
    }

    ///Metodo get de ID
    int getID() const {
        return ID;
    }

    ///Metodo set de ID
    void setID(int ID) {
        MPointer::ID = ID;
    }

    ///Metodo get de conteo de referencias
    RC *getReference() const {
        return reference;
    }

    ///Metodo set de conteo de referencias
    void setReference(RC *reference) {
        MPointer::reference = reference;
    }


};


#endif //PROYECTO1_MPOINTER_H