#include "alg_grafoPMC.h"
#include "grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <math.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


struct Coordenadas{
	double x,y;
};


double calcularDistancia(const vector<Coordenadas>& ciudad, int i, int j)
{
	double res,a,b;

	a = abs(ciudad[i].x-ciudad[j].x);
	b = abs(ciudad[i].y-ciudad[j].y);
	res = sqrt(pow(a,2)+pow(b,2)); 
	return res;

}

void deimosFobosCarreteras(const vector<Coordenadas>& Fobos,const vector<Coordenadas>& Deimos, 
							vector<bool> costaFobos, vector<bool> costaDeimos,
							int origen, int destino)
{
	const size_t N1 = Fobos.size();
	const size_t N2 = Deimos.size();
	GrafoP<double> matrizSinCarreteraFobos(N1);
	GrafoP<double> matrizSinCarreteraDeimos(N2);
	GrafoP<double> matrizConCarreteraFobos(N1);
	GrafoP<double> matrizConCarreteraDeimos(N2);
	for(int i = 0; i<N1;i++)
	{
		for(int j = i+1; j<N1;j++)
		{
			matrizSinCarreteraFobos[i][j] = matrizSinCarreteraFobos[j][i] = calcularDistancia(Fobos,i,j);
		}
	}
	for(int i = 0; i<N2;i++)
	{
		for(int j = i+1; j<N2;j++)
		{
			matrizSinCarreteraDeimos[i][j] = matrizSinCarreteraDeimos[j][i] = calcularDistancia(Deimos,i,j);
		}
	}
	matrizConCarreteraDeimos = Prim(matrizSinCarreteraDeimos);
	matrizConCarreteraFobos = Prim(matrizSinCarreteraFobos);
	
	//std::cout << matrizConCarreteraFobos << std::endl;
	//std::cout << matrizConCarreteraDeimos << std::endl;
	vector<double> costeMinFobos(N1);
	vector<double> costeMinDeimos(N2);
	vector<GrafoP<int>::vertice> caminoMinFobos(N1);
	vector<GrafoP<int>::vertice> caminoMinDeimos(N2);
	std::cout << matrizConCarreteraDeimos;
	GrafoP<double> grafototal(N1+N2);
	//std::cout << grafototal;
	for(int i = 0; i<N1;i++)
	{
		for(int j = i+1; j<N1;j++)
		{
			grafototal[i][j] = grafototal[j][i] = matrizConCarreteraFobos[i][j];
		}
	}
	std::cout << grafototal;
	cout <<matrizConCarreteraDeimos;
	
	int i1 = 0,j1 = 0;
	for(int i =N1 ; i<N1+N2;i++)
	{
		j1=0;
		for(int j = N1+1; j<N1+N2;j++)
		{
			if(matrizSinCarreteraDeimos[i1][j1]!= GrafoP<double>::INFINITO)
				grafototal[i][j] = grafototal[j][i] = matrizConCarreteraDeimos[i1][j1];
			
			j1++;
		}
		i1++;
	}
	
	std::cout << grafototal;

	double coste = GrafoP<double>::INFINITO;
	double aux;
	int pos = 0;
	for(int i = 0;i<N1;i++)
	{
		aux = 0;
		if(costaFobos[i])
		{
				costeMinFobos = Dijkstra(matrizConCarreteraFobos,i,caminoMinFobos);
				aux += costeMinFobos[i];
		}
		if(aux< coste)
			coste = aux;
			pos = i;
	}
	int pos2;

	for(int j = 0;j<N1;j++)
	{
		aux = 0;
		if(costaFobos[j])
		{
				costeMinFobos = Dijkstra(matrizConCarreteraFobos,j,caminoMinFobos);
				aux += costeMinFobos[j];
		}
		if(aux< coste)
			coste = aux;
			pos2 = j;
	}

		
	
	

}


int main(){
	srand(time(NULL));
	vector<Coordenadas> Fobos(5);
	vector<Coordenadas> Deimos(5);
	vector<bool> FobosCosta(5);
	FobosCosta[1] = true;
	FobosCosta[2] = true;
	FobosCosta[3] = true;
	vector<bool> DeimosCosta(5);
	DeimosCosta[1] = true;
	DeimosCosta[6] = true;
	DeimosCosta[9] = true;
	const size_t N = 5;
	for(int i = 0; i< N; i++){
		
		Fobos[i].x = rand() %50;
		Fobos[i].y = 0;
		Deimos[i].x = rand() %50;
		Deimos[i].y = 0; 
		//std::cout << Deimos[i].x << " , " << Deimos[i].y;
		
	}
	
	
	deimosFobosCarreteras(Fobos,Deimos,FobosCosta,DeimosCosta,0,2);


}