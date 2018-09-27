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
    ListaEnlazada::tipoNodo *cabeza = NULL;
    LE.agregar(cabeza, 3);
    LE.agregar(cabeza, 5);
    LE.agregar(cabeza, 8);
    LE.agregar(cabeza, 2);
    LE.agregar(cabeza, 11);

    std::cout << "Primer iteracion: " << std::endl;
    LE.mostrar(cabeza);

    LE.buscar(cabeza, 2);
    LE.buscar(cabeza, 20);

    LE.eliminar(cabeza, 8);
    std::cout << "Segunda iteracion: " << std::endl;
    LE.mostrar(cabeza);

    LE.eliminar(cabeza,30);
    std::cout << "Tercera iteracion: " << std::endl;
    LE.mostrar(cabeza);

    std::cout << "\nLISTA DOBLEMENTE ENLAZADA: " << std::endl;
    ListaDoblementeEnlazada LDE = ListaDoblementeEnlazada();
    LDE.agregarInicio(7);
    LDE.agregarFinal(9);
    LDE.agregarInicio(24);
    LDE.agregarFinal(12);

    std::cout << "Primer iteracion: " << std::endl;
    LDE.mostrar();

    LDE.agregarEspec(3, 15);
    LDE.agregarEspec(2, 22);
    std::cout << "Segunda iteracion: " << std::endl;
    LDE.mostrar();

    ListaDoblementeEnlazada::nodoDoble* aBorrar = LDE.buscar(15);
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

// pruebas Mpointer

   MPointer<int> myPtr=MPointer<int>(new int);
    MPointer<int> myPtr2=MPointer<int>(new int);

    cout << &myPtr<< endl;
    cout << &myPtr2 <<"\n"<< endl;


    *myPtr=5;
    cout<< &myPtr<<"\n"<<endl;

    myPtr2=11;
    int y= &myPtr2;
    cout<<y<<endl;
    cout<<&myPtr2<<"\n"<<endl;

    myPtr=myPtr2;
    cout << &myPtr<< endl;
    cout << &myPtr2 <<"\n"<< endl;






    cout<< MPointerGC::getInstance().getBoss()<<endl;

    return 0;
}
