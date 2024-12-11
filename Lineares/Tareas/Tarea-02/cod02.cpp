#include <iostream>
#include <deque>

int main (){
    std::deque<int> pila;
    std::deque<int> cola;
    std::deque <int> Aux1;
    std::deque <int> Aux2;

    int q, tipo, x;
    std::cin>>q;
    for (int i=0; i<q; ++i){
        std::cin>>tipo;
        if(tipo==1){
            std::cin>>x;
            pila.push_front(x);
            cola.push_back(x);
        }
        else if (tipo==2){
            if(cola.empty() || pila.empty()){
                break;
            }
            pila.pop_back();
            cola.pop_front();   
        }
        else if(tipo==3){
            if(pila.empty()){
                std::cout<<"EMPTY";
               // break;
            }
            else
                std::cout<<pila.front();
        }
        else{
            for(int i=0; i<cola.size(); ++i){
                int k = cola.back();
                Aux1.push_front(k);
                cola.pop_back();
            }
            for(int i=0; i<pila.size(); ++i){
                int k = pila.front();
                Aux2.push_back(k);
                pila.pop_front();
            }
            for (int i=0; i<Aux1.size()+Aux2.size(); ++i){
                pila.push_back(Aux1.back());
                cola.push_front(Aux2.front());
            }
        }
    }
}