#include <stdio.h>

int CALLS = 0;

int fib(int value){
	if(value == 0)
		return 0;
	if(value == 1){
		CALLS++;
		return 1;
	}
	CALLS++;
	return fib(value - 1) + fib(value - 2);
}

int main(int argc, char *argv[]){
	int times, value;
	scanf("%d", &times);
s1:	if(times){
		scanf("%d", &value);
		printf("fib(%d) = %d calls = %d\n", value, CALLS, fib(value));
		CALLS = 0;
		times--;
		goto s1;
	}
	return 0;
}
