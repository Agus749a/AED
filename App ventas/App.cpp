#include "header.h"
void Cargar_productos(Data_Producto&);
void Cargar_clientes(Data_Cliente&);
void menu_principal();
void menu_generarVentas();
boleta_ Generar_venta (Data_Producto&,Data_Cliente&);
int main()
{
    menu_principal();
}
void Cargar_clientes (Data_Cliente& _almacenadorcliente_aux)
{
    unsigned id_cliente_aux{};
    string nombre_apellido_aux; 
    string domicilio_aux;
    string razon_social_aux;
    string zona_aux;
    long long int numero_telefono_aux{};
    ifstream flujo_producto;
    flujo_producto.open("DataBase_Clientes.txt", ios::in);
    for(int i{};flujo_producto>>nombre_apellido_aux>>domicilio_aux>>razon_social_aux>>numero_telefono_aux>>zona_aux;i++)
    {
        _almacenadorcliente_aux.at(i).id_cliente=i;
        _almacenadorcliente_aux.at(i).nombre_apellido=nombre_apellido_aux;
        _almacenadorcliente_aux.at(i).domicilio=domicilio_aux;
        _almacenadorcliente_aux.at(i).razon_social=razon_social_aux;
        _almacenadorcliente_aux.at(i).numero_telefono=numero_telefono_aux;
        _almacenadorcliente_aux.at(i).numero_telefono=numero_telefono_aux;
        _almacenadorcliente_aux.at(i).zona=zona_aux;
    }
}
void Cargar_productos (Data_Producto& _almacenadorproducto_aux)
{
    string nombre_Producto_aux;
    long unsigned codigo_aux{};
    double precio_aux{};
    unsigned stock_aux{};
    ifstream flujo_cliente;
    flujo_cliente.open("DataBase_Productos.txt", ios::in);
    for(int j{};flujo_cliente>>nombre_Producto_aux>>codigo_aux>>precio_aux>>stock_aux;j++)
    {
        _almacenadorproducto_aux.at(j).nombre_Producto=nombre_Producto_aux;
        _almacenadorproducto_aux.at(j).codigo=j;
        _almacenadorproducto_aux.at(j).precio=precio_aux;
        _almacenadorproducto_aux.at(j).stock=stock_aux;
    }
}
void menu_principal ()
{
    Data_Producto Producto_Datamadre{};
    Data_Cliente cliente_Datamadre{};
    Data_boleta boleta_Datamadre{};
    Cargar_productos(Producto_Datamadre);
    Cargar_clientes(cliente_Datamadre);
    int opcion_MenuPrincipal{};
do
{system("cls");
        cout<<"1) GENERAR VENTA"<<'\n';
        cout<<"2) VER CLIENTES"<<'\n';
        cout<<"3) BUSCAR CLIENTE"<<'\n';
        cout<<"4) VENTAS DEL DIA"<<'\n';
        cout<<"5) CIERRE DE TURNO"<<'\n';
        cout<<"6) BOLETAS"<<'\n';
        cout<<"7) CONSULTAR STOCK"<<'\n';
        cout<<"Ingrese numero de opcion: ";
        cin>>opcion_MenuPrincipal;
switch(opcion_MenuPrincipal)
    {
case 1:{system("cls");
        boleta_Datamadre.push_back(Generar_venta(Producto_Datamadre,cliente_Datamadre));
        break;    
      }
case 2:{system("cls");
        for(auto y : cliente_Datamadre)
        {
        cout<<'\n'<<'\t'<<"ID cliente: "<<y.id_cliente<<'\n';
        cout<<"Direccion: "<<y.domicilio<<"           "<<"Nombre y apellido: "<<y.nombre_apellido<<'\n';
        cout<<"Razon social: "<<y.razon_social<<"             "<<"Numero de telefono: "<<y.numero_telefono<<'\n';
        }
        system("pause");
        break; 
      }
case 3:{system("cls");
        int id_cliete_buscar{};
        cout<<"Ingrese el id del cliente: "; cin>>id_cliete_buscar;
        cout<<'\n'<<"ID cliente: "<<cliente_Datamadre.at(id_cliete_buscar).id_cliente<<'\n';
        cout<<"Direccion: "<<cliente_Datamadre.at(id_cliete_buscar).domicilio<<"           "<<"Nombre y apellido: "<<cliente_Datamadre.at(id_cliete_buscar).nombre_apellido<<'\n';
        cout<<"Razon social: "<<cliente_Datamadre.at(id_cliete_buscar).razon_social<<"             "<<"Numero de telefono: "<<cliente_Datamadre.at(id_cliete_buscar).numero_telefono<<'\n';
        system("pause");
        break; 
      }
case 4:{system("cls");
        int total_del_dia{};
        for(auto acumulador : boleta_Datamadre)
        {
            total_del_dia+=acumulador.precio_final;
        }
        cout<<"El total de ventas en el dia es de: "<<total_del_dia<<"$"<<'\n';
        system("pause");
        break; 
      }
case 5:{system("cls");
        int total_del_dia2{}, opcion_cierre{};
        for(auto acumulador : boleta_Datamadre)
        {
            total_del_dia2+=acumulador.precio_final;
        }
        cout<<"Seguro que desea cerrar turno?"<<'\n';
        cout<<"Presione 1 para 'Si' o 2 para 'No': ";cin>>opcion_cierre;
        switch(opcion_cierre)
        {
            case 1:
            {
                ofstream flujo_boletas,flujo_producto;
                flujo_boletas.open("Ordenes.txt", ios::out);
                flujo_producto.open("DataBase_Productos.txt", ios::out);
                for(auto v : boleta_Datamadre)
                {system("cls");
                    flujo_boletas<<"-------------------------------------------------------------------------------------";
                    flujo_boletas<<'\n'<<"*****NUMERO DE BOLETA****** : "<<v.id_boleta<<'\n';
                    for(auto y : v.cliente_boleta)
                    {
                        flujo_boletas<<"Direccion: "<<y.domicilio<<"           "<<"Nombre y apellido: "<<y.nombre_apellido<<'\n';
                        flujo_boletas<<"Razon social: "<<y.razon_social<<"             "<<"Numero de telefono: "<<y.numero_telefono<<'\n';
                        flujo_boletas<<'\n'<<"Listado de productos: "<<'\n';
                    }
                        for(auto t : v.productos_boleta)
                            {
                                flujo_boletas<<'\t'<<'\n'<<"Codigo de producto: "<<t.codigo<<'\n';
                                flujo_boletas<<'\t'<<"Nombre del producto: "<<t.nombre_Producto<<'\n';
                                flujo_boletas<<'\t'<<"Precio por unidad: "<<t.precio<<"$"<<"   CANTIDAD: "<<t.cantidad<<'\n';
                            }
                    flujo_boletas<<"Se aplicara un: "<<v.porcentaje_descuento<<"'%' de descuento"<<'\n';
                    flujo_boletas<<"Precio total: "<<v.precio_final<<"$"<<'\n';
                }
                for (auto l : Producto_Datamadre)
                {
                    flujo_producto<<l.nombre_Producto<<" "<<l.codigo<<" "<<l.precio<<" "<<l.stock<<'\n';
                }
                boleta_Datamadre.clear();
                cout<<"Turno cerrado con exito, anote el total del dia: "<<total_del_dia2<<"$"<<'\n';
                system("pause");
            }
            case 2: 
            {
                break;;
            }
        }
        break; 
      }
case 6:{system("cls");
        for(auto v : boleta_Datamadre)
        {system("cls");
        cout<<"*****NUMERO DE BOLETA****** : "<<v.id_boleta<<'\n';
        for(auto y : v.cliente_boleta)
        {
        cout<<"Direccion: "<<y.domicilio<<"           "<<"Nombre y apellido: "<<y.nombre_apellido<<'\n';
        cout<<"Razon social: "<<y.razon_social<<"             "<<"Numero de telefono: "<<y.numero_telefono<<'\n';
        cout<<'\n'<<"Listado de productos: "<<'\n';
        }
        for(auto t : v.productos_boleta)
        {
            cout<<'\t'<<'\n'<<"Codigo de producto: "<<t.codigo<<'\n';
            cout<<'\t'<<"Nombre del producto: "<<t.nombre_Producto<<'\n';
            cout<<'\t'<<"Precio por unidad: "<<t.precio<<"$"<<"  CANTIDAD "<<t.cantidad<<'\n';
        }
        cout<<"Se aplicara un: "<<v.porcentaje_descuento<<"'%' de descuento"<<'\n';
        cout<<"Precio total: "<<v.precio_final<<"$"<<'\n';
        system("pause");
        }
        break; 
      }
case 7:{system("cls"); int id_producto_aux{};
        cout<<"Ingrese id del producto: "; cin>>id_producto_aux;
        cout<<Producto_Datamadre.at(id_producto_aux).nombre_Producto<<"     Precio: "<<Producto_Datamadre.at(id_producto_aux).precio<<"$     Cantidad en stock: "<<Producto_Datamadre.at(id_producto_aux).stock<<'\n';
        system("pause");
        break; 
      }
    }
}
while(opcion_MenuPrincipal<=7 && opcion_MenuPrincipal>0);
}
boleta_ Generar_venta (Data_Producto & aux_producto,Data_Cliente & aux_cliente)
{
  int opcion_GenerarVentas{},cantidad{},descuento{},porcentaje_descuento{};
  float total {};
  vector<float> subtotal;
  boleta_ boleta_aux;
  unsigned id_cliente_aux{},id_producto_aux{};
  static unsigned id_boleta_aux {};
  ++id_boleta_aux;
  boleta_aux.id_boleta = id_boleta_aux;
  cout<<"INGRESE EL ID DEL CLIENTE: "; cin>>id_cliente_aux;
  boleta_aux.cliente_boleta.push_back(aux_cliente.at(id_cliente_aux));
 do
 {system("cls");
     cout<<"1) Agregar producto"<<'\n';
     cout<<"2) Finalizar venta"<<'\n';
     cin>>opcion_GenerarVentas;
 switch(opcion_GenerarVentas)
     {
 case 1:{system("cls");
         cout<<"INGRESE EL ID DEL PRODUCTO: "; cin>>id_producto_aux;
         cout<<'\a'<<"Producto: "<<aux_producto.at(id_producto_aux).nombre_Producto<<'\n';
         cout<<'\a'<<"Precio por unidad: "<<aux_producto.at(id_producto_aux).precio;
         cout<<'\n'<<"INGRESE LA CANTIDAD: "; cin>>cantidad;
         aux_producto.at(id_producto_aux).cantidad=cantidad;
         aux_producto.at(id_producto_aux).stock =  (aux_producto.at(id_producto_aux).stock) - cantidad;
         (boleta_aux.productos_boleta).push_back(aux_producto.at(id_producto_aux));
         subtotal.push_back((aux_producto.at(id_producto_aux).precio)*cantidad);
         break;    
       }
 case 2:{ 
         for (auto v : subtotal)
            {
                total +=v;
            }
         cout<<"Ingrese porcentaje de descuento: "; cin>>porcentaje_descuento;
         boleta_aux.porcentaje_descuento = porcentaje_descuento;
         descuento=(total*porcentaje_descuento)/100;
         boleta_aux.precio_final=total-descuento;
         return(boleta_aux); 
       }
     }
 }
     while(opcion_GenerarVentas<=2 && opcion_GenerarVentas>0);
}