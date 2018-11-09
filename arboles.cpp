/* ******************ARBOL BINARIO****************** */

class Abin{
	struct celda;
	public:
		typedef celda* nodo;
		static const nodo NODO_NULO;
		Abin();
		void insertarRaizB(const T& e);
		void insertarHijoIzqdoB(nodo n, const T& e);
		void insertarHijoDrchoB(nodo n, const T& e);
		void eliminarHijoDrchoB(nodo n);
		void eliminarHijoizqdoB(nodo n);
		void eliminarRaizB();
		~Abin();
		bool arbolVacioB() const;
		const T& elemento(nodo n) const;
		T& elemento(nodo n);
		nodo padreB(nodo n) const;
		nodo hijoIzqdoB(nodo n) const;
		nodo hijoDrchoB(nodo n) const;
	private:
		struct celda{
			T elto;
			nodo padre, hizq, hder;
			celda(const T& e,nodo p = NODO_NULO): elto(e),padre(p),hizq(NODO_NULO);
		}


	
};





/****************ARBOLES GENERALES*****************/


class Agen{
	Agen();
	void insertarRaiz(const T& e);
	void insertarHijoIzqdo(nodo n, const T& e);
	void insertarHijoDrcho(nodo n, const T& e);
	void eliminarHijoizqdo(nodo n);
	void eliminarHijoDrchoB(nodo n);
	void eliminarRaiz();
	bool arbolVacio();
	const T& elemento(nodo n) const;
	T& elemento(nodo n);

}
