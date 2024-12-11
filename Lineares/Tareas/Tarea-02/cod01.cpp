#include <iostream>

void agregaDerecha (int *&arreglo, int ini, int & tamanio, int capacidad, int v){
    ini = (ini + tamanio)%capacidad;
    arreglo[ini]=v;
    tamanio++;
};

void rotaIzquierda(int *&arreglo, int &ini, int & tamanio, int capacidad, int movimientos){
    for(int i=0; i<movimientos; ++i){
        ini++;
    }
    for(int i = 0; i<tamanio; ++i)
        std::cout<<arreglo[(ini + i)%capacidad]<<" ";
    std::cout<<"\n";
}

int main (){
    int *arreglo, ini, tamanio, capacidad;
    std::cin>>capacidad;
    arreglo = new int [capacidad]; //Declarar la deque
    ini = 0;
    tamanio = 0;
    int operaciones; 
    for (int i = 0; i<capacidad; i++){
        int joyas;
        std::cin>>joyas;
        agregaDerecha(arreglo, ini, tamanio, capacidad, joyas);
        
    }
    std::cin>>operaciones;
    rotaIzquierda(arreglo, ini, tamanio, capacidad, operaciones);

}