#include <iostream>
#include <stdio.h>

using namespace std;


int main(){

	int a, b, c, d;
	while(scanf("%d", &a) != EOF && scanf("%d", &b) != EOF &&
		scanf("%d", &c) != EOF && scanf("%d", &d) != EOF){
		printf("DIFERENCA = %d\n", ((a * b) - (c * d)));
	}

	return 0;
}
