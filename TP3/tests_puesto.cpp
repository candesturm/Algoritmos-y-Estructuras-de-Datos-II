#include "gtest-1.8.1/gtest.h"
#include "../src/puesto.h"
#include <utility>

using namespace std;


TEST(tests_puesto,obtenerStock){
    Menu m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    Menu const& const_m = m;
    Stock s;
    s[1] = 30;
    s[2] = 30;
    s[3] = 30;
    vector<int>a = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>b = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>c = {0,0,0,0,0,10,10,10,10,10,20};
    map<Producto, std::vector<int>> desc;
    desc[1] = a;
    desc[2] = b;
    desc[3] = c;
    map<Producto, std::vector<int>> const& const_d = desc;
    Puesto p(const_m,s,const_d);
    int k = p.ObtenerStock(1);
    EXPECT_EQ(30,k);
}

TEST(tests_puesto,obtenerDesc){
    Menu m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    Menu const& const_m = m;
    Stock s;
    s[1] = 30;
    s[2] = 30;
    s[3] = 30;
    vector<int>a = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>b = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>c = {0,0,0,0,0,10,10,10,10,10,20};
    map<Producto, std::vector<int>> desc;
    desc[1] = a;
    desc[2] = b;
    desc[3] = c;
    map<Producto, std::vector<int>> const& const_d = desc;
    Puesto p(const_m,s,const_d);
    EXPECT_EQ(10,p.ObtenerDescuento(1,7));
}

TEST(tests_puesto,obtenerPrecio){
    Menu m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    Menu const& const_m = m;
    Stock s;
    s[1] = 30;
    s[2] = 30;
    s[3] = 30;
    vector<int>a = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>b = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>c = {0,0,0,0,0,10,10,10,10,10,20};
    map<Producto, std::vector<int>> desc;
    desc[1] = a;
    desc[2] = b;
    desc[3] = c;
    map<Producto, std::vector<int>> const& const_d = desc;
    Puesto p(const_m,s,const_d);
    EXPECT_EQ(20,p.ObtenerPrecio(2));
}

TEST(tests_puesto,vender){
    Menu m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    Menu const& const_m = m;
    Stock s;
    s[1] = 30;
    s[2] = 30;
    s[3] = 30;
    vector<int>a = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>b = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>c = {0,0,0,0,0,10,10,10,10,10,20};
    map<Producto, std::vector<int>> desc;
    desc[1] = a;
    desc[2] = b;
    desc[3] = c;
    map<Producto, std::vector<int>> const& const_d = desc;
    Puesto p(const_m,s,const_d);
    p.Vender(1,2,4);
    EXPECT_EQ(80,p.GastoPorPersona(1));

}

TEST(tests_puesto,esHack){
    Menu m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    Menu const& const_m = m;
    Stock s;
    s[1] = 30;
    s[2] = 30;
    s[3] = 30;
    vector<int>a = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>b = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>c = {0,0,0,0,0,10,10,10,10,10,20};
    map<Producto, std::vector<int>> desc;
    desc[1] = a;
    desc[2] = b;
    desc[3] = c;
    map<Producto, std::vector<int>> const& const_d = desc;
    Puesto p(const_m,s,const_d);
    p.Vender(1,2,4);
    EXPECT_TRUE(p.esHackeable(2,1));

}

TEST(tests_puesto,Hackear){
    Menu m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    Menu const& const_m = m;
    Stock s;
    s[1] = 30;
    s[2] = 30;
    s[3] = 30;
    vector<int>a = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>b = {0,0,0,0,0,10,10,10,10,10,20};
    vector<int>c = {0,0,0,0,0,10,10,10,10,10,20};
    map<Producto, std::vector<int>> desc;
    desc[1] = a;
    desc[2] = b;
    desc[3] = c;
    map<Producto, std::vector<int>> const& const_d = desc;
    Puesto p(const_m,s,const_d);
    p.Vender(1,2,4);
    p.HackearPuesto(2,1);
    EXPECT_EQ(60,p.GastoPorPersona(1));

}


