#include <stdio.h>

int* createInt(void) {
	int a = 5;
	return &a;
}

int main(void) {
	int *a;
	a = createInt();
	printf("value %d", *a);
	return 0;
}
