#include <iostream>
#include <stdio.h>


using namespace std;

const double pi = 3.14159;

double area(double raio){
	return pi * (raio * raio);
}

int main(){

	
	double raio;
	cin >> raio;
	printf("A=%.4lf\n", area(raio));

	return 0;
}
