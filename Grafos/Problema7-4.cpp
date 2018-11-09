#include "grafoPMC.h"
#include "alg_grafoPMC.h"

enum tipoalergia{Tren, Carretera, Avion};
template <typename tCoste>
void ViajeroAlergico(int dinero,const GrafoP<tCoste> grafoTren,const GrafoP<tCoste> grafoCarretera,const GrafoP<tCoste> grafoAvion,typename GrafoP<tCoste>::vertice& origen)
{
	tipoalergia alergia = Tren;
	GrafoP<tCoste> grafoGeneral(grafoTren.numVert());
	switch(alergia)
	{
		case Tren:
			minimoMatriz(grafoCarretera,grafoAvion,grafoGeneral);
			break;
	
		case Carretera:
			minimoMatriz(grafoAvion,grafoTren,grafoGeneral);
			break;
		case Avion:
			minimoMatriz(grafoCarretera,grafoTren,grafoGeneral);
			break;
	}
	//Dijkstra(grafoCarretera, origen, mCostesMinTransbordo);
}

template <typename tCoste>
void minimoMatriz(const GrafoP<tCoste>& g1, const GrafoP<tCoste>& g2, GrafoP<tCoste>& ggeneral)
{
	for(int i = 0; i < g1.numVert();i++)
		for(int j = 0; j< g1.numVert();j++)
		{
			if(g1[i][j]||g2[i][j])
				ggeneral[i][j] = GrafoP<tCoste>::INFINITO;
			else
				ggeneral[i][j] = min(g1[i][j],g2[i][j]);
		}
}

template<typename tCoste>
tCoste min(const tCoste& el1, const tCoste& el2)
{
	if(el1<el2)
		return el1;
	else
		return el2;
}