#ifndef TP_LOLLA_LOLLAPATUZA_H
#define TP_LOLLA_LOLLAPATUZA_H

#include <string>
#include <map>
#include <set>
#include "puesto.h"

using namespace std;

class Lollapatuza{
public:
    Lollapatuza(std::map<IdPuesto,Puesto> ps, std::set<Persona> per);

    void RegistrarCompra(IdPuesto id, Persona p, Producto i, int c);
    void Hackear(Persona p, Producto i);
    int GastoTotal(Persona p) const;
    Persona PersonaQueMasGasto() const;
    IdPuesto MenorStockDeItem(Producto i) const;
    const std::set<Persona>& Personas() const;
    const std::map<IdPuesto,Puesto>& PuestosDeComida() const;

private:
    std::map<IdPuesto,Puesto> _puestos;
    std::set<Persona>  _personas;
    std::map<Persona, int> _gastoTotal;
    std::map<int, std::map<Persona, int>> _GTxPrecio;
    Persona _personaQMasGasto; //cambiamos a persona que mas gasto de un puntero a la Persona por comodidad, no altera las complejidades de las operaciones
    std::map<Persona, std::map<Producto, std::map<IdPuesto,Puesto*>>> _puestosHackeables;

};


#endif //TP_LOLLA_LOLLAPATUZA_H
