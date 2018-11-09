#include <iostream>
#include "grafoPMC.h"
#include "grafoMA.h"
#include "alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <random>
using namespace std;

void menuCosas(Grafo& g);

int main(){
	srand(time(NULL));
	Grafo grafoadyacencia{5};
	//menuCosas(grafoadyacencia);
	GrafoP<int> grafo1{4};
	GrafoP<int> grafo2{4};
	typedef GrafoP<int>::vertice vertice;
	typedef GrafoP<int>::tCamino tCamino;
	const size_t N = grafo1.numVert();
	for(int i = 0; i< N; i++){
		for(int j = i+1;j<N;j++){
			if(j == i)
				grafo1[i][j] = grafo1[j][i] = GrafoP<int>::INFINITO; 

			else if (j == 2||i==2)
			{
				grafo1[i][j] = grafo1[j][i] = GrafoP<int>::INFINITO;
			}
			else
				grafo1[i][j]= grafo1[j][i] = rand() % 5+1;
		}
	}
	for(int i = 0; i< N; i++){
		for(int j = i+1;j<N;j++){
			if(j == i)
				grafo2[i][j] = grafo2[j][i] = GrafoP<int>::INFINITO; 
			else if (j == 2)
			{
				grafo2[i][j] = grafo2[j][i] = GrafoP<int>::INFINITO;
			}
			else
				grafo2[i][j]= grafo2[j][i] = rand() % 20+1;
		}
	}
	GrafoP<int> matrizgrandota(2*N);
	
	for(int i = 0; i< N; i++){
		for(int j = i+1;j<N;j++){
			matrizgrandota[i][j] = matrizgrandota[j][i] = grafo1[i][j]; 
				
		}
	}
	int f = 0,c=0;
	for(int i = N; i< 2*N; i++){
		for(int j = N;j<2*N;j++){
			if(i == j){
				matrizgrandota[i][j] = matrizgrandota[j][i] = GrafoP<int>::INFINITO;
			}
			else
				matrizgrandota[i][j] = matrizgrandota[j][i] = grafo2[f][c]; 
			c++;
		}
		f++;
		c=0;
	}

	vector<int> costeMin1(N,0);
	vector<int> costeMin2(N,0);
	vector<int> costeMinTotal(N,0);
	vector<vertice> caminoMin(N,0); 
	

	for(int i =0; i < N;i++)
	{
		cout << i <<"    "<< N+i <<endl;
		if(i == 3||i == 2)
			matrizgrandota[i][N+i] = matrizgrandota[N+i][i] = 0;
		else
			matrizgrandota[i][N+i] = matrizgrandota[N+i][i] = GrafoP<int>::INFINITO ;
	}

	costeMin1 = Dijkstra(matrizgrandota,2,caminoMin);
	cout << "Avion: "<< costeMin1 <<endl;
	costeMin2 = Dijkstra(matrizgrandota,N+2,caminoMin);

	cout <<matrizgrandota<<endl;
	cout << "Tren: "<< costeMin2;
	for(int i = 0; i<N;i++)
	{
		costeMinTotal[i] = min(min(costeMin1[i],costeMin1[N+i]),min(costeMin2[i],costeMin2[N+i]));
	}
	cout <<'\n';
	cout << "Total: " <<costeMinTotal<<endl;;
	
	
	matriz<unsigned int> MatrizFloyd(grafo1.numVert());
	matriz<unsigned int> MatrizFloydResultado(grafo1.numVert());
	
}




