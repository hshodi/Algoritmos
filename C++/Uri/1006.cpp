#include <iostream>
#include <stdio.h>

using namespace std;

double media(double a, double b, double c){
	
	double media = a * 2 + b * 3 + c * 5;
	return media / 10;
	
}

int main(){

	double a, b, c;
	while(scanf("%lf", &a) != EOF && scanf("%lf", &b) != EOF && scanf("%lf", &c) != EOF){
		printf("MEDIA = %.1lf\n", media(a, b, c));
	}
	return 0;
}
