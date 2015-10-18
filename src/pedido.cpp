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
    return _atendio;
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
    _combos.erase(_combos.begin()+i);
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
    os << '{'
       << ENCABEZADO_ARCHIVO
       << _numero
       << _atendio
       << _combos
       << '}';
}

void Pedido::cargar (std::istream& is){
    is.ignore(0xff,'{'); // "  {"
    trimIS(is);

    if(is.get() != ENCABEZADO_ARCHIVO){
        throw std::invalid_argument("Encabezado inválido");
    }
    is >> _numero
       >> _atendio
       >> _combos;

    is.ignore(0xff,'}'); // "  }"
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

std::istream & operator>>(std::istream & is, Pedido & p){
    p.cargar(is);
    return is;
}

