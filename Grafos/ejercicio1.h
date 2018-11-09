#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"


template <typename tCoste>
void viajeMasCaro(const GrafoP<tCoste> &G, typename GrafoP<tCoste>::vertice & origen, typename GrafoP<tCoste>::vertice & dest, tCoste &coste )
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    coste = 0;
    matriz<unsigned int> McF(G.numVert());
	matriz<unsigned int> McamF(G.numVert());

	McF = Floyd(G, McamF );
    std::cout <<"Grafo de costes minimos agencia: \n"<< McF << std::endl;

    for(vertice i = 0; i<G.numVert(); i++)
        for(vertice j = 0; j<G.numVert(); j++)
        {
            if(McF[i][j] > coste)
            {
                coste = McF[i][j];
                origen = i;
                dest = j;
            }

        }
}
/*//configuracion de zuelandia
size_t nCiudades = 6;
vector<bool> cTomadas(nCiudades, false);

matriz<bool> carrCort(nCiudades, false);

GrafoP<size_t>::vertice capital;
//-------------------------------


template <typename tCoste>
void cortarCarreteras( GrafoP<tCoste> &zuelan)
{
    for(typename GrafoP<tCoste>::vertice i=0; i< zuelan.numVert(); i++)
        for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
            if(carrCort[i][u])
                zuelan[i][u] = GrafoP<tCoste>::INFINITO;
}

template <typename tCoste>
void tomarCiudades(GrafoP<tCoste> &zuelan)
{
    for(typename GrafoP<tCoste>::vertice i=0; i< zuelan.numVert(); i++)
            if(cTomadas[i])
            {
                for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
                    zuelan[u][i] = GrafoP<tCoste>::INFINITO;

                for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
                    zuelan[i][u] = GrafoP<tCoste>::INFINITO;
            }
}

template <typename tCoste>
matriz<tCoste> activarControlSeguridad(GrafoP<tCoste> &zuelan)
{
    //matriz de coste minimo de ciudades y matriz de vertices intermedios
    matriz<tCoste> Mc(zuelan.numVert());
    matriz<tCoste> Pf(zuelan.numVert());

    //vectores de coste minimo para dijkstra
    vector<tCoste> Vc;
    vector<tCoste> Vc2;
    vector<typename GrafoP<tCoste>::vertice> Pd;

    //hayamos la matriz de costes minimos en guerra
    Mc = Floyd(zuelan, Pf);
    std::cout <<"Matriz de costes en guerra antes de la aplicar controles de seguridad: \n"<< Mc <<std::endl;

    Vc = Dijkstra(zuelan, capital, Pd);     //hacemos dijkstra para calcular las distancias minimas desde la capi a todo lao
    Vc2 = DijkstraInv(zuelan, capital, Pd); //hacemos dijkstra inv para calcula el otro tramo, de cualquier origen a la capi
    for(typename GrafoP<tCoste>::vertice i=0; i< zuelan.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice u=0; u< zuelan.numVert(); u++)
        {
            if(u != capital) //si el destino es la capital, dejamos tal y como el floyd lo dejo ya  que  no es necesario pasar aduana
            {
                if(Mc[i][u] != 0 && Mc[i][u] != GrafoP<tCoste>::INFINITO )  //si el coste es de uno a uno mismo o si no hay camino se deja como el floyd lo dejo
                {
                    Mc[i][u] = Vc[u] + Vc2[i];
                }
            }
        }
    }

return Mc;

}
*/




