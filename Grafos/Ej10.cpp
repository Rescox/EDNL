/*10. Se dispone de tres grafos que representan la matriz de costes para viajes en un
determinado país, pero por diferentes medios de transporte (tren, autobús y avión). Por
supuesto los tres grafos tendrán el mismo número de nodos, N.
Dados los siguientes datos:
* los tres grafos,
* una ciudad de origen,
* una ciudad de destino,
* el coste del taxi para cambiar, dentro de una ciudad, de la estación de tren a la
de autobús o viceversa (taxi-tren-bus) y
* el coste del taxi desde el aeropuerto a la estación de tren o la de autobús, o
viceversa (taxi-aeropuerto-tren/bus)
y asumiendo que ambos costes de taxi (distintos entre sí, son dos costes diferentes) son
constantes e iguales para todas las ciudades, implementa un subprograma que calcule el
camino y el coste mínimo para ir de la ciudad origen a la ciudad destino.*/
#include <iostream>
#include <string>
#include <vector>
#include <utility>


#include "alg_grafo_E-S.cpp"
#include "alg_grafoPMC.h"
#include "grafoPMC.h"

using namespace std;

template <typename tCoste>
GrafoP<tCoste> llenaGrafo(const GrafoP<tCoste>& t,const GrafoP<tCoste>& b,const GrafoP<tCoste>& a, 
const tCoste cTaxiTren_Bus, const tCoste cTaxiAeropuerto_Tren_Bus);


template <typename tCoste>
pair<typename GrafoP<tCoste>::tCamino, tCoste> todoChido(const GrafoP<tCoste>&, typename GrafoP<tCoste>::vertice,
typename GrafoP<tCoste>::vertice, const tCoste, const tCoste);


int nv;

int main()
{
	GrafoP<unsigned> tren("tren.txt");
	GrafoP<unsigned> bus("bus.txt");
	GrafoP<unsigned> avion("avion.txt");
	typename GrafoP<unsigned>::vertice origen(1);
	typename GrafoP<unsigned>::vertice destino(3);
	unsigned cTaxiTren_Bus = 3;
	unsigned cTaxiAeropuerto_Tren_Bus = 7;

	nv = bus.numVert();

	GrafoP<unsigned> buenaOnda = llenaGrafo(tren, bus, avion, cTaxiTren_Bus, cTaxiAeropuerto_Tren_Bus);
	std::cout << buenaOnda;

	pair<typename GrafoP<unsigned>::tCamino, unsigned> pareja;
	pareja = todoChido(buenaOnda, origen, destino, cTaxiTren_Bus, cTaxiAeropuerto_Tren_Bus);

	cout << endl << "CAMINO:\t" << pareja.first << endl;
	cout << "COSTE:\t" << pareja.second << endl;

}


template <typename tCoste>
GrafoP<tCoste> llenaGrafo(const GrafoP<tCoste>& t,const GrafoP<tCoste>& b,const GrafoP<tCoste>& a, 
const tCoste cTaxiTren_Bus, const tCoste cTaxiAeropuerto_Tren_Bus)
{
	GrafoP<tCoste> gChido(nv*3);
	for (int i = 0; i < nv; ++i)
	{
		gChido[i][i + nv]	 	= cTaxiTren_Bus;
		gChido[i][i + 2*nv]  	= cTaxiAeropuerto_Tren_Bus;
		gChido[i+nv][i] 	  	= cTaxiTren_Bus;
		gChido[i+nv][i+2*nv]   	= cTaxiAeropuerto_Tren_Bus;
		gChido[i+2*nv][i]		= cTaxiAeropuerto_Tren_Bus;
		gChido[i+2*nv][i+nv] 	= cTaxiAeropuerto_Tren_Bus;



		for (int j = 0; j < nv; ++j)
		{
			gChido[i][j] 			= b[i][j];
			gChido[i+nv][j+nv] 		= t[i][j];
			gChido[i+2*nv][j+2*nv] 	= a[i][j]; 
		}
	}
	return gChido;
}



template <typename tCoste>
pair<typename GrafoP<tCoste>::tCamino, tCoste> 
todoChido			(const GrafoP<tCoste>& gChido, typename GrafoP<tCoste>::vertice origen,
					typename GrafoP<tCoste>::vertice destino, const tCoste cTaxiTren_Bus, const tCoste cTaxiAeropuerto_Tren_Bus)

{
	vector<typename GrafoP<tCoste>::vertice> P1;
	vector<typename GrafoP<tCoste>::vertice> P2;
	vector<typename GrafoP<tCoste>::vertice> P3;

	

	vector<tCoste> D1 = Dijkstra(gChido, origen 		, P1);
	vector<tCoste> D2 = Dijkstra(gChido, origen + nv 	, P2);
	vector<tCoste> D3 = Dijkstra(gChido, origen + nv*2  , P3); 

	pair<typename GrafoP<unsigned>::tCamino, unsigned> pareja;


	pareja.second = GrafoP<tCoste>::INFINITO;
	
	tCoste min1 = pareja.second, min2 = pareja.second, min3 = pareja.second;

	unsigned pos;
	int select;
				

	for (unsigned i = destino; i < 3*nv; i+=nv)
	{
		if (D1[i] < min1)
		{			
			min1 = D1[i];			
			pos = i;
		}
		if (D2[i] < min2)
		{								
			min2 = D2[i];						
			pos = i;
		}
		if (D3[i] < min3)
		{				
			min3 = D3[i];			
			pos = i;
		}		
	}


	pareja.second =  min(min(min1,min2), min3);

	if (min(min(min1,min2), min3) == min1)
		select = 1;
	else if (min(min(min1,min2), min3) == min2)
		select = 2;
	else select = 3;
				
	switch (select)
	{
		case 1:
				pareja.first = camino<tCoste>(origen, pos, P1);
				break;

		case 2:
				pareja.first = camino<tCoste>(origen + nv, pos, P2);			
				break;
		case 3:
				pareja.first = camino<tCoste>(origen + nv*2, pos, P3);	
				break;
	}




	return pareja;



}










