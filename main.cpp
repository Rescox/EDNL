#include <iostream>
#include "ABB_H.hpp"
#include "abb_E-S.h"

using namespace std;

int main()
{
    Abb<int> uno;

    rellenarAbb(uno, -1);
    imprimirAbin(uno);
    std::cout << "antes de eliminar subarbol" << std::endl;
    uno.eliminarArbol(28);
    cout << " se ha eliminado con exito" << endl;
    imprimirAbin(uno);

    return 0;
}
