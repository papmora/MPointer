cmake_minimum_required(VERSION 3.12)
project(MPointer)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(MPointer main.cpp MPointer.h MPointerGC.cpp MPointerGC.h RC.cpp RC.h "Estructuras de Datos/ListaEnlazada.cpp" "Estructuras de Datos/ListaEnlazada.h" "Algoritmos de Ordenamiento/BubbleSort.h" "Estructuras de Datos/ListaDoblementeEnlazada.cpp" "Estructuras de Datos/ListaDoblementeEnlazada.h" "Algoritmos de Ordenamiento/InsertionSort.h" "Algoritmos de Ordenamiento/QuickSort.h" cliente.cpp cliente.h)
