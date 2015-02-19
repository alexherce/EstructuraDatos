//
//  main.cpp
//  Problema2
//
//  Created by Alejandro Herce on 19/02/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
#include "vehiculo.h"
#include "cliente.h"
#include "venta.h"
#include "concesionaria.h"

int main(int argc, const char * argv[]) {
    
    Concesionaria agencia;
    Vehiculo coche1;
    Vehiculo coche2;
    Cliente cliente1;
    Cliente cliente2;
    Venta sale;
    
    
    coche1 = Vehiculo("Camioneta", "Toyota", "0001", 2000, 100000, "4x4");
    coche2 = Vehiculo("Coche", "Mazda", "0002", 2014, 3000, "-");
    
    
    cliente1 = Cliente("Alejandro", "Herce", "HEBA140194");
    cliente2 = Cliente("Vicente", "Cubells", "ELPROFE010203");
    
    agencia.adicionarVenta("0001", Venta(10000, coche1, cliente1));
    agencia.adicionarVenta("0002", Venta(30000, coche2, cliente2));
    
    cout << "LISTADO DE VENTAS: " << endl;
    cout << agencia << endl << endl;
    
    cout << "BUSCAR: " << endl;
    agencia.buscarCompradorApellido("Herce");
    
    
    cout << "VENTAS ORDENADAS POR MONTO: " << endl;
    
    
    
    return 0;
}
