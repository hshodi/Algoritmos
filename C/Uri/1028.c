#include <stdio.h>

typedef struct dupla{
	unsigned int a;
	unsigned int b;
}Dupla;

unsigned int euclidean_GDC(unsigned int a, unsigned int b){
	if(!b)
		return a;
	else
		return euclidean_GDC(b, a % b);
}

int main(int argc, char **argv){
	
	int times;
	Dupla dupla;
	scanf("%d", &times);
s1: 	if(times){
		scanf("%d", &dupla.a);
		scanf("%d", &dupla.b);
		printf("%d\n", euclidean_GDC(dupla.a, dupla.b));
		times--;
		goto s1;
	}

	return 0;
}
