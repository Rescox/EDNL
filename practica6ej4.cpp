
template <typename T>
inline Ater<T>::Ater(const Ater<T>& a)
{ r = copiar(a.r); }

typename Ater<T>::nodo Ater<T>::copiar(Ater<T>::nodo n)
{
    nodo m = NODO_NULO;
    if (n != NODO_NULO) {
        m = new celda(n->elto); // copiar n
        m->hizq = copiar(n->hizq); // copiar subárbol izqdo.
        if (m->hizq != NODO_NULO)
           m->hizq->padre = m;
        m->hmed = copiar(n->hmed); // copiar subárbol medio.
        if (m->hmed != NODO_NULO)
           m->hmed->padre = m;
        m->hder = copiar(n->hder); // copiar subárbol drcho.
        if (m->hder != NODO_NULO)
           m->hder->padre = m;
    }
    return m;
}
