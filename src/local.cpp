#include "local.h"
#include <string.h>
#include <algorithm>

vector<Pedido> pedidosDelEmpleado();
int maxDescansoEmplado(Empleado);

Local::Local(){
    _bebidas = pair<Bebida,Cantidad>(PestiCola,0);
    _empleados = pair<Empleado,Cantidad>("",100);
    _sandwiches = pair<Hamburguesa,Cantidad>(MacPato,0);
    _ventas = vector<Pedido>(1);
}

Local::Local(const vector< pair<Bebida,Cantidad> > bs,
             const vector< pair<Hamburguesa,Cantidad> > hs,
             const vector<Empleado> es) {
    _bebidas = bs;
    _sandwiches = hs;

    _empleados.reserve(es.size());
    for(auto &i : es){
        _empleados.push_back(pair<Empleado,Energia>(i,100));
    }
}

Cantidad Local::stockBebidasL(const Bebida b) const{
    // Sofia
}

Cantidad Local::stockSandwichesL(const Hamburguesa h) const{
    // Alejo
}

vector<Bebida>       Local::bebidasDelLocalL() const{
    vector<Bebida> res;
    res.reserve(_bebidas.size());
    for (Bebida &i : _bebidas){
        res.push_back(i.first);
    }
    return res;
}

vector<Hamburguesa>  Local::sandwichesDelLocalL() const{
    vector<Hamburguesa> v;
    v.reserve(_sandwiches.size());
    for(auto &i : _sandwiches){
        v.push_back(i.first);
    }
    return v;
}

vector<Empleado>     Local::empleadosL() const{
    // Sofia
}

vector<Empleado>     Local::desempleadosL() const{
    // Alejo
}

Energia  Local::energiaEmpleadoL(const Empleado e) const{
    for (auto &i : _empleados)
        if (i.first == Empleado)
            return i.second;
}

vector<Pedido>       Local::ventasL() const{
    return _ventas;
}

vector<Empleado> Local::candidatosAEmpleadosDelMesL() const{
    // Sofia
}

void Local::venderL(const Pedido p){
    // Alejo
}

void Local::sancionL(const Empleado e, const Energia n){
    for (auto &i : _empleados)
        if (i.first == e)
            i.second -= n;
}

void Local::anularPedidoL(int n){
    auto esNumeroN = [n](Pedido p){return p.numeroP() == n;};
    auto itPedido = find_if(_ventas.begin(),_ventas.end(),esNumeroN);

    // Modificar energia y stock
    for(auto &empleado : _empleados){
        if(empleado.first == itPedido->atendioP())
            empleado.second += itPedido->dificultadP();
    }
    for(auto &bebida : _bebidas){
        bebida.second += countBebidasP(*itPedido,bebida.first);
    }
    for(auto &sandwich : _sandwiches){
        sandwich.second += countSandwichesP(*itPedido,sandwich.first);
    }

    // Cambiar los numeros de pedido
    for(Pedido &pedido : _ventas){
        if(pedido.numeroP() > n)
            pedido = Pedido(pedido.numeroP()-1,
                            pedido.atendioP(),
                            pedido.combosP());
    }

    _ventas.erase(itPedido);
}

void Local::agregarComboAlPedidoL(const Combo c, int n){
    // Sofia
}

bool Local::unaVentaCadaUnoL() const{
    // Alejo
}

Empleado Local::elVagonetaL() const{
    vector< pair<Empleado,int> > empYdes = empleadoYdescanso();
    int i = 1, n = emp.size();
    int vago = 0;
    while (i < n){
        if (empYdes[i].second > empYdes[vago].second)
            vago = i;
        i++;
    }
    return empYdes[vago].first;
}

void Local::guardar(std::ostream& os) const{
    os << "{ " << (char)ENCABEZADO_ARCHIVO << " "
       << _bebidas << " "
       << _sandwiches << " "
       << _empleados << " "
       << _ventas << " }";
}

void Local::mostrar(std::ostream& os) const{
    // Sofia
}

void Local::cargar (std::istream& is){
    // Alejo
}

std::ostream & operator<<(std::ostream & os,const Local & l){
    l.mostrar(os);
    return os;
}

std::istream & operator>>(std::istream & is, Local & l){
    l.cargar(is);
    return is;
}


//Shhhh aca no pasa nada
vector<Pedido> pedidosDelEmpleado(Empleado e){
    vector<Pedido> res = vector<Pedido>(1);
    for (auto &i : _ventas)
        if (i.atendioP()==e)
            res.push_back(i);
    return res;
}

int maxDescansoEmplado(Empleado e){
    vector<Pedido> pedidos = pedidosDelEmpleado(e);
    vector<int> numVen = numsVentas();
    int maxDescanso = pedidos[0].numeroP() - _ventas[0].numeroP();
    for (int i = 1; i < pedidos.size(); i++)
        maxDescanso = max(pedidos[i].numeroP() - pedidos[i-1].numeroP(),maxDescanso);
    maxDescanso = max(pedidos.back().numeroP() - _ventas.back().numeroP(),maxDescanso);
    return maxDescanso;
}

vector< pair<Empleado, int> > empleadoYdescanso()
{
    vector< pair<Empleado,int> > res;
    vector<Empleado> emp = empleadosL();
    res.reserve(emp.size());
    for(auto &i : emp)
        res.push_back(pair<Empleado,int>(i,maxDescanso(i)));
    return res;
}