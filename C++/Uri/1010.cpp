#include <iostream>
#include <stdio.h>

using namespace std;

class Transacao{

	public:
		int codigo;
		int qtd;
		double preco;
		double calcula_preco();
};

double Transacao::calcula_preco(){
	return qtd * preco;
}

int main(int agrc, char *argv[]){

	Transacao primeira, segunda;
	scanf("%d", &primeira.codigo);
	scanf("%d", &primeira.qtd);
	scanf("%lf", &primeira.preco);
	
	scanf("%d", &segunda.codigo);
	scanf("%d", &segunda.qtd);
	scanf("%lf", &segunda.preco);
	
	printf("VALOR A PAGAR: R$ %.2lf\n", primeira.calcula_preco() + segunda.calcula_preco());

	return 0;
}
