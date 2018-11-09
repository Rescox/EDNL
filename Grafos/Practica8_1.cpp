#include "alg_grafoMA.h"
#include "grafoMA.h"
#include "grafoPMC.h"
#include <stdlib.h>
#include <math.h>
#include "listaenla.h"
#include <iostream>

struct Coordenadas{
	double x,y;
};

double calcularDistancia(const Lista<Coordenadas>& ciudad, int i, int j);


GrafoP<int> Tombuctu(const Lista<Coordenadas>& ciudad,const Grafo& carreteras)
{
	const size_t N = carreteras.numVert();
	GrafoP<int> costeCiudad(N);

	for(size_t  i = 0; i<N; i++)
	{
		for(size_t j = 0; j<N;j++)
		{
			if(i == j)
				costeCiudad[i][j] = GrafoP<int>::INFINITO;
			else
				if(carreteras[i][j])
					costeCiudad[i][j] = calcularDistancia(ciudad,i,j);
		}

	}
	return costeCiudad;
}



double calcularDistancia(const Lista<Coordenadas>& ciudad, int i, int j)
{
	typedef Lista<Coordenadas>::posicion pos;
	double res,a,b;
	pos it,jt;

	a = abs(ciudad[i].x-ciudad[j].x);
	b = abs(ciudad[i].y-ciudad[j].y);
	res = sqrt(pow(a,2)+pow(b,2)); 
	return res;

}

int main(){
	Grafo p(6);
	GrafoP<int> grafitores(6);
	p[2][3] = p[3][2] = true;
	p[1][0] = p[0][1] = true;
	p[4][5] = p[5][4] = true;
	Lista<Coordenadas> caminos(6);
	
		caminos.insertar.x = 1.0;
		caminos[0].y = 2.0;
		caminos[1].x = 5.0;
		caminos[1].y = 2.0;
		caminos[2].x = 7.0;
		caminos[2].y = 5.0;
		caminos[3].x = 23.0;
		caminos[3].y = 64.0;
		caminos[4].x = 432.0;
		caminos[4].y = 2.0;
		caminos[5].x = 3.0;
		caminos[5].y = 2.0;
	
	grafitores = Tombuctu(caminos,p);
	std::cout <<grafitores;

}