#include "pedido.h"
#include <algorithm>

Pedido::Pedido() : Pedido(1,"",vector<Combo>(1)){}

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
    return _combos;
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
    Combo old = _combos[i];
    _combos[i] = Combo(b,old.sandwichC(),old.dificultadC());
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

// Auxiliares
int countBebidasP(const Pedido& p, Bebida b){
    int count = 0;
    for(auto &c : p.combosP()){
        if(c.bebidaC() == b)
            count++;
    }
    return count;
}

int countSandwichesP(const Pedido& p, Hamburguesa s){
    int count = 0;
    for(auto &c : p.combosP()){
        if(c.sandwichC() == s)
            count++;
    }
    return count;
}

std::ostream & operator<<(std::ostream & os,const Pedido& p){
    // Alejo
}

