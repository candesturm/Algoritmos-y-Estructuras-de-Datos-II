#include "lollapatuza.h"
#include "puesto.h"

Lollapatuza::Lollapatuza(std::map<IdPuesto, Puesto> ps, std::set<Persona> per): _personas(per), _puestos(ps){
    _personaQMasGasto = *_personas.begin();
}

void Lollapatuza::RegistrarCompra(IdPuesto id, Persona p, Producto i, int c) {
    auto it5 = _puestos.find(id);
    Puesto* pu = &(it5->second); //usamos it5 para obtener el puntero a puesto
    int precio = pu->ObtenerPrecio(i);
    int desc = pu->ObtenerDescuento(i,c);
    int gasto = precio * c - (precio * c * desc)/100;
    pu->Vender(p,i,c);

    if(_gastoTotal.count(p)==1){
        int gastoAnterior= _gastoTotal[p];
        _gastoTotal[p] = gastoAnterior + gasto;
    }else{
        _gastoTotal[p] = gasto;
    }
    int gastoAnterior = _gastoTotal[p] - gasto; //declaramos gastoAnterior fuera del if para que sea una variable global
    if(_GTxPrecio.count(gastoAnterior)==1){
        _GTxPrecio[gastoAnterior].erase(p);
        if(_GTxPrecio[gastoAnterior].empty()){
            _GTxPrecio.erase(gastoAnterior);
        }
    }

    _GTxPrecio[gastoAnterior + gasto][p]=0; //lineas 20-23 tp2

    if(desc == 0){
        _puestosHackeables[p][i][id]= pu; //lineas 25-36
    }

    auto it= _GTxPrecio.end();
    it--;//it a la clave maxima (o sea la ultima)
    auto it2 = ((*it).second).begin(); //it a la minima clave (o sea la primera)
    _personaQMasGasto = (*it2).first;

    return;

}

int Lollapatuza::GastoTotal(Persona p) const{
    if(_gastoTotal.count(p)==1){
        auto a = _gastoTotal.find(p);
        int const& c = (*a).second;
        return c;
    }else{
        return 0;
    }
}

Persona Lollapatuza::PersonaQueMasGasto()const {
    return _personaQMasGasto;
}

IdPuesto Lollapatuza::MenorStockDeItem(Producto i) const {
     auto it= _puestos.begin();
     Puesto min = it->second;
     IdPuesto idMin = it->first; //agregamos idMin para hcer las comparaciones mas facil, no agrega complejidad extra al algoritmo
     while(it!= _puestos.end()){
         int stockIt = ((*it).second).ObtenerStock(i);
         int stockMin= min.ObtenerStock(i);
         if(stockIt < stockMin){
             min = (*it).second;
             idMin = (*it).first;
         }
         it++;
     }
    return idMin;
}

void Lollapatuza::Hackear(Persona p, Producto i) {
    auto it = (_puestosHackeables[p][i]).begin(); //it nos da el puesto hackeable de menor id
    Puesto* pu = (*it).second; //puntero al puesto de it
    pu->HackearPuesto(i,p);
    int gastoAnterior = _gastoTotal[p];
    int precio = pu->ObtenerPrecio(i);

    if(gastoAnterior == precio){
        _gastoTotal.erase(p);
    }else{
        _gastoTotal[p]= gastoAnterior - precio;
        _GTxPrecio[gastoAnterior].erase(p);
    }

    if(_GTxPrecio[gastoAnterior].empty()){
        _GTxPrecio.erase(gastoAnterior);
    }

    _GTxPrecio[gastoAnterior - precio][p] = 0; //lineas 14-17

    if (p == PersonaQueMasGasto()){
        auto itPrecio= _GTxPrecio.end()--; //it a la clave maxima (o sea la ultima)
        auto itPersona = ((*itPrecio).second).begin(); //it a la minima clave (o sea la primera)
        _personaQMasGasto = (*itPersona).first;
    }

    if(!pu->esHackeable(i,p)){
        _puestosHackeables[p][i].erase(i);
    }

    if(_puestosHackeables[p][i].empty()){
        _puestosHackeables[p].erase(i);
    }

    if(_puestosHackeables[p].empty()){
        _puestosHackeables.erase(p);
    }
    return;
}

 const std::set<Persona>& Lollapatuza::Personas() const {
    return _personas;
}

const std::map<IdPuesto, Puesto>& Lollapatuza::PuestosDeComida() const{
    return _puestos;
}

