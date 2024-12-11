#include <iostream>

void imprimirArreglo(int* arreglo, int tamanio) {
    for (int i = 0; i < tamanio; i++) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << "\n";
}

void actualizarArreglo(int*& arreglo, int& capacidad, int& tamanio, int elemento) {
    if (tamanio == capacidad) {
        capacidad *= 2;
        int* nuevoArreglo = new int[capacidad];

        for (int i = 0; i < tamanio; i++) {
            nuevoArreglo[i] = arreglo[i]; //Llenar el nuevo arreglo con los elementos del viejito
        }

        delete[] arreglo;
        arreglo = nuevoArreglo;
    }

    arreglo[tamanio] = elemento; //Así se va a la última casilla del arreglo
    tamanio++;
}

int main() {
    int n;
    std::cout << "Ingrese la capacidad del arreglo: ";
    std::cin >> n;

    int* arreglito = new int[n];
    int tamanio = 0; //Número de elementos actuales en el arreglo
    int capacidad = n; //Número de elementos permitidos en el arreglo
    int elemento;
    std::string llave;

    do {
        std::cout << "Ingresa un elemento al arreglo: ";
        std::cin >> elemento;

        actualizarArreglo(arreglito, capacidad, tamanio, elemento);

        std::cout << "¿Quieres continuar arreglando elementos?";
        std::cin >> llave;

    } while (llave != "no");

    imprimirArreglo(arreglito, tamanio);

    delete[] arreglito; //Vaciar memoria
}
