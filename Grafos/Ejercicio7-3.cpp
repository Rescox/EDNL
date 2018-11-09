#include "alg_grafoPMC.h"
#include "grafoPMC.h"

/* Datos:	
	-Vertice Origen-
	-Cantidad de unidades-
	-Matriz de coste(GrafoP)-
	-Capacidad de cada vertice
	-Porcentaje de subvención
*/
template <typename tCoste>
void distribuirStock(const GrafoP<tCoste>& Ciudades,
	const GrafoP<tCoste>::vertice& origen, unsigned cantidad,
	const vector<double>& SubvPorcentaje,const vector<tCoste>& CapacidadCiudad)
{
	int N =Ciudades.numVert();
	typedef typename GrafoP<tCoste>::vertice vertice;
	//Como vamos a usar Djikstra, ya que el ejercicio
	//habla de que partimos de un nodo origen, debemos
	//crearnos dos vectores, uno para los costes
	//minimos y otro para guardar por la posicion
	//por la que pasan dichos vertices
	vector<tCoste> camMinimo(N,0);
	vector<tCoste> recorridoVertices(N,0);
	vector<unsigned> alamcen(N,);

	camMinimo = Djikstra(Ciudades, origen, recorridoVertices);

	for(size_t i = 0; i<N;i++)
	{
		camMinimo[i] -= camMinimo[i]*SubvPorcentaje[i]; //Vector de costes minimos con su subvencion aplicada
	}
	tCoste costeMinimo;
	size_t j;
	while(cantidad > 0)
	{
		costeMinimo = GrafoP<tCoste>::INFINITO;
		for(size_t i = 0;i<N;i++)
		{
			if(costeMinimo > camMinimo[i] && !alamcen[i])
				j = i;
				costeMinimo = camMinimo[i];
		}
		if(cantidad > CapacidadCiudad[j])
		{
			cantidad = cantidad - CapacidadCiudad[j];
			alamcen[j] = CapacidadCiudad[j];
		}
		else	
			alamcen[j] = cantidad;
			cantidad = 0;

	}



}