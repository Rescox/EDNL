#include "alg_grafoPMC.h"
#include "grafoPMC.h"
#include <stdlib.h>
#include <iostream>
#include <random>



void caudalLongitud(const GrafoP<double>& longitud, const GrafoP<double>& caudal,double subvencion, double costeKM)
{
	const size_t numvert = longitud.numVert(); // Guardamos el numero total de vertices
	GrafoP<double> LonYCaudal(numvert); // Creamos el grafo auxiliar que tendra la resta de:
										//longitud*costeKM -caudal*costeSubvencion
	
	for(int i = 0;i<numvert;i++)
	{
		for(int j = 0;j<numvert;j++)
		{
			if(i != j)
			//LonYCaudal[i][j] = suma(costeKM*longitud[i][j],-1*(subvencion*caudal[i][j]) );
			LonYCaudal[i][j] = costeKM*longitud[i][j] -subvencion*caudal[i][j];
		}
	}
	std::cout<< LonYCaudal<< std::endl;
	
	GrafoP<double> matrizresultado(numvert);
	matrizresultado = Prim(LonYCaudal);
	std::cout << matrizresultado << std::endl;
}


int main()
{
	srand(time(NULL));
	GrafoP<double> grafo1(5);
	GrafoP<double> grafo2(5);
	const size_t N = 5;
	for(int i = 0; i< N; i++){
		for(int j = 0;j<N;j++){
			if(j == i)
			{ 
				grafo1[i][j] = grafo1[j][i] = GrafoP<int>::INFINITO;
				grafo2[i][j] = grafo2[j][i] = GrafoP<int>::INFINITO;
			}
			else
				grafo1[i][j]= grafo1[j][i] = 1*rand() % 50+1;
				grafo2[i][j]= grafo2[j][i] = 1*rand() % 50+1;
		}
	}
	caudalLongitud(grafo1,grafo2,1.5,5.0);
}