#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"
#include <algorithm>


template <typename tCoste>
matriz<tCoste>  tarifaMin(const GrafoP<tCoste> &gBus, const GrafoP<tCoste> &gTren,const typename GrafoP<tCoste>::vertice &ciudadTrans )
{
    GrafoP<tCoste> gUnion(gTren.numVert());
    typedef typename GrafoP<tCoste>::vertice ciudad;

    matriz<tCoste> mCosMin(gBus.numVert());
    matriz<ciudad> mCamMin(gBus.numVert());


    for(ciudad i=0; i<gTren.numVert(); i++)
        for(ciudad j=0; j<gTren.numVert(); j++)
        {
            if(i==j)
                gUnion[i][j] = GrafoP<tCoste>::INFINITO;
            else
            {
                if(ciudadTrans == i)
                {
                    gUnion[i][j] = std::min(gBus[i][j], gTren[i][j]);
                }
                else
                {

                }
            }

        }

    return Floyd(gUnion, mCamMin );
}
