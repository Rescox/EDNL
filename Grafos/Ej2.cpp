/*2. El archipiélago de Tombuctú2 está formado por un número desconocido de islas,
cada una de las cuales tiene, a su vez, un número desconocido de ciudades, las cuales
tienen en común que todas y cada una de ellas dispone de un aeropuerto. Sí que se
conoce el número total de ciudades del archipiélago (podemos llamarlo N, por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. No existen puentes que unan las islas y se ha decidido que la
opción de comunicación más económica de implantar será el avión.
Se dispone de las coordenadas cartesianas (x, y) de todas y cada una de las
ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en el que se
indica si existe carretera directa entre cualesquiera dos ciudades del archipiélago. El
objetivo de nuestro problema es encontrar qué líneas aéreas debemos implantar para
poder viajar entre todas las ciudades del archipiélago, siguiendo los siguientes criterios:
1) Se implantará una y sólo una línea aérea entre cada par de islas.
2) La línea aérea escogida entre cada par de islas será la más corta entre todas
las posibles.
Así pues, dados los siguientes datos:
• Lista de ciudades de Tombuctú2 representada cada una de ellas por sus
coordenadas cartesianas.
• Matriz de adyacencia de Tombuctú que indica las carreteras existentes en
dicho archipiélago,
Implementen un subprograma que calcule y devuelva las líneas aéreas necesarias para
comunicar adecuadamente el archipiélago siguiendo los criterios anteriormente
expuestos.*/
#include "grafoMA.h"
#include "grafoPMC.h"
#include "alg_grafoMA.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_E-S.cpp"
#include "particion.cpp"

#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

template <typename tCoste>
tCoste distancia(const pair<tCoste,tCoste>& c1, 
const pair<tCoste,tCoste>& c2);


template <typename tCoste>
matriz<tCoste> vinagre2(Particion& p, const vector<pair<tCoste,tCoste> >& ciudades, const Grafo& ady);

int main()
{

}



template <typename tCoste>
matriz<tCoste> vinagre2(Particion& p, const vector<pair<tCoste,tCoste> >& ciudades, const Grafo& ady)
{
	GrafoP<tCoste> aux(ciudades.size());

	for (int i = 0; i < ciudades.size(); ++i)
	{
		for (int j = i+1; j < ciudades.size(); ++j)
		{
			if(ady[i][j]) 
			{
				aux[i][j] = distancia(ciudades[i], ciudades[j]);
				aux[j][i] = distancia(ciudades[i], ciudades[j]);
			}

		}
	}
	int numeroIslas = ciudades.size();

	matriz<typename GrafoP<tCoste>::vertice> P;
	matriz<tCoste> F = Floyd(aux, P);

	for (int i = 0; i < F.dimension(); ++i)
	{
		for (int j = i; j < F.dimension(); ++j)
		{
			if (F[i][j] != GrafoP<tCoste>::INFINITO)
			{
				p.unir(i,j);
				numeroIslas--;
			}
		}
	}


	vector<vector<typename GrafoP<tCoste>::vertice > > ciudadesIslas(numeroIslas);

	for (int i = 0; i < numeroIslas; ++i) 					//Pone los representantes en la primera posicion de cada fila de mi ciudadesIslas
	{
		ciudadesIslas[i][0] = p.encontrar(i);				
	}

	for (int i = 0; i < ciudades.size; i++) 				//Para cada ciudad...
	{
		for (int j = 0; j < numeroIslas; j++)				//...miramos a que isla pertenece y la pusheamos en su fila correspondiente
		{
			if (p.encontrar(i) == ciudadesIslas[j][0])
			{
				ciudadesIslas[j].push_back(i); 				//Metemos la ciudad
				j = numeroIslas;							//Salimos del bucle
			}
		}
	}
	
vector< typename GrafoP<tCoste>::arista> sol;

tCoste min;
int a,b;
	for (int i = 0; i < numeroIslas; i++)
	{
		min = GrafoP<tCoste>::INFINITO;
		for (int j = 0; j < numeroIslas; j++)
		{
			if (i != j)
			{
				for (int k = 1; k < ciudadesIslas[i].size(); k++)
				{
					for (int l = 1; l < ciudadesIslas[j].size(); l++)
					{
						tCoste aux = distancia(ciudades[ciudadesIslas[j][l]], ciudades[ciudadesIslas[i][k]]);
						if (aux < min)
							{
								min = aux;
								a = l;
								b = k;
							}
					}
				}
			}
			sol.push_back(typename GrafoP<tCoste>::arista (l,k,min));

		}
					
	}





}



template <typename tCoste>
tCoste distancia(const pair<tCoste,tCoste>& c1, 
const pair<tCoste,tCoste>& c2)
{
	return sqrt(pow((c1.first - c2.first),2) + pow((c1.second - c2.second),2) );
}
