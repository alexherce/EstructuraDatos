//
//  main.cpp
//  Ejercicio2
//
//  Created by Alejandro Herce on 29/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
using namespace std;
#define N 6

bool path(int horizontal, int vertical, int n, int maze[N][N]);

int main(int argc, const char * argv[]) {
  
    
    int maze[N][N] = {{0, 0, 0, 0, 0, 0} , {1, 1, 1, 1, 1, 0}, {0, 0, 0, 0, 0, 0}, {0, 1, 1, 1, 1, 1}, {0, 1, 0, 0, 0, 1}, {0, 0, 0, 1, 0, 0}};
    
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    
    cout << endl << endl;
    
    if (path(0, 0, N, maze) == true)
    {
        cout << "Exito! Se resolvio el laberinto." << endl;
    } else {
        cout << "Error! No se encontro una salida." << endl;
    }
    
    cout << endl << endl << endl;
    cout << "Camino (8 es el camino tomado, 0 es disponible, 1 es pared): " << endl;
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << maze[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}


bool path(int horizontal, int vertical, int n, int maze[N][N])
{
    maze[horizontal][vertical] = 8;
    
    if (horizontal == n-1 && vertical == n-1)
    {
        return true;
    } else {
        if((horizontal + 1 < n) && (maze[horizontal + 1][vertical]==0))
        {
            return path(horizontal + 1, vertical, 6, maze);
        }
        
        if((horizontal - 1 > -1) && (maze[horizontal - 1][vertical]==0))
        {
           return path(horizontal - 1, vertical, 6, maze);
        }
        if((vertical + 1 < n) && (maze[horizontal][vertical + 1]==0))
        {
            return path(horizontal, vertical + 1, 6, maze);
        }
        if((vertical - 1 > -1) && (maze[horizontal][vertical - 1]==0))
        {
            return path(horizontal, vertical - 1, 6, maze);
        }
     return false;
    }
}