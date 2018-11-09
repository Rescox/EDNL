/* Se dispone de dos grafos que representan la matriz de 
costes para viajes en un determinado país, pero por diferentes me
dios de transporte (tren y autobús, por ejemplo). 
Por supuesto ambos grafos tendrán el mismo número de nodos, N. 
Dados ambos grafos, una ciudad de origen, una ciudad de destino y el 
coste del taxi para cambiar de una estación a otra dentro de 
cualquier ciudad (se supone constante e igual para todas las ciudades), 
implementa un subprograma que calcule el camino y el coste 
mínimo para ir de la ciudad origen a la ciudad destino. */
#include <iostream>
#include <string>
#include <utility>
#include <vector>


#include "alg_grafo_E-S.h"
#include "alg_grafoPMC.h"
#include "grafoPMC.h"
#include "matriz.h"

using namespace std;


template <typename tCoste>
GrafoP<tCoste> crearMatriz(const GrafoP<tCoste>& bus,const GrafoP<tCoste>& tren,const unsigned coste);

template <typename tCoste>
pair<unsigned, unsigned> minimo(const GrafoP<tCoste>& gChido, const typename GrafoP<tCoste>::vertice origen,
const typename GrafoP<tCoste>::vertice destino);



int main()
{
	GrafoP<unsigned> bus  ("bus.txt");
	GrafoP<unsigned> tren("tren.txt");
	unsigned coste = 3;
	GrafoP<unsigned> grafoguay = crearMatriz(bus, tren, coste);

	vector<typename GrafoP<unsigned>::vertice> P;
	typename GrafoP<unsigned>::vertice v, w;
	
	typename GrafoP<unsigned>::tCamino cam;

	pair<unsigned,unsigned> pareja = minimo(grafoguay, 2, 1);

	unsigned choose = pareja.first;
	vector<unsigned> D;
	
	switch (int(choose))
	{
		case 1:
				D =  Dijkstra(grafoguay, 2, P );
				v = 2;
				w = pareja.second;
				cout << "El coste mínimo es : " << D[pareja.second] << " S/." <<endl;
				cam = camino<unsigned>(v, w, P);

				break;



		case 2:
				D =  Dijkstra(grafoguay, 2 + bus.numVert(), P );
				v = 2 + bus.numVert();
				w = pareja.second;
				cout << "El coste mínimo es : " << D[pareja.second] << " S/." <<endl;
				cam = camino<unsigned>(v , w, P);
				break;
	}

	vector<unsigned> el;

	for (auto it = cam.primera(); it != cam.fin(); it = cam.siguiente(it))
	{
	 	cout << cam.elemento(it) << " ";
	}






}


template <typename tCoste>
GrafoP<tCoste> crearMatriz(const GrafoP<tCoste>& bus,const GrafoP<tCoste>& tren,const unsigned coste)
{
	GrafoP<tCoste> nhete(tren.numVert() * 2);

	for (int i = 0; i < tren.numVert(); ++i)
	{
		nhete[i][i+tren.numVert()] = coste;
		nhete[i+tren.numVert()][i] = coste;
		for (int j = 0; j < tren.numVert(); ++j)
		{
			nhete[i][j]								  =  bus[i][j];
			nhete[i+tren.numVert()][j+tren.numVert()] = tren[i][j];
		}
	}
	return nhete;
}



template <typename tCoste>
pair<unsigned, unsigned> minimo(const GrafoP<tCoste>& gChido,const typename GrafoP<tCoste>::vertice origen,
const typename GrafoP<tCoste>::vertice destino)
{
	vector<typename GrafoP<unsigned>::vertice> P1;
	vector<typename GrafoP<unsigned>::vertice> P2;

	unsigned jaja = gChido.numVert()/2;

	vector<tCoste> D1 = Dijkstra(gChido, origen, P1);
	vector<tCoste> D2 = Dijkstra(gChido, origen + jaja,P2);

	tCoste minimo = GrafoP<tCoste>::INFINITO; 

	pair<unsigned, unsigned> pareja;

	
	if(D1[destino] 		< minimo)
	{
		pareja.first  = 1;
		pareja.second = destino;
		minimo = D1[destino];
	}

	if(D1[destino+jaja] < minimo)
	{
		pareja.first  = 1;
		pareja.second = destino + jaja;
		minimo = D1[destino + jaja];
	}

	if(D2[destino] 		< minimo)
	{
		pareja.first  = 2;
		pareja.second = destino;
		minimo = D2[destino];
	}

	if(D2[destino+jaja] < minimo)
	{
		pareja.first  = 2;
		pareja.second = destino + jaja;
	}



return pareja;

}