#ifndef ABB_H
#define ABB_H
#include <cassert>


template <typename T> class Abb {
    struct celda; // declaraci�n adelantada privada
    public:
        typedef celda* nodo;
        static const nodo NODO_NULO;
        explicit Abb(nodo n = NODO_NULO); // constructor
        nodo buscar(const T& e) const;
        void insertar(const T& e);
        void eliminar(const T& e);
        bool vacio() const;
        Abb(const Abb<T>& a); // ctor. de copia
        Abb<T>& operator =(const Abb<T>& a); // asig. �rboles
        void transformacion(nodo n,Abin<T>& Bin,typename Abin<T>::nodo t)const;
        operator Abin<T>() const;                    // conversi�n en Abin<T>, esta parece ser la forma de hacerlo.
        ~Abb();
        void poda(const T& e);
   private:
    struct celda {
           T elto;
           nodo hizq, hder;
           celda(const T& e): elto(e),
                       hizq(NODO_NULO), hder(NODO_NULO) {}
    };
    nodo r; // nodo ra�z del �rbol
    T borrarMin(nodo& n);
    nodo copiar(nodo n);
};

/* Definici�n del nodo nulo */
template <typename T>
const typename Abb<T>::nodo Abb<T>::NODO_NULO(0);

template <typename T>
inline Abb<T>::Abb(nodo n) : r(n) {}

template <typename T>
inline bool Abb<T>::vacio() const
{
 return (r == NODO_NULO);
}

template <typename T>
typename Abb<T>::nodo Abb<T>::buscar(const T& e) const
{
    nodo n;
    if (r == NODO_NULO) // �rbol vac�o, e no encontrado
      n = NODO_NULO;
    else if (e == r->elto) // encontrado e en la ra�z
      n = r;
    else if (e < r->elto) { // buscar en sub�rbol izqdo.
        Abb<T> Ai(r->hizq);
        n = Ai.buscar(e);
        Ai.r = NODO_NULO; // impide destruir el sub�rbol izqdo.
    }
    else { // buscar en sub�rbol drcho.
        Abb<T> Ad(r->hder);
        n = Ad.buscar(e);
        Ad.r = NODO_NULO; // impide destruir el sub�rbol drcho.
    }
    return n;
}

template <typename T>
void Abb<T>::insertar(const T& e)
{
    if (r == NODO_NULO) // �rbol vac�o
       r = new celda(e);
    else if (!(e == r->elto)) { // e no est� en la ra�z.
       if (e < r->elto) { // insertar en el sub�rbol izqdo.
            Abb<T> Ai(r->hizq);
            Ai.insertar(e);
            r->hizq = Ai.r;
            Ai.r = NODO_NULO; // impide destruir el sub�rbol drcho.
       }
       else { // insertar en el sub�rbol drcho.
            Abb<T> Ad(r->hder);
            Ad.insertar(e);
            r->hder = Ad.r;
            Ad.r = NODO_NULO; // impide destruir el sub�rbol drcho.
       }
    }
}

template <typename T>
void Abb<T>::eliminar(const T& e)
{
    if (r != NODO_NULO){ // �rbol no vac�o
      if (e == r->elto) { // quitar elemento de la ra�z
        if (r->hizq == NODO_NULO && r->hder == NODO_NULO) {//1.Ra�z es hoja
           delete(r);
           r = NODO_NULO; // el �rbol queda vac�o
        }
        else
          if (r->hder == NODO_NULO) { // 2.Ra�z s�lo tiene hijo izqdo.
            nodo n = r->hizq;
            delete(r);
            r = n; // nueva ra�z el antiguo hijo izqdo.
          }
          else
             if (r->hizq == NODO_NULO) { // 3.Ra�z s�lo tiene hijo drcho.
               nodo n = r->hder;
               delete(r);
               r = n; // nueva ra�z el antiguo hijo drcho.
             }
             else // 4.La ra�z tiene dos hijos.
               r->elto = borrarMin(r->hder); // sustituir el elemento de la
                                        // ra�z por el m�nimo del
                                        // sub�rbol derecho
         }
         else
           if (e < r->elto) {//quitar elemento del sub�rbol izqdo.
             Abb<T> Ai(r->hizq);
             Ai.eliminar(e);
             r->hizq = Ai.r;
             Ai.r = NODO_NULO; // impide destruir el sub�rbol izqdo.
           }
           else { // quitar elemento del sub�rbol drcho.
             Abb<T> Ad(r->hder);
             Ad.eliminar(e);
             r->hder = Ad.r;
             Ad.r = NODO_NULO; // impide destruir el sub�rbol drcho.
          }
    }
}

// M�todo privado
template <typename T>
T Abb<T>::borrarMin(Abb<T>::nodo& n)
// Elimina el nodo que almacena el menor elemento
// del sub�rbol cuya ra�z es n. Devuelve el elemento
// del nodo eliminado
{
    if (n->hizq == NODO_NULO) {
        T e = n->elto;
        nodo m = n->hder;
        delete(n);
        n = m;
        return e;
    }
    else
      return borrarMin(n->hizq);
}

template <typename T>
inline Abb<T>::Abb(const Abb<T>& a)
{
   r = copiar(a.r);
}

template <typename T>
Abb<T>& Abb<T>::operator =(const Abb<T>& a)
{
    if (this != &a) { // evitar autoasignaci�n
       this->~Abb(); // vaciar el �rbol
       r = copiar(a.r);
    }
    return *this;
}

template <typename T>
Abb<T>::operator Abin<T>() const
{
   Abin<T> S;
   typename Abin<T>::nodo t=S.raizB();
   if(r!=NODO_NULO){
      S.crearRaizB(r->elto);
      transformacion(r,S,t);
   }
   return S;
}

template <typename T>
void Abb<T>::transformacion(Abb<T>::nodo n,Abin<T>& Bin,typename Abin<T>::nodo t)const{
           if(n->hizq!=NODO_NULO){
              Bin.insertarHijoIzqdoB(Bin.hijoIzqdoB(t),n->hizq->elto);
              transformacion(n->hizq,Bin,Bin.hijoIzqdoB(t));
           }
           if(n->hder!=NODO_NULO){
              Bin.insertarHijoDrchoB(Bin.hijoDrchoB(t),n->hder->elto);
              transformacion(n->hder,Bin,Bin.hijoDrchoB(t));
           }
}

template <typename T>
inline Abb<T>::~Abb()
{
    if (r != NODO_NULO) { // �rbol no vac�o
        Abb<T> Ai(r->hizq),
               Ad(r->hder);
        delete r;
    }
}


// M�todo privado
template <typename T>
typename Abb<T>::nodo Abb<T>::copiar(Abb<T>::nodo n)
// Devuelve una copia del nodo n y todos sus descendientes
{
    nodo m = NODO_NULO;
    if (n != NODO_NULO) {
        m = new celda(n->elto); // copiar n
        m->hizq = copiar(n->hizq); // copiar sub�rbol izqdo.
        m->hder = copiar(n->hder); // copiar sub�rbol drcho.
    }
    return m;
}

template <typename T>
void Abb<T>::poda(const T& e)
{
    nodo m= buscar(e);
    while(m!=NODO_NULO)
       eliminar(e);
}



#endif // ABB_H
