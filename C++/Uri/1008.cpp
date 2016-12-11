#include <iostream>
#include <stdio.h>

using namespace std;

class funcionario{
	public:
		int numero;
		int salario;
		double horas;
};

double salario(int preco, double horas){
	return preco * horas;

}

int main(){

	funcionario primary;
	scanf("%d", &primary.numero);
	scanf("%d", &primary.salario);
	scanf("%lf", &primary.horas);
	printf("NUMBER = %d\n", primary.numero);
	printf("SALARY = U$ %.2lf\n", salario(primary.salario, primary.horas)); 
	
	return 0;

}
