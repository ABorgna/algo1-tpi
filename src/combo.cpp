#include "combo.h"
#include <string.h>

Combo::Combo() : Combo(PestiCola,McGyver,0) {}

Combo::Combo(const Bebida b, const Hamburguesa h, const Energia d ){
    // Sofia
}

Bebida      Combo::bebidaC() const{
    // Alejo
}

Hamburguesa Combo::sandwichC() const{
    // Leandro
}

Energia     Combo::dificultadC() const{
    return _dificultad;
}

void Combo::mostrar(std::ostream& os) const{
    // Sofia
}

void Combo::guardar(std::ostream& os) const{
    // Alejo
}

void Combo::cargar (std::istream& is){
    // Leandro
}

bool Combo::operator==(const Combo& otroCombo) const{
    return _sandwich == otroCombo.sandwichC() &&
           _bebida == otroCombo.bebidaC() &&
           _dificultad == otroCombo.dificultadC();
}

std::ostream & operator<<(std::ostream & os,const Combo & c){
    // Sofia
}

std::ostream & operator<<(std::ostream & os,const Hamburguesa & h){
    // Alejo
}

std::ostream & operator<<(std::ostream & os,const Bebida & b){
    // Leandro
}

