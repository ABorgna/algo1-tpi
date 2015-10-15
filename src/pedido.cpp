#include "pedido.h"
#include <algorithm>
Pedido::Pedido(){
    // Agustin
}

Pedido::Pedido(const int nro, const Empleado e, const vector<Combo> combos){
    // Sofia
}

int Pedido::numeroP() const{
    // Alejo
}

Empleado Pedido::atendioP() const{
    // Leandro
}

vector<Combo> Pedido::combosP() const{
    // Agustin
}

Energia Pedido::dificultadP() const{
    // Sofia
}

void  Pedido::agregarComboP(const Combo c){
    // Alejo
}

void  Pedido::anularComboP(int i){
    // Leandro
}

void  Pedido::cambiarBebidaComboP(const Bebida b, int i){
    // Agustin
}

void  Pedido::elMezcladitoP(){
    // Sofia
}

void Pedido::mostrar(std::ostream& os) const{
    // Alejo
}

void Pedido::guardar(std::ostream& os) const{
    // Leandro
}

void Pedido::cargar (std::istream& is){
    // Agustin
}

bool Pedido::operator==(const Pedido& otroPedido) const{
    // Sofia
}

std::ostream & operator<<(std::ostream & os,const Pedido& p){
    // Alejo
}

