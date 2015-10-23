#include "pedido.h"
#include <algorithm>
vector<Combo> combosDelPedidoSinRep (const Pedido *p);
vector<Combo> combosRepetidos (const Pedido *p);
vector<Bebida> bebidasDelPedidoSinRep (const Pedido *p);
vector<Hamburguesa> sandwichesDelPedidoSinRep (const Pedido *p);
bool estaC(const Combo c, const vector<Combo> cs);
void cambiarBebida (Combo &c, const vector<Bebida> bs);
void cambiarSandwich (Combo &c, const vector<Hamburguesa> hs);

Pedido::Pedido(){
}

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
	int t = combosP().size();
	vector<Combo> res = combosDelPedidoSinRep (this);
	for(auto &i : combosRepetidos(this)){
		int j=0;
		int n = bebidasDelPedidoSinRep(this).size();
		int m = sandwichesDelPedidoSinRep(this).size();
		while (j<n){
			int k=0;
			Hamburguesa s=i.sandwichC();
			while (k<m){
				cambiarSandwich(i,sandwichesDelPedidoSinRep(this));
					if (estaC(i,res)){
						k++;
					}
					else{
						res.push_back(i);
						k=m;
					}
				}
			
			if (i.sandwichC()==s){
				cambiarBebida(i,bebidasDelPedidoSinRep(this));
				if (estaC(i,res)){
					j++;
				}
				else{
					res.push_back(i);
					j=n;
				}
			}
			else{
				j=n;
			}
		}
	}
	int a;
	for(a=0;a<t;a++){
	_combos[a]=res[a];
	}
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
    os << '{' << " "
       << (char)ENCABEZADO_ARCHIVO << " "
       << _numero << " "
       << _atendio << " [ ";
    for (auto &c : _combos){
        c.guardar(os);
        os << " ";
    }
    os << "] }";
}

void Pedido::cargar (std::istream& is){
    char aux;
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

bool estaC(const Combo c, const vector<Combo> cs){
int i = 0;
int n = cs.size();
while (i < n && (cs[i].bebidaC() != c.bebidaC() || cs[i].sandwichC() != c.sandwichC())){
i = i + 1;
}
return i < n;
}

bool estaB(const Bebida b, const vector<Bebida> bs){
int i = 0;
int n = bs.size();
while (i < n && bs[i] != b){
i = i + 1;
}
return i < n;
}

bool estaS(const Hamburguesa h, const vector<Hamburguesa> hs){
int i = 0;
int n = hs.size();
while (i < n && hs[i] != h){
i = i + 1;
}
return i < n;
}

vector<Bebida> bebidasDelPedido (const Pedido *p){
    vector<Bebida> res;
    res.reserve(p->combosP().size());
    for (auto &i : p->combosP()){
		res.push_back(i.bebidaC());
        }
    return res;
}

vector<Bebida> bebidasDelPedidoSinRep (const Pedido *p){
    vector<Bebida> res;
    res.reserve(bebidasDelPedido(p).size());
    for (auto &i : bebidasDelPedido(p)){
		if (!estaB(i,res)){
		res.push_back(i);
        }
	}
    return res;
}

vector<Hamburguesa> sandwichesDelPedido (const Pedido *p){
    vector<Hamburguesa> res;
    res.reserve(p->combosP().size());
    for (auto &i : p->combosP()){
		res.push_back(i.sandwichC());
        }
    return res;
}

vector<Hamburguesa> sandwichesDelPedidoSinRep (const Pedido *p){
    vector<Hamburguesa> res;
    res.reserve(sandwichesDelPedido(p).size());
    for (auto &i : sandwichesDelPedido(p)){
		if (!estaS(i,res)){
		res.push_back(i);
        }
	}
    return res;
}

vector<Combo> combosDelPedidoSinRep (const Pedido *p){
    vector<Combo> res;
    res.reserve(p->combosP().size());
    for (auto &i : p->combosP()){
		if (!estaC(i,res)){
		res.push_back(i);
        }
	}
    return res;
}

vector<Combo> combosRepetidos (const Pedido *p){
    vector<Combo> res;
    vector<Combo> aux = p->combosP();
    int n = p->combosP().size();
    int i =0;
    while (i<n){
		aux.erase(aux.begin()+i);
		if (estaC(p->combosP()[i],aux)){
		res.push_back(p->combosP()[i]);
		i++;
		}
        else{
			i++;
        }
	}
    return res;
}

void cambiarBebida (Combo &c, const vector<Bebida> bs){
	int n = bs.size();
	int i = 0;
	while (i<n)
		if (c.bebidaC()==bs[i]){
			c= Combo(bs[(i+1) % n],c.sandwichC(), c.dificultadC()); 
			i=n;
		}
		else{
			i++;
		}
}

void cambiarSandwich (Combo &c, const vector<Hamburguesa> hs){
	int n = hs.size();
	int i = 0;
	while (i<n)
		if (c.sandwichC()==hs[i]){
			c= Combo(c.bebidaC(),hs[(i+1) % n], c.dificultadC()); 
			i=n;
		}
		else{
			i++;
		}
}

std::ostream & operator<<(std::ostream & os,const Pedido& p){
    p.mostrar(os);
    return os;
}

std::istream & operator>>(std::istream & is, Pedido & p){
    p.cargar(is);
    return is;
}


