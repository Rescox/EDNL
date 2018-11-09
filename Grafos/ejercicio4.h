#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"

size_t numCamiones = 0;     //variable que define cuantos caminiones y empleados hay, hay el mismo num de empleados que de camiones

template <typename tCoste>
struct parteTrabajo
{
    typename GrafoP<tCoste>::vertice destino;
    size_t nCargas;
    parteTrabajo(typename GrafoP<tCoste>::vertice _destino = -1, size_t _nCargas = 0): destino(_destino), nCargas(_nCargas){}
};

template <typename tCoste>
vector<tCoste> calcularDistCamiones(const GrafoP<tCoste> &G, const matriz<parteTrabajo<tCoste>> &vPT, typename GrafoP<tCoste>::vertice capital)
{
    vector<tCoste> distCamiones(numCamiones, 0);
    vector<tCoste> vCostMin(G.numVert());
    vector<typename GrafoP<tCoste>::vertice> vCaminMin(G.numVert());
    size_t j;

    for(size_t i = 0; i<vPT.dimension(); i++)
    {
        j = 0;
        while(vPT[i][j].destino != -1 )
        {
            vCostMin = Dijkstra(G, capital, vCaminMin );
            distCamiones[i] += vCostMin[vPT[i][j].destino]*vPT[i][j].nCargas;
            vCostMin = Dijkstra(G, vPT[i][j].destino, vCaminMin );
            distCamiones[i] += vCostMin[capital]*vPT[i][j].nCargas;
            j++;
        }

    }

    return distCamiones;
}


