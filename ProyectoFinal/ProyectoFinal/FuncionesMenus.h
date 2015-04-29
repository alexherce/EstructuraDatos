//
//  FuncionesMenus.h
//  ProyectoFinal
//
//  Created by Alejandro Herce on 24/11/14.
//  Copyright (c) 2014 Alejandro Herce. All rights reserved.
//

#ifndef ProyectoFinal_FuncionesMenus_h
#define ProyectoFinal_FuncionesMenus_h


#include "FuncionesTrabajadores.h"
#include "FuncionesClientes.h"
#include "FuncionesProductos.h"

//DefiniciÛn.

void imprimirMenuPrincipal();
void imprimirMenuSecundario();
void ejecutarAccionesMenuPrincipal();
void ejecutarAccionesMenuSecundario(std::list <Producto> *, std::list <Cliente> *);

//DefiniciÛn.


//Imprimir el menu principal del programa.
void imprimirMenuPrincipal(){
    
    std::cout << "\n\n\t1) Iniciar Sesion\n\t2) Agregar trabajador\n\t3) Eliminar trabajador\n\t4) Imprimir lista de trabajadores\n\t5) Agregar cliente\n\t6) Eliminar cliente\n\t7) Imprimir lista de clientes\n\t8) Buscar producto por numero\n\t9) Buscar producto por nombre\n\t10) Buscar productos por categoria\n\t11) Buscar productos agotados\n\t12) Obtener cliente mas leal\n\t13) Obtener cliente que mas ha invertido\n\t14) Salir";
    
}
//Imprimir el menu principal del programa.


//Imprimir el menu secundario del programa.
void imprimirMenuSecundario(){
    
    std::cout << "\n\n\t1) Cobrar\n\t2) Agregar producto\n\t3) Eliminar producto\n\t4) Imprimir lista de productos\n\t5) Actualizar cantidad de producto\n\t6) Actualizar precio producto\n\t7) Salir";
    
}
//Imprimir el menu secundario del programa.


//Ejecutar las acciones del menu principal.
void ejecutarAccionesMenuPrincipal(){
    
    std::list <Trabajador> * listaTrabajadores = new std::list <Trabajador>();
    std::list <Cliente> * listaClientes = new std::list <Cliente>();
    std::list <Producto> * listaProductos = new std::list <Producto>();
    almacenarInformacionTrabajadoresEnLista(listaTrabajadores, "ArchivoTrabajadores");
    almacenarInformacionClientesEnLista(listaClientes, "ArchivoClientes");
    almacenarInformacionProductosEnLista(listaProductos, "ArchivoProductos");
    
    std::string opcionMenuPrincipalIngreso = "";
    int $opcionMenuPrincipalIngreso;
    
    std::string numeroTrabajadorAEliminarIngreso = ""; //Case 3
    int $numeroTrabajadorAEliminarIngreso; //Case 3
    
    std::string numeroClienteAEliminarIngreso = ""; //Case 6
    int $numeroClienteAEliminarIngreso; //Case 6
    
    std::string numeroProductoABuscarIngreso = ""; //Case 8
    int $numeroProductoABuscarIngreso; //Case 8
    
    std::string nombreProductoABuscarIngreso = ""; //Case 9
    
    std::string categoriaProductoABuscarIngreso = ""; //Case 10
    
    while($opcionMenuPrincipalIngreso != 14){
        
        std::list <Producto> listaProductosTemp; //Case 10 y 11.
        Producto productoBuscado; //Case 8 y 9.
        Cliente clienteLeal; //Case 12
        Cliente clientePrometedor; //Case 13
        
        imprimirMenuPrincipal();
        
        std::cout << "\n\n\tIngrese la opcion: ";
        std::cin >> opcionMenuPrincipalIngreso;
        $opcionMenuPrincipalIngreso = atoi(opcionMenuPrincipalIngreso.c_str());
        
        switch($opcionMenuPrincipalIngreso){
                
            case 1:
                
                if(validarInicioSesion(listaTrabajadores, ingresarInformacionInicioSesion()))
                    ejecutarAccionesMenuSecundario(listaProductos, listaClientes);
                
                else
                    std::cout << "\n\t\t\tInicio fallido.";
                
                break;
                
            case 2:
                
                agregarTrabajadorEnLista(listaTrabajadores, ingresarInformacionTrabajador());
                
                break;
                
            case 3:
                
                std::cout << "\n\t\tIngrese el numero del trabajador a eliminar: ";
                std::cin >> numeroTrabajadorAEliminarIngreso;
                $numeroTrabajadorAEliminarIngreso = atoi(numeroTrabajadorAEliminarIngreso.c_str());
                
                if($numeroTrabajadorAEliminarIngreso > 0 && $numeroTrabajadorAEliminarIngreso <= listaTrabajadores->size()){
                    
                    eliminarTrabajadorEnLista(listaTrabajadores, $numeroTrabajadorAEliminarIngreso);
                    reasignarNumeroTrabajadorEnLista(listaTrabajadores);
                    
                }
                
                else
                    std::cout << "\n\t\t\tTrabajador invalido";
                
                break;
                
            case 4:
                
                imprimirInformacionTrabajadores(listaTrabajadores);
                
                break;
                
            case 5:
                
                agregarClienteEnLista(listaClientes, ingresarInformacionCliente());
                
                break;
                
            case 6:
                
                std::cout << "\n\t\tIngrese el numero del cliente a eliminar: ";
                std::cin >> numeroClienteAEliminarIngreso;
                $numeroClienteAEliminarIngreso = atoi(numeroClienteAEliminarIngreso.c_str());
                
                if($numeroClienteAEliminarIngreso > 0 && $numeroClienteAEliminarIngreso <= listaClientes->size()){
                    
                    eliminarClienteEnLista(listaClientes, $numeroClienteAEliminarIngreso);
                    reasignarNumeroClienteEnLista(listaClientes);
                    
                }
                
                else
                    std::cout << "\n\t\t\tCliente invalido";
                
                break;
                
            case 7:
                
                imprimirInformacionClientes(listaClientes);
                
                break;
                
            case 8:
                
                std::cout << "\n\t\tIngrese el numero del producto: ";
                std::cin >> numeroProductoABuscarIngreso;
                $numeroProductoABuscarIngreso = atoi(numeroProductoABuscarIngreso.c_str());
                
                productoBuscado = buscarProductoPorNumero(listaProductos, $numeroProductoABuscarIngreso);
                
                if($numeroProductoABuscarIngreso > 0 && $numeroProductoABuscarIngreso <= listaProductos->size())
                    std::cout << "\n\t\t" << productoBuscado;
                
                else
                    std::cout << "\n\t\t\tProducto invalido";
                
                break;
                
            case 9:
                
                std::cout << "\n\t\tIngrese el nombre del producto: ";
                std::cin >> nombreProductoABuscarIngreso;
                
                productoBuscado = buscarProductoPorNombre(listaProductos, nombreProductoABuscarIngreso);
                
                if(productoBuscado == Producto(-1, "####", "####", 0, 0))
                    std::cout << "\n\t\t\tNo encontrado";
                
                else
                    std::cout << "\n\t\t" << productoBuscado;
                
                break;
                
            case 10:
                
                std::cout << "\n\t\tIngrese la categoria del producto: ";
                std::cin >> categoriaProductoABuscarIngreso;
                
                listaProductosTemp = buscarProductosPorCategoria(listaProductos, categoriaProductoABuscarIngreso);
                
                if(listaProductosTemp.size() > 0)
                    for(std::list <Producto> :: iterator it = listaProductosTemp.begin(); it != listaProductosTemp.end(); ++it)
                        std::cout << "\n\t\t" << *it;
                
                else
                    std::cout << "\n\t\tNo encotrados";
                
                listaProductosTemp.clear();
                
                break;
                
            case 11:
                
                listaProductosTemp = buscarProductosAgotados(listaProductos);
                
                if(listaProductosTemp.size() > 0)
                    for(std::list <Producto> :: iterator it = listaProductosTemp.begin(); it != listaProductosTemp.end(); ++it)
                        std::cout << "\n\t\t" << *it;
                
                else
                    std::cout << "\n\t\tNo encotrados";
                
                listaProductosTemp.clear();
                
                break;
                
            case 12:
                
                clienteLeal = obtenerClienteLeal(listaClientes);
                
                if(clienteLeal == Cliente())
                    std::cout << "\n\t\t\tNo se ha comprado nada";
                
                else
                    std::cout << "\n\t\t" << clienteLeal;
                
                break;
                
            case 13:
                
                clientePrometedor = obtenerClientePrometedor(listaClientes);
                
                if(clientePrometedor == Cliente())
                    std::cout << "\n\t\t\tNo se ha comprado nada";
                
                else
                    std::cout << "\n\t\t" << clientePrometedor;
                
                break;
                
            case 14:
                
                break;
                
            default:
                
                std::cout << "\n\t\t\tOpcion invalida";
                
                break;
                
        }
        
        almacenarInformacionTrabajadoresEnArchivoTxt(listaTrabajadores, "ArchivoTrabajadores");
        almacenarInformacionClientesEnArchivoTxt(listaClientes, "ArchivoClientes");
        almacenarInformacionProductosEnArchivoTxt(listaProductos, "ArchivoProductos");
        
    }
    
    //Liberar memoria.
    
    listaTrabajadores->clear();
    listaClientes->clear();
    listaProductos->clear();
    delete listaTrabajadores;
    delete listaClientes;
    delete listaProductos;
    
    //Liberar memoria.
    
}
//Ejecutar las acciones del menu principal.


//Ejecutar las acciones del menu secundario.
void ejecutarAccionesMenuSecundario(std::list <Producto> * _listaProductos, std::list <Cliente> * _listaClientes){
    
    std::string opcionMenuSecundarioIngreso;
    int $opcionMenuSecundarioIngreso;
    
    std::string numeroClienteIngreso; //Case 1
    std::string nombreClienteIngreso; //Case 1
    int $numeroClienteIngreso; //Case 1
    
    std::string numeroProductoAEliminarIngreso; //Case 3
    int $numeroProductoAEliminarIngreso; //Case 3
    
    std::string numeroProductoAActualizarIngreso; //Case 5 & Case 6
    int $numeroProductoAActualizarIngreso; //Case 5 & Case 6
    std::string cantidadProductoAActualizarIngreso; //Case 5
    int $cantidadProductoAActualizarIngreso; //Case 5
    
    std::string precioProductoAActualizarIngreso; //Case 6
    double $precioProductoAActualizarIngreso; //Case 6
    
    while($opcionMenuSecundarioIngreso != 7){
        
        imprimirMenuSecundario();
        
        std::cout << "\n\n\tIngrese la opcion: ";
        std::cin >> opcionMenuSecundarioIngreso;
        $opcionMenuSecundarioIngreso = atoi(opcionMenuSecundarioIngreso.c_str());
        
        switch($opcionMenuSecundarioIngreso){
                
            case 1:
                
                std::cout << "\n\t\tIngrese el numero del cliente: ";
                std::cin >> numeroClienteIngreso;
                $numeroClienteIngreso = atoi(numeroClienteIngreso.c_str());
                
                std::cout << "\n\t\tIngrese el nombre del cliente: ";
                std::cin >> nombreClienteIngreso;
                
                if(verificarExistenciaCliente(_listaClientes, nombreClienteIngreso, $numeroClienteIngreso))
                    cobrarProductos(_listaProductos, _listaClientes, $numeroClienteIngreso);
                
                else
                    std::cout << "\n\t\t\tCliente invalido";
                
                break;
                
            case 2:
                
                agregarProductoEnLista(_listaProductos, ingresarInformacionProducto());
                
                break;
                
            case 3:
                
                std::cout << "\n\t\tIngrese el numero del producto a eliminar: ";
                std::cin >> numeroProductoAEliminarIngreso;
                $numeroProductoAEliminarIngreso = atoi(numeroProductoAEliminarIngreso.c_str());
                
                if($numeroProductoAEliminarIngreso > 0 && $numeroProductoAEliminarIngreso <= _listaProductos->size()){
                    
                    eliminarProductoEnLista(_listaProductos, $numeroProductoAEliminarIngreso);
                    reasignarNumeroProductoEnLista(_listaProductos);
                    
                }
                
                else
                    std::cout << "\n\t\t\tProducto invalido";
                
                break;
                
            case 4:
                
                imprimirInformacionProductos(_listaProductos);
                
                break;
                
            case 5:
                
                std::cout << "\n\t\tIngrese el numero del producto a actualizar: ";
                std::cin >> numeroProductoAActualizarIngreso;
                $numeroProductoAActualizarIngreso = atoi(numeroProductoAActualizarIngreso.c_str());
                
                if($numeroProductoAActualizarIngreso > 0 && $numeroProductoAActualizarIngreso <= _listaProductos->size()){
                    
                    std::cout << "\n\t\tIngrese la cantidad del producto: ";
                    std::cin >> cantidadProductoAActualizarIngreso;
                    $cantidadProductoAActualizarIngreso = atoi(cantidadProductoAActualizarIngreso.c_str());
                    
                    if($cantidadProductoAActualizarIngreso > 0)
                        actualizarCantidadProducto(_listaProductos, $numeroProductoAActualizarIngreso, $cantidadProductoAActualizarIngreso);
                    
                    else
                        std::cout << "\n\t\tCantidad invalida";
                    
                }
                
                else
                    std::cout << "\n\t\t\tProducto invalido";
                
                break;
                
            case 6:
                
                std::cout << "\n\t\tIngrese el numero del producto a actualizar: ";
                std::cin >> numeroProductoAActualizarIngreso;
                $numeroProductoAActualizarIngreso = atoi(numeroProductoAActualizarIngreso.c_str());
                
                if($numeroProductoAActualizarIngreso > 0 && $numeroProductoAActualizarIngreso <= _listaProductos->size()){
                    
                    std::cout << "\n\t\tIngrese el precio del del producto: ";
                    std::cin >> precioProductoAActualizarIngreso;
                    $precioProductoAActualizarIngreso = atof(precioProductoAActualizarIngreso.c_str());
                    
                    if($precioProductoAActualizarIngreso > 0)
                        actualizarPrecioProducto(_listaProductos, $numeroProductoAActualizarIngreso, $precioProductoAActualizarIngreso);
                    
                    else
                        std::cout << "\n\t\tCantidad invalida";
                    
                }
                
                else
                    std::cout << "\n\t\t\tProducto invalido";
                
                break;
                
            case 7:
                
                break;
                
            default:
                
                std::cout << "\n\t\t\tOpcion invalida";
                
                break;
                
        }
    }
}
//Ejecutar las acciones del menu secundario.

#endif
