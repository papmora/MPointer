//
// Created by davepj007 on 20/09/18.
//

#include "Estructuras de Datos/ListaEnlazada.h"
#include "Estructuras de Datos/ListaDoblementeEnlazada.h"
#include "Algoritmos de Ordenamiento/BubbleSort.h"
#include "Algoritmos de Ordenamiento/InsertionSort.h"
#include "Algoritmos de Ordenamiento/QuickSort.h"
#include "MPointer.h"
#include "MPointerGC.h"

typedef ListaDoblementeEnlazada LDE;
typedef ListaEnlazada LE;

int main() {

    ///Pruebas MPointer
    MPointerGC& mPointerGC = MPointerGC::getInstance();

    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();
    MPointer<int> myPtr3 = MPointer<int>::New();
    MPointer<int> myPtr4 = MPointer<int>::New();

    std::cout<< "" << std::endl;
    std::cout << "Ptr 1: " << &myPtr << std::endl;
    std::cout << "Ptr 2: " << &myPtr2 << std::endl;
    std::cout << "Ptr 3: " << &myPtr3 << std::endl;
    std::cout << "Ptr 4: " << &myPtr4 <<"\n"<< std::endl;

    *myPtr = 5;
    std::cout<< "Nuevo ptr 1: " << &myPtr <<"\n"<< std::endl;

    myPtr2 = 11;
    int y= &myPtr2;
    std::cout << "Y: " << y << std::endl;
    std::cout<< "Nuevo ptr 2: " << &myPtr2 <<"\n"<< std::endl;

    *myPtr3 = 7;
    std::cout<< "Nuevo ptr 3: " << &myPtr3 <<"\n"<< std::endl;

    *myPtr4 = 3;
    std::cout<< "Nuevo ptr 4: " << &myPtr4 <<"\n"<< std::endl;

    /*myPtr=myPtr2;
    std::cout << "Si se iguala ptr1 = ptr2: " << std::endl;
    std::cout << "Ptr1: " << &myPtr<< std::endl;
    std::cout << "Ptr2: " << &myPtr2 << std::endl;*/



    LE le = mPointerGC.getLista();
    LDE lde = mPointerGC.getListaD();

    std::cout << "\nLISTA DE DIRECCIONES: " << std::endl;
    std::cout << "LE: ";
    le.mostrar<int>();
    std::cout << "LDE: ";
    lde.mostrar<int>();

    //BubbleSort::bubbleSort<int>(lde);
    //InsertionSort::insertionSort<int>(lde);
    QuickSort::quickSort<int>(lde);
    std::cout << "LDE Ordenada: ";
    lde.mostrar<int>();

    std::cout << "\nID's: " << std::endl;
    std::cout << "ID myPtr: " << myPtr.getID() << std::endl;
    std::cout << "ID myPtr2: " << myPtr2.getID() << std::endl;
    std::cout << "ID myPtr3: " << myPtr3.getID() << std::endl;
    std::cout << "ID myPtr4: " << myPtr4.getID() << std::endl;
    return 0;
}
