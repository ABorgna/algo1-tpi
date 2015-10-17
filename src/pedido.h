#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

#include <vector>
#include <stdexcept>
#include "tipos.h"
#include "combo.h"
#include "auxiliar.h"

class Pedido {

    public:

        Pedido();
        Pedido(const int n, const Empleado e, const vector<Combo> cs);

        int             numeroP() const;
        Empleado        atendioP() const;
        vector<Combo>    combosP() const;

                Energia dificultadP() const;

        void  agregarComboP(const Combo c);
        void  anularComboP(int i);
        void  cambiarBebidaComboP(const Bebida b, int i);
        void  elMezcladitoP();

        void mostrar(std::ostream& os) const;
        void guardar(std::ostream& os) const;
        void cargar (std::istream& is);

        bool operator==(const Pedido& otroPedido) const;

    private:

        vector<Combo> _combos;
        Empleado     _atendio;
        int          _numero;

        enum {ENCABEZADO_ARCHIVO = 'P'};

};

// Auxiliares
int countBebidasP(const Pedido&, Bebida);
int countSandwichesP(const Pedido&, Hamburguesa);

// Definirlo usando mostrar, para poder usar << con este tipo.
std::ostream & operator<<(std::ostream & os,const Pedido & p);
std::istream & operator>>(std::istream & is, Pedido & p);

#endif // PEDIDO_H_INCLUDED
