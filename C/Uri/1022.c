#include <stdio.h>
#include <stdlib.h>

#define STRING_SIZE 50

typedef struct fracao {
	int numerador;
	int denominador;
}Fracao;

typedef struct operacao{
	
	Fracao fracao_a;
	Fracao fracao_b;
	char operacao;

}Operacao;

unsigned int euclidean_mdc(int a, int b){

	if(!b)
		return a;
	else
		return euclidean_mdc(b, a % b);

}

Fracao simplifica(Fracao a){

	printf("MDC: %d", euclidean_mdc(a.numerador, a.denominador);

}

Fracao divisao_fracao(Operacao *x){

	Fracao aux;
	int n1 = x->fracao_a.numerador;
	int d1 = x->fracao_a.denominador;
	int n2 = x->fracao_b.numerador;
	int d2 = x->fracao_b.denominador;

	aux.numerador = n1 * d2;
	aux.denominador = n2 * d1;

	return aux;
}

Fracao multiplicacao_fracao(Operacao *x){

	Fracao aux;
	int n1 = x->fracao_a.numerador;
	int d1 = x->fracao_a.denominador;
	int n2 = x->fracao_b.numerador;
	int d2 = x->fracao_b.denominador;

	aux.numerador = n1 * n2;
	aux.denominador = d1 * d2;

	return aux;
}

Fracao soma_fracao(Operacao *x){

	Fracao aux;
        int n1 = x->fracao_a.numerador;
	int d1 = x->fracao_a.denominador;
	int n2 = x->fracao_b.numerador;
	int d2 = x->fracao_b.denominador;

	aux.numerador = (n1 * d2) + (n2 * d1);
	aux.denominador = d1 * d2;

	return aux;
}

Fracao subtracao_fracao(Operacao *x){

	Fracao aux;
        int n1 = x->fracao_a.numerador;
        int d1 = x->fracao_a.denominador;
        int n2 = x->fracao_b.numerador;
        int d2 = x->fracao_b.denominador;

	aux.numerador = (n1 * d2) - (n2 * d1);
	aux.denominador = d1 * d2;

	return aux;
}

void get_simplificacao(Operacao *x){
	
	Fracao aux;
	switch(x->operacao){
		case '/':
		case '*':
		break;
		case '-':
		case '+':
		break;
	}

}

int main(int argc, char  **argv) {

	Operacao a;

	char *linha = (char *)malloc(50 * sizeof(char));

	int count;

	scanf("%d ", &count);

	while(count--){
		
		scanf("%[^\n]s", linha);
		a.fracao_a.numerador = atoi(linha[0]);
		a.fracao_a.denominador = atoi(linha[4]);

		a.operacao = linha[6];

		a.fracao_b.numerador = atoi(linha[8]);
		a.fracao_b.denominador = atoi(linha[12]);

	}
	
	free(linha);

	return 0;
}
