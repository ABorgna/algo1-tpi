#include "local.h"
#include <string.h>
Local::Local(){
}

Local::Local(const vector< pair <Bebida,Cantidad> > bs, const vector< pair <Hamburguesa,Cantidad> > hs, const vector<Empleado> es){
}

Cantidad Local::stockBebidasL(const Bebida b) const{
}

Cantidad Local::stockSandwichesL(const Hamburguesa h) const{
}

vector<Bebida>       Local::bebidasDelLocalL() const{
}

vector<Hamburguesa>  Local::sandwichesDelLocalL() const{
}

vector<Empleado>     Local::empleadosL() const{
}

vector<Empleado>     Local::desempleadosL() const{
}

Energia  Local::energiaEmpleadoL(const Empleado e) const{
}

vector<Pedido>       Local::ventasL() const{
}

vector<Empleado> Local::candidatosAEmpleadosDelMesL() const{
}

void Local::venderL(const Pedido p){
}

void Local::sancionL(const Empleado e, const Energia n){
}

void Local::anularPedidoL(int n){
}

void Local::agregarComboAlPedidoL(const Combo c, int n){
}

bool Local::unaVentaCadaUnoL() const{
}

Empleado Local::elVagonetaL() const{
}

void Local::guardar(std::ostream& os) const{
}

void Local::mostrar(std::ostream& os) const{
}

void Local::cargar (std::istream& is){
}

std::ostream & operator<<(std::ostream & os,const Local & l){
}

