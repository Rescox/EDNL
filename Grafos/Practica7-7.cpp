#include "alg_grafoPMC.h"
#include "grafoPMC"


template <typename tCoste>
vector <tCoste> taxistasCabrones(const GrafoP<tCoste>& grafotren, const GrafoP<tCoste>& grafoautobus,
								GrafoP<tCoste>::vertice origen, GrafoP<tCoste>::vertice destino,
								GrafoP<tCoste>::vertice cambio1, Grafo<tCoste>::vertice cambio2)
{
	typedef typename GrafoP<tCoste>::vertice vertice;
	vector<tCoste> origen_cambio(grafoautobus.numVert(),0);
	vector<tCoste> cambio_destino(grafotren.numVert(),0);
	vector<typename GrafoP<tCoste>::vertice> caminitoacambio(N,0);
	vector<typename GrafoP<tCoste>::vertice> cambioadestino(N,0);

	origen_cambio = Djikstra(grafoautobus,origen,caminito);
	cambio_destino = Djikstra(grafotren,destino,cambioadestino);		
	if(origen_cambio[cambio2] < origen_cambio[cambio1])
		if(cambio_destino[cambio2] < cambio_destino[cambio1])
}