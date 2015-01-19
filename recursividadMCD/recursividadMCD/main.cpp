//
//  main.cpp
//  recursividadMCD
//
//  Created by Alejandro Herce on 19/01/15.
//  Copyright (c) 2015 Alejandro Herce. All rights reserved.
//

#include <iostream>
using namespace std;

int mcd(int m, int n);



int main(int argc, const char * argv[]) {
    
    int num1, num2;
    
    cout << "Ingresa un numero: ";
    cin >> num1;
    
    cout << "Ingresa otro numero: ";
    cin >> num2;
    
    cout << "El MCD es: " << mcd(num1, num2) << endl;
    
    
    
    return 0;
}


int mcd(int m, int n)
{
    if (n != 0)
    {
        return mcd(n, m%n);
    } else {
        return m;
    }
}
