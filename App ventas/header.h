#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <list>
#include <fstream>
using namespace std;
struct Producto_
{
    string nombre_Producto;
    long unsigned codigo{};
    double precio{};
    unsigned cantidad{};
    unsigned stock{};
};
struct cliente_ 
{
    unsigned id_cliente{};
    string nombre_apellido; 
    string domicilio;
    string zona;
    string razon_social;
    long long int numero_telefono{};
};

struct boleta_
{
    long unsigned id_boleta{};
    float precio_final{};
    int porcentaje_descuento;
    list<Producto_> productos_boleta{};
    list<cliente_> cliente_boleta{};
};
using Data_Producto = array<Producto_,9>;
using Data_Cliente = array<cliente_,4>;
using Data_boleta = list<boleta_>;
