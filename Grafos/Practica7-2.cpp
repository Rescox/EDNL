#include "alg_grafoPMC.h"
#include "grafoPMC.h"
#include "alg_grafo_E-S.cpp"
#include <iostream>
static const int N = 9;
int main(){

	int h = 3;

	GrafoP<unsigned int> l (N);
	for(int i = 0;i<N;i++)
	{
		for(int j = 0; j< N;j++)
		{
		 	l[i][j] = GrafoP<unsigned int>::INFINITO;
		}
	
	}
	for(int i = 0;i<N;i++)
	{
		if(i + h < h*h)
            l[i][i+h] = 1;

        if(i-h >= 0)
            l[i][i-h] = 1;

        if((i+1 % h) != 0)
            l[i][i+1] = 1;
        

        if((i % h) != 0)
            l[i][i-1] = 1;
	
	}
	
	std::cout << l<<'\n'<< std::endl;


}