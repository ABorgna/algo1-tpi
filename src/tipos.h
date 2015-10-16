#ifndef TIPOS_H
#define TIPOS_H

#include <vector>
#include <stdlib.h>

#include <string>
#include <iostream>

using namespace std;
typedef string Empleado;
typedef int Energia;
typedef int Cantidad;

static const char* BEBIDA_STR[] = 
    {"PestiCola","FalsaNaranja","SeVeNada", "AguaConGags","AguaSinGags"};
static const char* HAMBURGUESA_STR[] = 
    {"McGyver","CukiQueFresco","McPato","BigMacabra"};

enum Bebida{PestiCola, FalsaNaranja, SeVeNada, AguaConGags, AguaSinGags};
enum Hamburguesa{McGyver, CukiQueFresco, McPato, BigMacabra};

#define MaxH 3
#define MaxB 4

#endif /*TIPOS_H*/
