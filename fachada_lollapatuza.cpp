#include "fachada_lollapatuza.h"

map<Producto,vector<int>> FachadaLollapatuza::mapaAVector(map<Producto, map<Nat, Nat>> desc) { //nuestro constructor de Puesto toma un menu, stock..
    map<Producto,vector<int>> descuentos;                                                      //..(como los de Fachada) y descuentos es un mapa<Producto, vector<int>>, esta funcion hace la conversion de descuento
    auto itProducto = desc.begin();
    while(itProducto!=desc.end()) {
        vector<int> v;
        auto itDesc = ((*itProducto).second).begin();
        for(int i=0; i<(*itDesc).first; i++){
            v.push_back(0);
        }
        auto ultElem =((*itProducto).second).end();
        ultElem--;
        while(itDesc!=ultElem){
            auto itSig = itDesc;
            itSig++;
            for(int i=(*itDesc).first; i<(*(itSig)).first; i++){ //i tiene que ser menor a la cantidad que le sigue
                v.push_back((*itDesc).second);
            }
            itDesc++;
        }
        v.push_back((*itDesc).second);
        descuentos[(*itProducto).first]=v;
        v.clear();
        itProducto++;
    }
    return descuentos;
}

FachadaLollapatuza::FachadaLollapatuza(const set<Persona> &personas, const map<IdPuesto, aed2_Puesto> &infoPuestos):lolla(Lollapatuza(std::map<IdPuesto,Puesto>(),personas)) {
    // TODO: Completar
    map<IdPuesto ,aed2_Puesto> p = infoPuestos;
    auto it= p.begin();
    std::map<IdPuesto, Puesto> puestos;
    while(it!=p.end()){
        Puesto pu (p[(*it).first].menu, p[(*it).first].stock, mapaAVector(p[(*it).first].promociones));
        puestos.insert(make_pair((*it).first,pu));
        it++;
    }
    lolla = Lollapatuza(puestos,personas);
}

void FachadaLollapatuza::registrarCompra(Persona persona, Producto producto, Nat cant, IdPuesto idPuesto) {
    // TODO: Completar
    lolla.RegistrarCompra(idPuesto,persona,producto,cant);
    return;
}

void FachadaLollapatuza::hackear(Persona persona, Producto producto) {
    // TODO: Completar
    lolla.Hackear(persona,producto);
    return;
}

Nat FachadaLollapatuza::gastoTotal(Persona persona) const {
    // TODO: Completar
    return lolla.GastoTotal(persona);
}

Persona FachadaLollapatuza::mayorGastador() const {
    // TODO: Completar
    return lolla.PersonaQueMasGasto();
}

IdPuesto FachadaLollapatuza::menorStock(Producto producto) const {
   // TODO: Completar
   return lolla.MenorStockDeItem(producto);
}

const set<Persona> &FachadaLollapatuza::personas() const {
    // TODO: Completar
    return lolla.Personas();
}

Nat FachadaLollapatuza::stockEnPuesto(IdPuesto idPuesto, const Producto &producto) const {
    // TODO: Completar
    auto pu = lolla.PuestosDeComida().find(idPuesto);
    return ((*pu).second).ObtenerStock(producto);
}

Nat FachadaLollapatuza::descuentoEnPuesto(IdPuesto idPuesto, const Producto &producto, Nat cantidad) const {
    // TODO: Completar
    auto pu = lolla.PuestosDeComida().find(idPuesto);
    return ((*pu).second).ObtenerDescuento(producto,cantidad);
}

Nat FachadaLollapatuza::gastoEnPuesto(IdPuesto idPuesto, Persona persona) const {
    // TODO: Completar
    auto pu = lolla.PuestosDeComida().find(idPuesto);
    return ((*pu).second).GastoPorPersona(persona);
}

set<IdPuesto> FachadaLollapatuza::idsDePuestos() const {
    // TODO: Completar
    set<IdPuesto> s;
    auto it= (lolla.PuestosDeComida()).begin();
    while(it!=(lolla.PuestosDeComida()).end()){
        s.insert((*it).first);
        it++;
    }
    return s;
}