#include <iostream>
#include <stdio.h>

#define PI 3.14159

using namespace std;

double power(double a, int b){
	if(!a){
		if(!b){
			printf("INDETERMINACAO\n");
		}
		else{
			return 1;
		}
	}
	if(b == 1){
		return a;
	}
	else{
		return a * power(a, b - 1);
	}
}		

double area_triangulo(double a, double b){
	return (a * b) / 2;
}
	
double area_circulo(double a){
	return (PI * power(a, 2));
}

double area_trapezio(double a, double b, double c){
	return ((a + b) * c) / 2;
}

double area_quadrado(double a){
	return (power(a, 2));
}

double area_retangulo(double a, double b){
	return a * b;
}

int main(int agrc, char *argv[]){

	double a, b, c;
	while(scanf("%lf", &a) != EOF && scanf("%lf", &b) != EOF && scanf("%lf", &c) != EOF){
		printf("TRIANGULO: %.3lf\n", area_triangulo(a, c));
		printf("CIRCULO: %.3lf\n", area_circulo(c));
		printf("TRAPEZIO: %.3lf\n", area_trapezio(a, b, c));
		printf("QUADRADO: %.3lf\n", area_quadrado(b));
		printf("RETANGULO: %.3lf\n", area_retangulo(a, b));
	}

	return 0;
}
