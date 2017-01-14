#include <stdio.h>
#include <iostream>

using namespace std;

double calcula_gasto_medio(int a, double b){
	double result = a / b;
	return result; 
}

int main(int argc, char *argv[]){
	
	int dist;
	double gasto;
	scanf("%d", &dist);
	scanf("%lf", &gasto);
	double result = calcula_gasto_medio(dist, gasto);

	printf("%.3lf km/l\n", result);

	return 0;
}
