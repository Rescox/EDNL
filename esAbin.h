#ifndef ESARBOLBINARIO
#define ESARBOLBINARIO
#include <iostream>
template <typename T> void imprimirAbin (const Abin<T>& A);
template <typename T> void imprimirDescendientes(typename Abin<T>::nodo r,const Abin<T>& A);
template <typename T> void leerAbin(Abin<T>& A);
template <typename T> void leerDescendientes(typename Abin<T>::nodo n,Abin<T>& A,T bander);

template <typename T>
void imprimirAbin (const Abin<T>& A)
{
 if (!A.arbolVacioB()) {
    std::cout << "Raiz del arbol: " << A.elemento(A.raizB()) << std::endl;
    imprimirDescendientes(A.raizB(), A);
    }
 else
     std::cout << "arbol vacio\n";
}

template <typename T>
void imprimirDescendientes (typename Abin<T>::nodo r,const Abin<T>& A)
{
 if (A.hijoIzqdoB(r) != Abin<T>::NODO_NULO) {
    std::cout << "Hijo izqdo de " << A.elemento(r) << ": " << A.elemento(A.hijoIzqdoB(r)) << std::endl;
    imprimirDescendientes(A.hijoIzqdoB(r), A);
    }
 if (A.hijoDrchoB(r) != Abin<T>::NODO_NULO) {
    std::cout << "Hijo derecho de " << A.elemento(r) << ": " << A.elemento(A.hijoDrchoB(r)) << std::endl;
    imprimirDescendientes(A.hijoDrchoB(r), A);
 }
}

template <typename T>
void leerAbin(Abin<T>& A)
{
     T bandera,raiz;
     //A.~Abin<T>();   //para usarlo con la implementacion vectorial hay que ponerlo como comentario

         std::cout << "Elija una bandera"<<std::endl;
         std::cin >> bandera;
         std::cout << "Introduzca raiz, si no introduzca "<< bandera <<":"<< std::endl;
         std::cin >> raiz;
         if(raiz!=bandera){
           A.crearRaizB(raiz);
           leerDescendientes(A.raizB(),A,bandera);
         }
}

template <typename T>
void leerDescendientes (typename Abin<T>::nodo n,Abin<T>& A,T bander)
{
     T hizq,hder;
     std::cout << "Introduzca hijo izquierdo de "<< A.elemento(n) <<",si no introduzca "<< bander <<":"<< std::endl;
     std::cin >> hizq;
     if(hizq!=bander){
        A.insertarHijoIzqdoB(n,hizq);
        leerDescendientes(A.hijoIzqdoB(n),A,bander);
     }
     
     std::cout << "Introduzca hijo derecho de "<< A.elemento(n) <<",si no introduzca "<< bander <<":"<< std::endl;
     std::cin >> hder;
     if(hder!=bander){
        A.insertarHijoDrchoB(n,hder);
        leerDescendientes(A.hijoDrchoB(n),A,bander);
     }
     


}

#endif

