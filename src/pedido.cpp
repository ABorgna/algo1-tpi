#include "pedido.h"
#include <algorithm>
Pedido::Pedido(){
}

Pedido::Pedido(const int nro, const Empleado e, const vector<Combo> combos){
}

int Pedido::numeroP() const{
}

Empleado Pedido::atendioP() const{
}

vector<Combo> Pedido::combosP() const{
}

Energia Pedido::dificultadP() const{
}

void  Pedido::agregarComboP(const Combo c){
}

void  Pedido::anularComboP(int i){
}

void  Pedido::cambiarBebidaComboP(const Bebida b, int i){
}

void  Pedido::elMezcladitoP(){
}

void Pedido::mostrar(std::ostream& os) const{
}

void Pedido::guardar(std::ostream& os) const{
}

void Pedido::cargar (std::istream& is){
}

bool Pedido::operator==(const Pedido& otroPedido) const{
}

std::ostream & operator<<(std::ostream & os,const Pedido& p){
}

