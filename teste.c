#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000



void swap(int *a, int *b){
	
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	
}

void merging(int *a, int *b, int low, int mid, int high) {
   int l1, l2, i;

   for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
      if(a[l1] <= a[l2])
         b[i] = a[l1++];
      else
         b[i] = a[l2++];
   }

   while(l1 <= mid)    
      b[i++] = a[l1++];

   while(l2 <= high)   
      b[i++] = a[l2++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void mergeSort(int *a, int *b, int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      mergeSort(a, b, low, mid);
      mergeSort(a, b, mid+1, high);
      merging(a, b, low, mid, high);
   }else { 
      return;
   }   
}

void quick_sort(int arr[],int low,int high){
	 int pivot,j,temp,i;
	 if(low<high){
		  pivot = low;
		  i = low;
		  j = high;
		 
			while(i<j){
			   	while((arr[i]<=arr[pivot])&&(i<high)){
			  		i++;
			    }
			 
			   	while(arr[j]>arr[pivot]){
			   		j--;
			    }
			 
			   	if(i<j){ 
				    swap(&arr[i], &arr[j]);
				}
		}
		 
		  swap(&arr[pivot], &arr[j]);
		  quick_sort(arr,low,j-1);
		  quick_sort(arr,j+1,high);
	 }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
    //http://quiz.geeksforgeeks.org/selection-sort/
}


void bubble(int a[], int size){
	int i;
	int j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size - 1; j++){
			if(a[j] > a[j + 1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
	//implementado por mim
}


int main(int argc, char const *argv[]){
	clock_t begin = clock();
	FILE *arq;
	int *a;
	a = (int *)malloc(SIZE * sizeof(4));
	int tam = SIZE;
	int *b;
	b = (int *)malloc(SIZE * sizeof(4));		

	int j;
	int i;
	for(i = 0; i < tam; i++){
		a[i] = rand() % 10000;
	}
	bubble(a, tam);
	clock_t end = clock();
	arq = fopen("teste.txt", "w+");
	for(j = 0; j < tam; j++){
		fprintf(arq, "%d\n", a[j]);
	}
	fclose(arq);
	free(a);
	free(b);
	double total = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("%.5lf", total);
	return 0;
}
