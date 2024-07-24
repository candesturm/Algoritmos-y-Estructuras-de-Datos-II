#include "puesto.h"

Puesto::Puesto(const Menu &menu, Stock &stock, const std::map<Producto, std::vector<int>> &desc): _menu(menu),_stock(stock),_desc(desc){

}

int Puesto::ObtenerStock(Producto item) const {
    auto a = _stock.find(item);
    int const& c = (*a).second;
    return c;
}

int Puesto::ObtenerDescuento(Producto item, int cant) const {
    if(_desc.count(item) == 1) {
        vector<int> vecDesc = _desc.at(item);
        if (cant >= vecDesc.size() - 1) {
            return vecDesc[vecDesc.size() - 1];
        } else {
            return vecDesc[cant];
        }
    } else{
        return 0;
    }
}

int Puesto::ObtenerPrecio(Producto item) const {
    return _menu.at(item);
}

void Puesto::Vender(Persona per, Producto item, int cant) {
    Nat precio= _menu[item];
    int desc= ObtenerDescuento(item,cant);
    int st= ObtenerStock(item);
    _stock[item]=(st - cant);
    int gasto= precio * cant - (precio * cant * desc)/100;
    if(_gastoxPersona.count(per)!=0){
        int gastoPer=_gastoxPersona[per];
        _gastoxPersona[per]=(gastoPer + gasto);
        _ventas[per].emplace_back(make_pair(item,cant));
        list<pair<int,int>>::iterator it = --_ventas[per].end();
        if(desc == 0){
            (_ventasSinDesc[per])[item].emplace_back(it);
        }
    }else{
        _gastoxPersona[per]=gasto;
        list<pair<Producto,int>>v;
        v.clear();
        _ventas[per]=v;
        _ventas[per].push_back(make_pair(item,cant));
        std::list<pair<Producto,int>>::iterator it2= _ventas[per].end();
        it2--;
        if(desc == 0){
            _ventasSinDesc[per][item].emplace_back(it2);
        }
    }
    return;
}

int Puesto::GastoPorPersona(Persona per) const {
    if(_gastoxPersona.count(per)==1){
        return _gastoxPersona.at(per);
    }else{
        return 0;
    }
}

bool Puesto::esHackeable(Producto item, Persona per) const {
    if(_ventasSinDesc.count(per)==1){
        if(_ventasSinDesc.at(per).count(item)!=0){
            return !_ventasSinDesc.at(per).at(item).empty();
        }
    }
    return false;
}

void Puesto::HackearPuesto(Producto item, Persona per) {
    auto it= (_ventasSinDesc[per][item]).begin(); //me da la primer venta sin descuento de la persona en ese item

        int stockAnt = ObtenerStock(item);
        _stock[item]= stockAnt + 1;
        int precio= _menu[item];
        int gastoPuestoAnt= _gastoxPersona[per];

        if(gastoPuestoAnt == precio){
            _gastoxPersona.erase(per);
        }else{
            _gastoxPersona[per] = gastoPuestoAnt - precio;
        }

        if((**it).second == 1){ //si la cantidad de la venta era 1 elimina esa venta de ventas sin descuento y de ventas
            _ventas[per].erase(*it);
            _ventasSinDesc[per][item].pop_front();
        }else{
            pair<Producto,int> s = **it; //sino elimina en una unidad la cantidad de la venta
            (**it).second= s.second-1;

        }
        return;
}