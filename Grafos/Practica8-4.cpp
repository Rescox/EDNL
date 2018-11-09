#include "alg_grafoPMC.h"
#include "grafoPMC.h"
#include <stdlib.h>
#include <iostream>
#include <random>

template <typename tCoste>
void CanalesAbrir(const GrafoP<tCoste>& g)
{
	GrafoP<int> caminoMinimo(g.numVert());
	GrafoP<tCoste> grafocopia(g);
	std::cout <<g << std::endl;
	const size_t N = 5;
	for(int i = 0;i<N;i++)
	{
		for(int j = 0;j<N;j++)
		{
			if(j != i)
				grafocopia[i][j]= -1*g[i][j];
		}
	}
	caminoMinimo = Prim(grafocopia);
	std::cout << caminoMinimo <<std::endl ; 
	for(int i = 0; i< N; i++){
		for(int j = i+1;j<N;j++){
			if(j != i)
				caminoMinimo[i][j] = caminoMinimo[j][i] = abs(caminoMinimo[i][j]);
			
		}
	}
	std::cout << caminoMinimo <<std::endl ; 
}


int main()
{
	srand(time(NULL));
	GrafoP<int> grafo(5);
	const size_t N = 5;
	for(int i = 0; i< N; i++){
		for(int j = 0;j<N;j++){
			if(j == i)
				grafo[i][j] = grafo[j][i] = GrafoP<int>::INFINITO; 
			else
				grafo[i][j]= grafo[j][i] = 1*rand() % 50+1;
		}
	}
	CanalesAbrir(grafo);
}