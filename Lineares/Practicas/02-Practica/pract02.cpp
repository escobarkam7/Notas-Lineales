#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main (){
    std::ios_base::sync_with_stdio(false);
    std:: vector<int> a;
    std:: vector<int> b;
    int N, val;
    int resultado = 0;
    std::string linea1, linea2;
    std::cin>>N;
    std::cin.ignore();
    getline(std::cin, linea1);
    getline(std::cin, linea2);
    std::stringstream num(linea1);
    std::stringstream numm(linea2);

    for (int i = 0; i < N; ++i){
        num >> val;
        a.push_back(val);
        numm >> val;
        b.push_back(val);
    }

    for (int i = 0; i < N; ++i){
        resultado += a[i]*b[i];
    }
    
    std::cout << resultado << "\n";
}