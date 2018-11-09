#include "alg_grafoPMC.h"
#include "alg_grafoP_E-S.h"

template <typename tCoste>
vector<tCoste>  distribuirProductos(const GrafoP<tCoste> &G, size_t cantProd,
                                    const typename GrafoP<tCoste>::vertice centrDistrib, vector<size_t> &capCiud,
                                    const vector<double> &subvencion, tCoste &minCosteTotal)
{
    typedef typename GrafoP<tCoste>::vertice vertice;

    vector<tCoste> cantAlmaCiu(G.numVert(), 0); //un vector que mostrara cuantos productos hemos almacenado en cada ciudad
    vector<tCoste> vCostesMin(G.numVert(), 0);  //un vector que contendrá los costes min para ir desde el almacen principal a todas las ciudades
    vector<vertice> vCaminMin(G.numVert(), 0);  //vector P de dijkstra

    tCoste costeMin;                            //el coste min del viaje en cada iteracion
    vertice j;                                  //en esta variable guardaremos el vertice hacia el que sale mas barato enviar los productos en cada iteracion

    vCostesMin = Dijkstra(G, centrDistrib, vCaminMin);  //calculamos el coste minimo para transportar una unidad desde centro distr a cualquier ciudad

    //aplicamos la subvencion a los costes min
    for(vertice i=0; i<G.numVert(); i++)
        vCostesMin[i] -= vCostesMin[i]*subvencion[i];

    while(cantProd > 0)                                 //damos viajes hasta que nos quedemos sin productos
    {
        costeMin = GrafoP<tCoste>::INFINITO;            //reiniciamos el coste min para buscar la siguiente ciudad que nos salga mas barato enviar

        for(vertice i=0; i<G.numVert(); i++)            //iteramos buscando la ciudad que nos proporciona un coste mas barato y que tenga hueco y la almacenamos en j
            if(vCostesMin[i] < costeMin && cantAlmaCiu[i] != capCiud[i])
            {
                 j = i;
                costeMin = vCostesMin[i];
            }

        if(cantProd > capCiud[j]-cantAlmaCiu[j])        //si la cantidad a repartir es mayor que lo que cabe en el almacen(lo que cabe-lo que hay)
        {
            cantProd -= capCiud[j]-cantAlmaCiu[j];      //llenamos el almacen y le restamos el num de prod a cantProd
            minCosteTotal += vCostesMin[j]*capCiud[j]-cantAlmaCiu[j]; //al numero de prod que hemos guardado lo multiplicamos por el precio de envio unitario y se lo añadimos al total
            cantAlmaCiu[j] = capCiud[j];            //llenamos el almacen de esa ciudad
        }
        else                                            //si el almacen posee mas capacidad de lo que tenemos
        {
            cantAlmaCiu[j] = cantProd;
            minCosteTotal += vCostesMin[j]*cantProd;
            cantProd -= cantProd;                       //ponemos el el stock disponible a 0 ya que vamos a vaciarlo en el almacen j
        }

    }

    //std::cout << vCostesMin << std::endl;

    return cantAlmaCiu;
}




