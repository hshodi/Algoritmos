#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){
	
	int a[] = {5, 3, 4, 9, 10, 8, 0, 1, 2, 5, 43, 1, 0, 5};
	int size = sizeof(a) / sizeof(int);
	int aux = -1, i;
	for(i = 0; i < size; i++){
		if(a[i] > aux){
			aux = a[i];
		}
	}
	if(aux != -1){
		int *vetor_aux;
		aux++;
		vetor_aux = (int *)malloc(aux * sizeof(int));
		for(i = 0; i < aux; i++){
			vetor_aux[i] = 0;
		}
		
		for(i = 0; i < size; i++){
			vetor_aux[a[i]]++;
		}
		
		for(i = 0; i <= aux; i++){
			vetor_aux[i + 1] = vetor_aux[i] + vetor_aux[i + 1]; 
		}
		
		int *ordenado;
		ordenado = (int *)malloc(size * sizeof(int));
		for(i = 0; i < size; i++){
			ordenado[vetor_aux[a[i]] - 1] = a[i];
			vetor_aux[a[i]]--;
		}
		for(i = 0; i < size; i++){
			printf("%d ", ordenado[i]);
		}
		printf("\n");
		free(vetor_aux);
		free(ordenado);
	}

	return 0;
}