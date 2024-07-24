#ifndef TP_LOLLA_PUESTO_H
#define TP_LOLLA_PUESTO_H

#include <string>
#include <map>
#include <vector>
#include <list>
#include "tipos.h"

using namespace std;

class Puesto{
public:
    //Constructor, CrearPuesto
    Puesto(const Menu& menu, Stock&stock, const std::map<Producto, std::vector<int>>& desc);

    int ObtenerStock(Producto item) const;
    int ObtenerDescuento(Producto item, int cant) const;
    int ObtenerPrecio(Producto item) const; //agregamos ObtenerPrecio para respetar el encapsulamiento del modulo Puesto
    void Vender(Persona per, Producto item, int cant);
    int GastoPorPersona(Persona per) const;
    bool esHackeable(Producto item, Persona per) const;
    void HackearPuesto(Producto item, Persona per);

private:
    Stock _stock;
    Menu _menu;
    std::map<Producto, std::vector<int>> _desc;
    std::map<Persona,Nat> _gastoxPersona;
    std::map<Persona,std::list<pair<Producto,int>>> _ventas;
    std::map<Persona,std::map<Producto,std::list<std::list<pair<Producto,int>>::iterator>>> _ventasSinDesc;

};



#endif //TP_LOLLA_PUESTO_H
