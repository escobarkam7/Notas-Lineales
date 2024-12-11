#include <iostream>
#include <cstdlib>
#include <sstream>
#include <algorithm>

bool esPar(int x){
    return x % 2 == 0;
}

void numDuo(int* arreglo, int n){
    int nD=0;
    for(int i = 0; i < n-1; ++i)
        if ((esPar(arreglo[i]) == true) && (esPar(arreglo[i+1])== true))
                nD +=1;
    std::cout<<nD;
}

int main (){
    int n;
    std::cin>>n;
    std::cin.ignore();
    std::string relleno;
    getline(std::cin, relleno);
    int* arreglo = new int [n];
    std::stringstream num(relleno);

    //Rellenar el arreglo
    for (int i = 0; i < n; ++i)
        num >> arreglo[i];

    int numeroDeDuos;

    numDuo(arreglo, n);

    //Vaciar la memoria
    delete[] arreglo;
}