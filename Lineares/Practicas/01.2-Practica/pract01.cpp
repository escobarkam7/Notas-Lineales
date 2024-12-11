#include <iostream>

int main() {
    int m, n;
    std::cin >> m >> n;

    int** arreglo = new int*[m];
    for (int i = 0; i < m; i++) 
        arreglo[i] = new int[n]; //Se crea como malloc, primero filas y luego columnas

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arreglo[i][j] = 0; //Rellenar con ceros
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << arreglo[i][j] << " ";
        }
        std::cout << "\n";
    }

    //Vaciar memoria
    for (int i = 0; i < m; i++) 
        delete[] arreglo[i];
    delete[] arreglo;

}
