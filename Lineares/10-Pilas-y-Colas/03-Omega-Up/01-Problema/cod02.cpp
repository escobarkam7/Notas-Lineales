#include <iostream>
#include <deque>
#include <string>
int main() {
	std::deque<int> P;
	int n;
	std::cin>>n;
	for(int i = 0;i<n;i++){
		std::string operacion;
		std::cin>>operacion;
		if (operacion == "AGREGA"){
			int v;
			std::cin>>v;
			P.push_back(v);
			
		}else if (operacion == "CONSUME"){
			int suma = P.top();
			P.pop();
			suma+=P.top();
			P.pop_back();
			P.push_back(suma);
		}else if (operacion == "IMPRIME"){
			std::cout<<P.top();
			std::cout<<"\n";
		}
	}
}