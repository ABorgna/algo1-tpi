#include "local.h"
#include <string.h>
#include <algorithm>

vector<Pedido> pedidosDelEmpleado();
int maxDescansoEmplado(Empleado);
vector< pair<Empleado, int> > empleadoYdescanso(const Local *l);
vector< pair <Empleado, Energia> > empleadosYenegiaL(const Local *l);
vector<Empleado> empleadosConMasVentas(const Local *l);
int maxCantPedidos(const Local *l);
int maxCantCombos(const Local *l);
vector<Combo> combosDelEmpleado(const Local *l,Empleado e);
	
Local::Local() {
    _bebidas = vector<pair<Bebida,Cantidad> >{{PestiCola,0}};
    _empleados = vector<pair<Empleado,Cantidad> >{{"",100}};
    _sandwiches = vector<pair<Hamburguesa,Cantidad> >{{McPato,0}};
    _ventas = vector<Pedido>(1);
}

Local::Local(const vector< pair<Bebida,Cantidad> > bs,
             const vector< pair<Hamburguesa,Cantidad> > hs,
             const vector<Empleado> es) {
    _bebidas = bs;
    _sandwiches = hs;

    _empleados.reserve(es.size());
    for(auto &i : es){
        _empleados.push_back(pair<Empleado,Energia>(i,100));
    }
}

Cantidad Local::stockBebidasL(const Bebida b) const{
    int n = _bebidas.size();
    int i = 0;
    int stock;
    while (i<n){
		if (_bebidas[i].first != b){
			i++;
		}
		else{
			stock= _bebidas[i].second;
			i=n;
		}
	}	
	return stock;	
}

Cantidad Local::stockSandwichesL(const Hamburguesa h) const{
    // Alejo
}

vector<Bebida>       Local::bebidasDelLocalL() const{
    vector<Bebida> res;
    res.reserve(_bebidas.size());
    for (auto &i : _bebidas){
        res.push_back(i.first);
    }
    return res;
}

vector<Hamburguesa>  Local::sandwichesDelLocalL() const{
    vector<Hamburguesa> v;
    v.reserve(_sandwiches.size());
    for(auto &i : _sandwiches){
        v.push_back(i.first);
    }
    return v;
}

vector<Empleado>     Local::empleadosL() const{
    vector<Empleado> res;
    res.reserve(_empleados.size());
    for (auto &i : _empleados){
		if(i.second>=0){
		res.push_back(i.first);
        }
    }
    return res;
}

	
vector<Empleado>     Local::desempleadosL() const{
	 // Alejo
}

Energia  Local::energiaEmpleadoL(const Empleado e) const{
    for (auto &i : _empleados)
        if (i.first == e)
            return i.second;
}

vector<Pedido>       Local::ventasL() const{
    return _ventas;
}

vector<Empleado> Local::candidatosAEmpleadosDelMesL() const{
	vector<Empleado> res;
	vector<Empleado> emp = empleadosConMasVentas(this);
	int n = emp.size();
    int i = 0;
	while (i<n){
		if (combosDelEmpleado(this,emp[i]).size() == maxCantCombos(this)){
		res.push_back(emp[i]);
		i++;
		}
		else{
		i++;
		}
	}
	return res;
}

void Local::venderL(const Pedido p){
    // Alejo
}

void Local::sancionL(const Empleado e, const Energia n){
    for (auto &i : _empleados)
        if (i.first == e)
            i.second -= n;
}

void Local::anularPedidoL(int n){
    auto esNumeroN = [n](Pedido p){return p.numeroP() == n;};
    auto itPedido = find_if(_ventas.begin(),_ventas.end(),esNumeroN);

    // Modificar energia y stock
    for(auto &empleado : _empleados){
        if(empleado.first == itPedido->atendioP())
            empleado.second += itPedido->dificultadP();
    }
    for(auto &bebida : _bebidas){
        bebida.second += countBebidasP(*itPedido,bebida.first);
    }
    for(auto &sandwich : _sandwiches){
        sandwich.second += countSandwichesP(*itPedido,sandwich.first);
    }

    // Cambiar los numeros de pedido
    for(Pedido &pedido : _ventas){
        if(pedido.numeroP() > n)
            pedido = Pedido(pedido.numeroP()-1,
                            pedido.atendioP(),
                            pedido.combosP());
    }

    _ventas.erase(itPedido);
}

void Local::agregarComboAlPedidoL(const Combo c, int n){
    Pedido p;
    int m = ventasL().size();
    int i=0;
    int j=0;
    while (i<m){
		if (ventasL()[i].numeroP()==n){
			p=ventasL()[i];
			j=i;
			i=n;
		}
		else{
			i++;
		}
	}
	stockBebidasL(c.bebidaC())-1;
    stockSandwichesL(c.sandwichC())-1;
    energiaEmpleadoL(p.atendioP())-c.dificultadC();
    p.combosP().push_back(c);    
	ventasL()[j]=p;
}

bool Local::unaVentaCadaUnoL() const{
    // Alejo
}

Empleado Local::elVagonetaL() const{
    vector< pair<Empleado,int> > empYdes = empleadoYdescanso(this);
    int i = 1, n = empYdes.size();
    int vago = 0;
    while (i < n){
        if (empYdes[i].second > empYdes[vago].second)
            vago = i;
        i++;
    }
    return empYdes[vago].first;
}

void Local::guardar(std::ostream& os) const{
    os << "{ " << (char)ENCABEZADO_ARCHIVO << " "
       << _bebidas << " "
       << _sandwiches << " "
       << _empleados << " "
       << _ventas << " }";
}


    
void Local::mostrar(std::ostream& os) const{
     os<<"Bebidas del local y su stock: "<<_bebidas<<endl;
     os<<"Sandwiches del local y su stock: "<<_sandwiches<<endl;
     os<<"Empleados del local y su energía: "<<empleadosYenegiaL(this)<<endl;
     os<<"Desempleados del local: "<<desempleadosL()<<endl;
     os<<"Ventas de local: "<<ventasL();
}

void Local::cargar (std::istream& is){
    // Alejo
}

std::ostream & operator<<(std::ostream & os,const Local & l){
    l.mostrar(os);
    return os;
}

std::istream & operator>>(std::istream & is, Local & l){
    l.cargar(is);
    return is;
}


//Shhhh aca no pasa nada
vector<Pedido> pedidosDelEmpleado(const Local *l,Empleado e){
    vector<Pedido> res = vector<Pedido>(1);
    for (auto &i : l->ventasL())
        if (i.atendioP()==e)
            res.push_back(i);
    return res;
}

int maxDescansoEmpleado(const Local *l,Empleado e){
    vector<Pedido> pedidos = pedidosDelEmpleado(l,e);
    int maxDescanso = pedidos[0].numeroP() - l->ventasL()[0].numeroP();
    for (int i = 1; i < pedidos.size(); i++)
        maxDescanso = max(pedidos[i].numeroP() - pedidos[i-1].numeroP(),maxDescanso);
    maxDescanso = max(pedidos.back().numeroP() - l->ventasL().back().numeroP(),maxDescanso);
    return maxDescanso;
}

vector< pair<Empleado, int> > empleadoYdescanso(const Local *l)
{
    vector< pair<Empleado,int> > res;
    vector<Empleado> emp = l->empleadosL();
    res.reserve(emp.size());
    for(auto &i : emp)
	    res.push_back(pair<Empleado,int>(i,maxDescansoEmpleado(l,i)));
    return res;
}

vector< pair <Empleado, Energia> >  empleadosYenegiaL(const Local *l){
    vector< pair <Empleado, Energia> >  res;
    vector<Empleado> emp = l->empleadosL();
    res.reserve(emp.size());
    for (auto &i : emp)
		res.push_back(pair<Empleado,Energia>(i,l->energiaEmpleadoL(i)));
    return res;
}
vector<Empleado> empleadosConMasVentas(const Local *l){
	vector<Empleado> res;
	vector<Empleado> emp = l->empleadosL();
	int n = emp.size();
	int i = 0;
	while (i<n){
		if (pedidosDelEmpleado(l,emp[i]).size() == maxCantPedidos(l)){
		res.push_back(emp[i]);
		i++;
		}
		else{
		i++;
		}
	}
	return res;
}

int maxCantPedidos(const Local *l){
	int res;
	vector<Empleado> emp = l->empleadosL();
	int n = emp.size();
	int i=1;
	Empleado e = emp[0];
	while (i<n){
		if (pedidosDelEmpleado(l,emp[i]).size() >= pedidosDelEmpleado(l,e).size()){
			e=emp[i];
			i++;
		}
		else{
			i++;
		}
	}
	res = pedidosDelEmpleado(l,e).size();
	return res;
}

int maxCantCombos(const Local *l){
	int res;
	vector<Empleado> emp = empleadosConMasVentas(l);
	int n = emp.size();
	int i=1;
	Empleado e = emp[0];
	while (i<n){
		if (combosDelEmpleado(l,emp[i]).size() >= combosDelEmpleado(l,e).size()){
			e=emp[i];
			i++;
		}
		else{
			i++;
		}
	}
	res = combosDelEmpleado(l,e).size();
	return res;
}

vector<Combo> combosDelEmpleado(const Local *l,Empleado e){
    vector<Combo> res = vector<Combo>(1);
    for (auto &i : l->ventasL())
        if (i.atendioP()==e)
            for (auto &j : i.combosP())
				res.push_back(j);
    return res;
}


