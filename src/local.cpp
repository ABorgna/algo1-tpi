#include "local.h"
#include <string.h>
Local::Local(){
    // Leandro
}

Local::Local(const vector< pair <Bebida,Cantidad> > bs, const vector< pair <Hamburguesa,Cantidad> > hs, const vector<Empleado> es){
    // Agustin
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
    // Agustin
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
    // Agustin
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
    // Agustin
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
    // Agustin
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

