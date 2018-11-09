#include <iostream>
#include "grafoPMC.h"
#include "matriz.h"


template <typename tCoste>
void viajeMasCaro(const GrafoP<tCoste>& GrafoOfertas)
{
	GrafoP<tCoste> caca(GrafoOfertas.numVert());
	for(int i = 0; i < GrafoOfertas.numVert();i++)
		for(int j = 0; j < GrafoOfertas.numVert();i++)
			caca[i][j] = -GrafoOfertas[i][j];

	
	typedef typename GrafoP<tCoste>::vertice vertice;
	tCoste coste = 0;
	matriz<tCoste> McF(GrafoOfertas.numVert());
	matriz<tCoste> McamF(GrafoOfertas.numVert());

}





/*typedef struct
{
	size_t coste;
	typename GrafoP<tCoste>::vertice origen;
	typename GrafoP<tCoste>::vertice destino;
} viajeWapo;

viajeWapo costeMaxRec(GrafoP<tCoste> G, typename GrafoP<tCoste>::vertice Origen)
{
	size_t maximo = 0;
	typename GrafoP<tCoste>::vertice destino;

	viajeWapo viaje;	

	for(typename GrafoP<tCoste>::vertice v = 0; v < G.numVert(); v++)
	{
		if(G[Origen][j] != GrafoP<tCoste>::INFINITO)
		{
			destino = j;
			maximo = max(maximo, G[Origen][j] + costeMaxRec(G, j).coste);
		}
	}

	viaje.coste = maximo;
	viaje.destino = destino;

	return viaje;
}

viajeWapo ViajeMasCaro(GrafoP<tCoste> G)
{
	typename GrafoP<tCoste>::vertice i;

	viajeWapo viajeMax;

	viajeMax.coste = 0;

	for (i = 0; i < G.numVert(); i++)
	{
		if(costeMaxRec(G, i).coste > viajeMax.coste)
		{
			viajeMax = costeMaxRec(G, i)
			viajeMax.origen = i;
		}
	}

	return viajeMax;
}*/