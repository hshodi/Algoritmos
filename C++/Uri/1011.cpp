#include <iostream>
#include <stdio.h>

#define PI 3.14159

using namespace std; 

double pow(double num, int potencia){
	if(!potencia){
		if(!num){
			printf("INDETERMINACAO\n");
		}
		else{
			return 1;
		}
	}

	if(potencia == 1){
		return num;
	}
	else{
		return num * pow(num, potencia - 1);
	}

}

int main(int argc, char *argv[]){

	int raio, potencia;
	while(scanf("%d", &raio) != EOF){
		printf("VOLUME = %.3lf\n", (4 / 3.0) * PI * (pow(raio, 3))); 
	
	}
	return 0;

}
