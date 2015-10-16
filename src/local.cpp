#include "local.h"
#include <string.h>
#include <algorithm>

Local::Local(){
    // Leandro
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
    // Leandro
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
    // Leandro
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
    // Leandro
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
            pedido = Pedido(pedido.numeroP()+1,
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
    // Leandro
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
    // Leandro
}

std::istream & operator>>(std::istream & is, Local & l){
    l.cargar(is);
    return is;
}

