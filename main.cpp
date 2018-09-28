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

int main() {

    std::cout << "LISTA ENLAZADA SIMPLE: " << std::endl;
    ListaEnlazada LE = ListaEnlazada();
    ListaEnlazada::nodoSimple *cabeza = NULL;
    int v1 = 3;
    LE.agregar(&v1);
    int v2 = 5;
    LE.agregar(&v2);
    int v3 = 8;
    LE.agregar(&v3);
    int v4 = 2;
    LE.agregar(&v4);
    int v5 = 11;
    LE.agregar(&v5);

    std::cout << "Primer iteracion: " << std::endl;
    LE.mostrar();

    LE.buscar((int*) 2);
    LE.buscar((int*) 20);

    LE.eliminar((int*) 8);
    std::cout << "Segunda iteracion: " << std::endl;
    LE.mostrar();

    LE.eliminar((int*) 30);
    std::cout << "Tercera iteracion: " << std::endl;
    LE.mostrar();

    std::cout << "\nLISTA DOBLEMENTE ENLAZADA: " << std::endl;
    ListaDoblementeEnlazada LDE = ListaDoblementeEnlazada();
    int v6 = 7;
    LDE.agregarInicio(&v6);
    int v7 = 9;
    LDE.agregarFinal(&v7);
    int v8 = 24;
    LDE.agregarInicio(&v8);
    int v9 = 12;
    LDE.agregarFinal(&v9);

    std::cout << "Primer iteracion: " << std::endl;
    LDE.mostrar();

    int v10 = 15;
    LDE.agregarEspec(3,&v10);
    int v11 = 22;
    LDE.agregarEspec(2, &v11);
    std::cout << "Segunda iteracion: " << std::endl;
    LDE.mostrar();

    ListaDoblementeEnlazada::nodoDoble* aBorrar = LDE.buscar(&v10);
    LDE.eliminar(aBorrar);

    std::cout << "Tercera iteracion: " << std::endl;
    LDE.mostrar();

    /*BubbleSort BS = BubbleSort();
    BS.bubbleSort(LDE);
    std::cout << "Ordenamiento Burbuja: " << std::endl;
    LDE.mostrar();*/

    /*InsertionSort IS = InsertionSort();
    IS.insertionSort(LDE);
    std::cout << "Ordenamiento por Inserción: " << std::endl;
    LDE.mostrar();*/

    QuickSort QS = QuickSort();
    QS.quickSort(LDE);
    std::cout << "Ordenamiento QuickSort: " << std::endl;
    LDE.mostrar();

// pruebas MPointer
    MPointerGC& mPointerGC = MPointerGC::getInstance();

    MPointer<int> myPtr = MPointer<int>::New();
    MPointer<int> myPtr2 = MPointer<int>::New();

    std::cout<< "" << std::endl;
    std::cout << "Ptr 1: " << &myPtr << std::endl;
    std::cout << "Ptr 2: " << &myPtr2 <<"\n"<< std::endl;

    *myPtr = 5;
    std::cout<< "Nuevo ptr 1: " << &myPtr <<"\n"<< std::endl;

    myPtr2 = 11;
    int y= &myPtr2;
    std::cout << "Y: " << y << std::endl;
    std::cout<< "Nuevo ptr 2: " << &myPtr2<<"\n"<< std::endl;

    myPtr=myPtr2;
    std::cout << "Si se iguala ptr1 = ptr2: " << std::endl;
    std::cout << "Ptr1: " << &myPtr<< std::endl;
    std::cout << "Ptr2: " << &myPtr2 << std::endl;

    std::cout << "\nLista de Direcciones: " << std::endl;
    mPointerGC.getLista().mostrar();
    return 0;
}
