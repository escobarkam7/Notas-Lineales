#include <iostream>
#include <deque>
#include <string>
int main (){
    std::deque <std::string> S;
    char accion;

    while(std::cin>>accion){
        if (accion == 'R'){
            std::string nombre_raro;
            std::cin>>nombre_raro;
            S.push_back(nombre_raro);
        }
        else if(accion== 'P'){
            int soldadosapelear;
            std::cin>>soldadosapelear;
            if(soldadosapelear>S.size()){
                std::cout<<"IMPOSIBLE\n";
            }
            else {
                for(int i = 0; i <soldadosapelear; ++i){
                    std::cout<<S.front()<<" "; //Es quitar siempre el primero pero igual se puede hacer con front
                    S.pop_front();
                }
            }
        }
    }

}