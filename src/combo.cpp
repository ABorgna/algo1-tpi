#include "combo.h"
#include <string.h>
Combo::Combo(){
}

Combo::Combo(const Bebida b, const Hamburguesa h, const Energia d ){
}

Bebida      Combo::bebidaC() const{
}

Hamburguesa Combo::sandwichC() const{
}

Energia     Combo::dificultadC() const{
}

void Combo::mostrar(std::ostream& os) const{
}

void Combo::guardar(std::ostream& os) const{
}

void Combo::cargar (std::istream& is){
}

bool Combo::operator==(const Combo& otroCombo) const{
}

std::ostream & operator<<(std::ostream & os,const Combo & c){
}

std::ostream & operator<<(std::ostream & os,const Hamburguesa & h){
}

std::ostream & operator<<(std::ostream & os,const Bebida & b){
}

