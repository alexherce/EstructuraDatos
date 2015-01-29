//
//  main.cpp
//  Ejercicio1
//
//  Created by Alejandro Herce on 28/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
using namespace std;
#include <math.h>

#define N 8

void llenarMatriz(int a, int b, int n, int m[N][N]);

int main(int argc, const char * argv[]) {
    
    
    int matriz[N][N] = {0};
    
    llenarMatriz(0, 0, N, matriz);
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << " " << matriz[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}

void llenarMatriz(int f, int c, int n, int m[N][N]){
    if (f == n - 1 && c == n - 1)
    {
        m[f][c] = pow(2, n-1);
    } else {
        if (f == n - 1)
        {
            m[f][c] = pow(2, c);
            llenarMatriz(0, c + 1, N, m);
        }
        else{
            if(f < c)
            {
                m[f][c] = pow(2, f);
            } else {
                m[f][c] = pow(2, c);
            }
            llenarMatriz(f + 1, c, N, m);
        }
    }
};