#include <iostream>
#include <stdio.h>
#include <list>

int main (){
    int N, M, I, S;
    std::cin>> N >> M;
    std:: list<int> lista(N, 0);

    for (int i = 0; i < M; ++i){
        std::cin>>I>>S;
        auto it = lista.begin();
        std::advance(it, I);

        for(int i = I; i < S; ++i){
            (*it) += 1; //Modificar el valor del nodo al que apunta el it
            ++it;
        }

        for (int num : lista)
            std::cout<<num<<" ";
        std::cout<<"\n"; 
    }

}