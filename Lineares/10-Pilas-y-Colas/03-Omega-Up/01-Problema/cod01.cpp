#include <iostream>
#include <stack>
#include <string>
int main() {
	std::stack<int> P;
	int n;
	std::cin>>n;
	for(int i = 0;i<n;i++){
		std::string operacion;
		std::cin>>operacion;
		if (operacion == "AGREGA"){
			int v;
			std::cin>>v;
			P.push(v);
			
		}else if (operacion == "CONSUME"){
			int suma = P.top();
			P.pop();
			suma+=P.top();
			P.pop();
			P.push(suma);
		}else if (operacion == "IMPRIME"){
			std::cout<<P.top();
			std::cout<<"\n";
		}
	}
}