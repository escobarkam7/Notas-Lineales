#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

struct nodo {
    int identificador;
    float temperatura;
    std::string nombre;
    nodo * ant;
    nodo * sig;
};

void imprimeLista (nodo * head){
	for( nodo * p=head;p != nullptr;p=p->sig){
		std::cout << "Nombre: " << p -> nombre << ", ";
        std::cout << "Temperatura: " << p -> temperatura << ", ";
        std::cout << "Identificador: " << p -> identificador << ". \n";
    }
    std::cout<<"\n";
}


int main (){
    std::srand(std::time(nullptr));
    double min = 35.5;
    double max = 39.2;
    double randomTemp1 = min + (static_cast<double>(std::rand()) / RAND_MAX)*(max-min);
    double randomTemp2 = min + (static_cast<double>(std::rand()) / RAND_MAX)*(max-min);
    nodo * p1 = new nodo;
    nodo * p2 = new nodo;
    nodo * p3 = new nodo;
    nodo * p4 = new nodo;
    p1->identificador = 1;
    p1->temperatura = 35.7;
    p1->nombre = "Pedrito";
    p1->ant = nullptr;
    p1->sig = p2;
    p2->identificador = 2;
    p2->temperatura = 37.7;
    p2->nombre = "Juanito";
    p2->ant = p1;
    p2->sig = p3;
    p3->identificador = 19;
    p3->temperatura = randomTemp1;
    p3->nombre = "Kam";
    p3->ant = p2;
    p3->sig = p4;
    p4->identificador = 27;
    p4->temperatura = randomTemp2;
    p4->nombre = "Erwin";
    p4->ant = p3;
    p4->sig = nullptr;
    imprimeLista(p1);
}