#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#if !defined( Hello )

void bubble(int a[], int size){
	int i;
	int j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size - 1; j++){
			if(a[j] > a[j + 1]){
				a[j] ^= a[j + 1];
				a[j + 1] ^= a[j];
				a[j] ^= a[j + 1];
			}
		}
	}
}

int main(int argc, char const *argv[]){
	clock_t begin = clock();
	FILE *arq;
	int *a;
	a = malloc(10000000 * sizeof(4));
	
	int tam = 10000000;

	int j;
	int i;
	for(i = 0; i < tam; i++){
		a[i] = rand() % 1000000000;
	}
	bubble(a, tam);
	arq = fopen("teste.txt", "w+");
	for(j = 0; j < tam; j++){
		fprintf(arq, "%d\n", a[j]);
	}
	free(arq);
	free(a);
	clock_t end = clock();
	double total = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.5lf", total);
	return 0;
}
