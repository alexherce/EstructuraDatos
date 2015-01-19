//
//  main.cpp
//  recursividadSumaArray2D
//
//  Created by Alejandro Herce on 19/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
using namespace std;

int sumaArray2D(int ** arreglo, int x, int y);

int main(int argc, const char * argv[]) {
    
    int a[3][3] = {3,2,1,4,6,4,3,2,6};
    cout << "La suma del arreglo en 2D es: ";
    cout << sumaArray2D(a, 3, 3) << endl;
    
    
    return 0;
}

int sumaArray2D(int ** arreglo, int x, int y)
{
    if(x == 0 && y == 0)
    {
        return arreglo[0][0];
    } else if (y == 0){
        return arreglo[x][y] + sumaArray2D(arreglo, x - 1, y - 1);
    } else {
        return arreglo[x][y] + sumaArray2D(arreglo, x, y - 1);
    }
}
