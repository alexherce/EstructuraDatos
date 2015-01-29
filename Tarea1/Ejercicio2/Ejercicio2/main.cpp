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

bool path(int x, int y, int n, int maze[N][N]);

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


bool path(int x, int y, int n, int maze[N][N])
{
    maze[x][y] = 8;
    
    if (x == n-1 && y == n-1)
    {
        return true;
    } else {
        if((x + 1 < n) && (maze[x + 1][y]==0 || maze[x + 1][y] == 8))
        {
            return path(x + 1, y, 6, maze);
        }
        
        if((x - 1 > -1) && (maze[x - 1][y]==0 || maze[x - 1][y] == 8))
        {
            return path(x - 1, y, 6, maze);
        }
        if((y + 1 < n) && (maze[x][y + 1]==0 || maze[x][y + 1] == 8))
        {
            return path(x, y + 1, 6, maze);
        }
        if((y - 1 > -1) && (maze[x][y - 1]==0 || maze[x][y - 1] == 8))
        {
            return path(x, y - 1, 6, maze);
        }
        return false;
    }
}