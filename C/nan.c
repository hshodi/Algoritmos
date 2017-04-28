#include <stdio.h>

long double factorial(int num){
	if(!num || num == 1){
		return 1;
	}else{
		return num * factorial(num - 1);
	}

}

int main(int agrc, char *argv[]){

	int a;
	scanf("%d", &a);
	long double result;
	result = factorial(a);
	printf("valor de a: %Lf\n", result);
	printf("comparacao: %lu\n", sizeof(long long unsigned int));

}
