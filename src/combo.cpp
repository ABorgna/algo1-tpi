#include "combo.h"
#include <string.h>
#include <stdexcept> 

Combo::Combo(){
}

Combo::Combo(const Bebida b, const Hamburguesa h, const Energia d ){
    _bebida = b;
    _sandwich = h;
    _dificultad = d;
}

Bebida      Combo::bebidaC() const{
    return _bebida;
}

Hamburguesa Combo::sandwichC() const{
    return _sandwich;
}

Energia     Combo::dificultadC() const{
    return _dificultad;
}

void Combo::mostrar(std::ostream& os) const{
     os<<"Bebida: "<<bebidaC()<<endl;
     os<<"Sandwich: "<<sandwichC()<<endl;
     os<<"Dificultad: "<<dificultadC();
}

void Combo::guardar(std::ostream& os) const{
    os << '{'<<" "
       << (char)ENCABEZADO_ARCHIVO<<" "
       << _bebida<<" "
       << _sandwich<<" "
       << _dificultad<<" "
       << '}';
}

void Combo::cargar (std::istream& is){
    char head;

    is >> head; //Inicio {

    is >> head;
    if (head != ENCABEZADO_ARCHIVO){
        throw std::invalid_argument("Encabezado inválido");
    }
    is >> _bebida
       >> _sandwich
       >> _dificultad
       >> head; //Fin }
}

bool Combo::operator==(const Combo& otroCombo) const{
    return _sandwich == otroCombo.sandwichC() &&
           _bebida == otroCombo.bebidaC() &&
           _dificultad == otroCombo.dificultadC();
}

std::ostream & operator<<(std::ostream & os,const Combo & c){
    c.mostrar(os);
    return os;
}

std::ostream & operator<<(std::ostream & os,const Hamburguesa & h){
    os << HAMBURGUESA_STR[h];
    return os;
}

std::ostream & operator<<(std::ostream & os,const Bebida & b){
    os << BEBIDA_STR[b];
    return os;
}

std::istream & operator>>(std::istream & is, Combo & c){
    c.cargar(is);
    return is;
}

std::istream & operator>>(std::istream & is, Hamburguesa & c){
    string s;
    is >> s;
    for(int i=0; i<=MaxH; i++){
        if(HAMBURGUESA_STR[i] == s){
            c = (Hamburguesa)i;
            break;
        }
    }
    return is;
}

std::istream & operator>>(std::istream & is, Bebida & b){
    string s;
    is >> s;
    for(int i=0; i<=MaxB; i++){
        if(BEBIDA_STR[i] == s){
            b = (Bebida)i;
            break;
        }
    }
    return is;
}

