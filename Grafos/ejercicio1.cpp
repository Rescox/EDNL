#include "alg_grafoPMC.h"
#include <iostream>

using namespace std;

template <typename tCoste> tCoste calculaDiametroVertice(const vector<tCoste> v)
{
	tCoste max1=0, max2=0;

	for(int i=0; i<v.size(); i++)
	{
		if(v[i] > max1){
			max2 = max1;
			max1 = max2;
		}
		else if(v[i] > max2){
				max2 = v[i];
			}
	}
	return max1 + max2;
}

template <typename tCoste> tCoste diametroGrafoP(const GrafoP<tCoste>& G)
{
	matriz<typename GrafoP<tCoste>::vertice> P;
	matriz<tCoste> M = Floyd(G,P);
	tCoste diametroGrafoP = GrafoP<tCoste>::INFINITO;
	tCoste diametroVertice;

	for(int i=0; i<G.numVert(); i++)
	{
		diametroVertice = calculaDiametroVertice(M[i]);

		if(diametroVertice < diametroGrafoP)
			diametroGrafoP = diametroVertice;
	}

	return diametroGrafoP;
}

int main()
{
	string a = "ejercicio1.txt";
	GrafoP<int> G;
	int diametro = diametroGrafoP(G);
	cout << "El diametro es: " << diametro << endl;
}