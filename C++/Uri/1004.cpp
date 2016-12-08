#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

	int a, b;
	while(scanf("%d", &a) != EOF && scanf("%d", &b) != EOF){
		printf("PROD = %d\n", a * b);
	}
	
	return 0;
}
