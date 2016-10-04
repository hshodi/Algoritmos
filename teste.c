#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000



void swap(int *a, int *b){
	
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
	
}

void shell_sort (int *a, int n) {
    int h, i, j, t;
    for (h = n; h /= 2;) {
        for (i = h; i < n; i++) {
            t = a[i];
            for (j = i; j >= h && t < a[j - h]; j -= h) {
                a[j] = a[j - h];
            }
            a[j] = t;
        }
    }
}


int separa (int v[], int p, int r) 
{
   int c = v[p], i = p+1, j = r, t;         // 1
   while (1) {                              // 2
      while (i <= r && v[i] <= c) ++i;      // 3
      while (c < v[j]) --j;                 // 4
      if (i >= j) break;                    // 5
      t = v[i], v[i] = v[j], v[j] = t;      // 6
      ++i; --j;                             // 7
   }                                        // 8
   v[p] = v[j], v[j] = c;                   // 9
   return j;                                // 10
}


void 
quicksort (int v[], int p, int r)
{
   int j;                         // 1
   if (p < r) {                   // 2
      j = separa (v, p, r);       // 3
      quicksort (v, p, j-1);      // 4
      quicksort (v, j+1, r);      // 5
   }
}

static void 
intercala1 (int p, int q, int r, int v[]) 
{
   int i, j, k, *w;                        //  1
   w = malloc ((r-p) * sizeof (int));     //  2
   i = p; j = q;                           //  3
   k = 0;                                  //  4

   while (i < q && j < r) {                //  5
      if (v[i] <= v[j])  w[k++] = v[i++];  //  6
      else  w[k++] = v[j++];               //  7
   }                                       //  8
   while (i < q)  w[k++] = v[i++];         //  9
   while (j < r)  w[k++] = v[j++];         // 10
   for (i = p; i < r; ++i)  v[i] = w[i-p]; // 11
   free (w);                               // 12
}

void
mergesort (int p, int r, int v[])
{
   if (p < r-1) {                 // 1
      int q = (p + r)/2;          // 2
      mergesort (p, q, v);        // 3
      mergesort (q, r, v);        // 4
      intercala1 (p, q, r, v);     // 5
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

int quick_part(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 	int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 
int aux (int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 	int j;
    for (j = l; j <= h- 1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap (&arr[i], &arr[j]);
        }
    }
    swap (&arr[i + 1], &arr[h]);
    return (i + 1);
}
 

void quickSortIterative (int arr[], int l, int h)
{
    // Create an auxiliary stack
    int stack[ h - l + 1 ];
 
    // initialize top of stack
    int top = -1;
 
    // push initial values of l and h to stack
    stack[ ++top ] = l;
    stack[ ++top ] = h;
 
    // Keep popping from stack while is not empty
    while ( top >= 0 )
    {
        // Pop h and l
        h = stack[ top-- ];
        l = stack[ top-- ];
 
        // Set pivot element at its correct position
        // in sorted array
        int p = aux( arr, l, h );
 
        // If there are elements on left side of pivot,
        // then push left side to stack
        if ( p-1 > l )
        {
            stack[ ++top ] = l;
            stack[ ++top ] = p - 1;
        }
 
        // If there are elements on right side of pivot,
        // then push right side to stack
        if ( p+1 < h )
        {
            stack[ ++top ] = p + 1;
            stack[ ++top ] = h;
        }
    }
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
		

	int j;
	int i;
	for(i = 0; i < tam; i++){
		a[i] = rand() % 10000;
	}
	quickSortIterative(a, 0, tam - 1);
	clock_t end = clock();
	arq = fopen("teste.txt", "w+");
	double total = (double)(end - begin) / CLOCKS_PER_SEC;
	fprintf(arq, "%.100lf", total);
	for(j = 0; j < tam; j++){
		fprintf(arq, "%d\n", a[j]);
	}
	fclose(arq);
	free(a);
	
	printf("%.20lf", total);
	return 0;
}
