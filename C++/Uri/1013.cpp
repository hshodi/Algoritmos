#include <iostream>
#include <stdio.h>

using namespace std;

int abs(int a){
	return a >= 0 ? a : -a;
}

int maior(int a, int b){
	return (a + b + abs(a - b)) / 2;
}

int result(int a, int b, int c){
	return maior(maior(a, b), c);
}

int main(int argc, char *argv[]){

	int a, b, c;

	while(scanf("%d", &a) != EOF && scanf("%d", &b) != EOF && scanf("%d", &c) != EOF){
		printf("%d eh o maior\n", result(a, b, c));

	}



}
