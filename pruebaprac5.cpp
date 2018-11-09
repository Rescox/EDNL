#include <cassert>
#include <iostream>
#include "Abin.h"
#include "ABB.h"
#include "esAbin.h"


int main(){
    Abb<char> Arbol;
    int ele;
    std::cout<<"arbolito:"<<std::endl;
    std::cout<<"introduzca elemento"<<std::endl;
    std::cin>>ele;
    Arbol.insertar(ele);
    Abin<char> A(Arbol);
    std::cout<<"arbol A:"<<std::endl;
    leerAbin(A);
    imprimirAbin(A);

    std::cout<<"arbol B:"<<std::endl;
    //leerAbin(B);
    //imprimirAbin(B);
    system("pause");
    return 0;
}
