#include "pedido.h"
#include <algorithm>

Pedido::Pedido() : Pedido(1,"",vector<Combo>(1)){}

Pedido::Pedido(const int nro, const Empleado e, const vector<Combo> combos){
    _numero = nro;
    _atendio = e;
    _combos = combos;
}

int Pedido::numeroP() const{
    return _numero;
}

Empleado Pedido::atendioP() const{
    return _atendio;
}

vector<Combo> Pedido::combosP() const{
    return _combos;
}

Energia Pedido::dificultadP() const{
    int n=combosP().size();
    int sum=0;
    int i=0;
    while(i<n){
		sum=sum+combosP()[i].dificultadC();
		i++;
	}
	return sum;
}

void  Pedido::agregarComboP(const Combo c){
    _combos.push_back(c);
}

void  Pedido::anularComboP(int i){
    _combos.erase(_combos.begin()+i);
}

void  Pedido::cambiarBebidaComboP(const Bebida b, int i){
    Combo old = _combos[i];
    _combos[i] = Combo(b,old.sandwichC(),old.dificultadC());
}

void  Pedido::elMezcladitoP(){
    //Sofia    
}

void Pedido::mostrar(std::ostream& os) const{
    os<<"Numero de pedido: "<<numeroP()<<endl;
     os<<"Empleado que atendio el pedido: "<<atendioP()<<endl;
     os<<"Los combos que integran el pedido son: "<<endl;
     for (int i=0;i<combosP().size();i++){
     os<<"Sandwich: "<<combosP()[i].sandwichC()<<" Bebida: "<<combosP()[i].bebidaC()<<" Dificultad: "<<combosP()[i].dificultadC()<<endl;
     }
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
    return atendioP() == otroPedido.atendioP() &&
           numeroP() == otroPedido.numeroP() &&
           combosP() == otroPedido.combosP();
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
    p.mostrar(os);
    return os;
}

std::istream & operator>>(std::istream & is, Pedido & p){
    p.cargar(is);
    return is;
}

