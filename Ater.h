#ifndef Ater_H
#define Ater_H
#include <cassert>

template <typename Z> class Ater {
   struct celda; // declaración adelantada privadapublic:
   public: 
    typedef celda* nodo;
    static const nodo NODO_NULO;
    Ater(); // constructor
    void crearRaiz(const Z& e);
    void insertarHijoIzqdo(nodo n, const Z& e);
    void insertarHijoDrcho(nodo n, const Z& e);
    void insertarHijoMedio(nodo n, const Z& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarHijoMedio(nodo n);
    void eliminarRaiz();
    ~Ater(); // destructor
    bool arbolVacio() const;
    Z elemento(nodo n) const; // acceso a elto, lectura
    Z& elemento(nodo n); // acceso a elto, lectura/escritura
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    nodo hijoMedio(nodo n) const;
    
   private:
        struct celda {
           Z elto;
           nodo padre, hizq, hder, hmed;
           celda(const Z& e, nodo p = NODO_NULO): elto(e),
           padre(p), hizq(NODO_NULO), hder(NODO_NULO), hmed(NODO_NULO) {}
        };
        nodo r; // nodo raíz del árbol
        void destruirNodos(nodo& n);
};

/* Definición del nodo nulo */
template <typename Z>
const typename Ater<Z>::nodo Ater<Z>::NODO_NULO(0);

template <typename Z>
inline Ater<Z>::Ater() : r(NODO_NULO) {}

template <typename Z>
inline void Ater<Z>::crearRaiz (const Z& e)
{
 assert(r == NODO_NULO); // árbol vacío
 r = new celda(e);
}

template <typename Z>inline
void Ater<Z>::insertarHijoIzqdo(Ater<Z>::nodo n,const Z& e)
{
 assert(n != NODO_NULO);
 assert(n->hizq == NODO_NULO);// no existe hijo
 n->hizq = new celda(e, n);
}

template <typename Z> inline
void Ater<Z>::insertarHijoDrcho(Ater<Z>::nodo n, const Z& e)
{
 assert(n != NODO_NULO);
 assert(n->hder == NODO_NULO); // no existe hijo
 n->hder = new celda(e, n);
}

template <typename Z> inline
void Ater<Z>::insertarHijoMedio(Ater<Z>::nodo n, const Z& e)
{
 assert(n != NODO_NULO);
 assert(n->hmed == NODO_NULO); // no existe hijo
 n->hmed = new celda(e, n);
}

template <typename Z>
inline void Ater<Z>::eliminarHijoIzqdo(Ater<Z>::nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hizq != NODO_NULO); // existe hijo izqdo.
    assert(n->hizq->hizq == NODO_NULO && // hijo izqdo.
    n->hizq->hder == NODO_NULO && n->hizq->hmed==NODO_NULO); // es hoja
    delete(n->hizq);
    n->hizq = NODO_NULO;
}

template <typename Z>
inline void Ater<Z>::eliminarHijoDrcho(Ater<Z>::nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hder != NODO_NULO); // existe hijo drcho.
    assert(n->hder->hizq == NODO_NULO && // hijo drcho.
    n->hder->hder == NODO_NULO && n->hizq->hmed==NODO_NULO); // es hoja
    delete(n->hder);
    n->hder = NODO_NULO;
}

template <typename Z>
inline void Ater<Z>::eliminarHijoMedio(Ater<Z>::nodo n)
{
    assert(n != NODO_NULO);
    assert(n->hmed != NODO_NULO); // existe hijo drcho.
    assert(n->hmed->hizq == NODO_NULO && // hijo drcho.
    n->hmed->hder == NODO_NULO && n->hmed->hmed==NODO_NULO); // es hoja
    delete(n->hmed);
    n->hmed = NODO_NULO;
}

template <typename Z>
inline void Ater<Z>::eliminarRaiz()
{
    assert(r != NODO_NULO); // árbol no vacío
    assert(r->hizq == NODO_NULO &&
    r->hder == NODO_NULO && r->hmed==NODO_NULO); // la raíz es hoja
    delete(r);
    r = NODO_NULO;
}

template <typename Z> inline Ater<Z>::~Ater()
{
destruirNodos(r); // vacía el árbol
}

template <typename Z> inline bool Ater<Z>::arbolVacio() const
{ return (r == NODO_NULO); }

template <typename Z>
inline Z Ater<Z>::elemento(Ater<Z>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename Z>
inline Z& Ater<Z>::elemento(Ater<Z>::nodo n)
{
    assert(n != NODO_NULO);
    return n->elto;
}

template <typename Z>
inline typename Ater<Z>::nodo Ater<Z>::raiz() const
{
return r;
}

template <typename Z> inline
typename Ater<Z>::nodo Ater<Z>::padre(Ater<Z>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->padre;
}

template <typename Z> inline
typename Ater<Z>::nodo Ater<Z>::hijoIzqdo(Ater<Z>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->hizq;
}

template <typename Z> inline
typename Ater<Z>::nodo Ater<Z>::hijoDrcho(Ater<Z>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->hder;
}

template <typename Z> inline
typename Ater<Z>::nodo Ater<Z>::hijoMedio(Ater<Z>::nodo n) const
{
    assert(n != NODO_NULO);
    return n->hmed;
}

template <typename Z>
void Ater<Z>::destruirNodos(Ater<Z>::nodo& n)
{
    if (n != NODO_NULO) {
        destruirNodos(n->hizq);
        destruirNodos(n->hmed);
        destruirNodos(n->hder);
        delete n;
        n = NODO_NULO;
    }
}

#endif
