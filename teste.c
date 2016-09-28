#include <stdio.h>
#include <stdlib.h>




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

	int *a;
	a = malloc(10000 * sizeof(4));
	
	int tam = 10000;

	int j;
	int i;
	for(i = 0; i < tam; i++){
		a[i] = rand() % 1000000;
	}
	bubble(a, tam);
	for(j = 0; j < tam; j++){
		printf("%d ", a[j]);
	}
	printf("\n");
	

	return 0;
}