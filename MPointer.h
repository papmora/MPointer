//
// Created by pablo on 21/09/18.
//

#ifndef MPOINTER_MPOINTER_H
#define MPOINTER_MPOINTER_H

#include <iostream>
#include <typeinfo>

#include "MPointerGC.h"
#include "RC.h"

template <class T>
class MPointer {
private:
    int ID;
    T* PDato= new T; ///puntero del dato que se va a usar
    RC* reference; /// puntero de contador de referencias

public:
    ///Constructor por defecto
    MPointer() : ID(0), PDato(new T), reference(NULL) {
        /// Crea nueva referencia
        reference = new RC();
        /// Incrementa el conteo de referencias
        reference->AddRef();
    }

    ///Constructor con datos
    MPointer(T* pValue) : ID(this->getID()), PDato(pValue), reference(0) {
        /// Crea nueva referencia
        reference = new RC();
        /// Incrementa el conteo de referencias
        reference->AddRef();
    }

    ///Constructor copia
    MPointer(const MPointer<T>& sp) : ID(sp.getID()), PDato(sp.PDato), reference(sp.reference)
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
    T& operator * (){
        return *PDato ;
    }
    ///sobre carga del operador = (igualdad de MPointer)
    MPointer<T>& operator = ( MPointer<T> &MP){
        // Operador de asignacion
       if (*this->PDato != &MP) { // Evita que se asigne el mismo dato
           // Decrementa el contador de referencias
           // si la referencia se vuelve cero borra el dato
           if (reference->Release() == 0) {
               delete PDato;
               delete reference;
           }
           // copia el dato y la referencia al puntero
           // e incrementa el contador de referencias
           this->PDato=MP.PDato;
           reference->AddRef();
       }
       return *this;
    }

    ///sobre carga del operador = (igualdad entre Mpointer y tipo T) guarda dato en espacio
    void operator =(const T t){
        *PDato=t;
    }

    ///sobre carga del operador = (igualdad entre *Mpointer y tipo T) guarda dato en espacio
    void operator =(T* t){
        std::cout << "HEY!" << std::endl;
        this->setPDato(t);
    }

    ///Metodo New para crear MPointer
    static MPointer<T> New(){
        MPointer<T>* ptr = new MPointer<T>();

        MPointerGC::agregarDirecciones((int*) ptr);
        int id = MPointerGC::getId();
        ptr->setID(id);
        return *ptr;
    }

    ///Metodo get de PDato
    T *getPDato() const {
        return PDato;
    }

    ///Metodo set de PDato
    void setPDato(T *PDato) {
        std::cout << "HEY!" << std::endl;
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


#endif //MPOINTER_MPOINTER_H