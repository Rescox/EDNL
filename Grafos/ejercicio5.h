#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"
#include <algorithm>

enum tipoAlergia{CARRETERA, TREN, AVION};

template <typename tCoste>
vector<bool> posiblesCiudadesDestino(const GrafoP<tCoste> &gCarr, const GrafoP<tCoste> &gTren, const GrafoP<tCoste> &gAvi, size_t presupuesto, tipoAlergia alergia, typename GrafoP<tCoste>::vertice origen )
{
    typedef typename GrafoP<tCoste>::vertice ciudad;     // typedef para identificar num ciudad
    GrafoP<tCoste> gTodos(gCarr.numVert());             //grafo con la union de todos los medios de transporte

    vector<bool> posiblesCiudades(gCarr.numVert(), false);     //donde se indica con un true las ciudades a las que puede llegar

    vector<tCoste> mCostesMinTransbordo(gCarr.numVert());                           //union de los costes minimos de cada medio de transporte
    vector<typename GrafoP<tCoste>::vertice> mCaminMinTransbordo(gCarr.numVert());  //vector P




    for(ciudad i = 0; i< gCarr.numVert(); i++)
    {
        for(ciudad j = 0; j< gCarr.numVert(); j++)
            if(i == j)
                gTodos[i][j] = GrafoP<tCoste>::INFINITO;
            else
            {
                switch(alergia)
                {
                    case CARRETERA:
                        gTodos[i][j] = std::min(gTren[i][j], gAvi[i][j]);
                        break;
                    case TREN:
                        gTodos[i][j] = std::min(gCarr[i][j], gAvi[i][j]);
                        break;
                    case AVION:
                        gTodos[i][j] = std::min(gCarr[i][j], gTren[i][j]);
                        break;
                }

            }

    }

    //hacemos dijkstra para calcular el coste min
    //std::cout <<"grafo con todos lo medios de transporte: " << std::endl;
    //std::cout << gTodos << std::endl;

    mCostesMinTransbordo = Dijkstra(gTodos, origen, mCostesMinTransbordo);

    //std::cout <<"grafo con los costes minimos de origen a cualquier ciudad: " << std::endl;
    //std::cout << mCostesMinTransbordo << std::endl;

    //si el presupuesto llega para ir a esa ciudad la marcamos como true
    for(ciudad i = 0; i< gCarr.numVert(); i++)
        if(mCostesMinTransbordo[i] <= presupuesto)
            posiblesCiudades[i] = true;




return posiblesCiudades;

}
