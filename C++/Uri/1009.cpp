#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class func{
	public:
		char *nome;
		double fixo;
		double venda;
		double salario();
};

double func::salario(){
	
	double total = venda * 0.15;
	return fixo + total;

}

int main(int agrc, char *argv[]){
	
	func primary;
	primary.nome = (char *)malloc(50 * sizeof(char));
	scanf("%s", primary.nome);
	scanf("%lf", &primary.fixo);
	scanf("%lf", &primary.venda);
	printf("TOTAL = R$ %.2lf\n", primary.salario()); 
	return 0;
}
