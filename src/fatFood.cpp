#include <vector>
#include <iostream>
#include <utility>
#include "interfaz.h"
#include "local.h"

using namespace std;

int main(){
    Local l(
        vector<pair<Bebida,Cantidad>> {{PestiCola,5}},
        vector<pair<Hamburguesa,Cantidad>> {{McGyver,5}},
        vector<Empleado> {"Hello"}
    );

    //l.guardar(cout);
    MenuPrincipal();
    return 0;
}
