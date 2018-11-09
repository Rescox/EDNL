
int cuentanodos(const Abb<T>& A)
{
	return cuentanodosRec(A);
}

int cuentanodosRec(const Abb<T>& A)
{
	if(Abb.vacio())
		return 0;
	else
		return	1+cuentanodosRec(A.izqdo())+cuentanodosRec(A.drcho());

}

Abb ordenarAbb(Abb<T> A)
{
	int vectorArbol[cuentanodos(A)];

	if(A.vacio())
		return *this;
	else
		return ordenarAbbRec(vectorArbol,A);
}

int* obtenerLista(int vectorArbol, Abb<T> A)
{
	if(A.drcho().vacio() && A.izqdo().vacio())
		

}
