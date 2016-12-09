#include <iostream>
#include <stdio.h>

using namespace std;

int main(){


	double a, b;

	while(scanf("%lf", &a) != EOF && scanf("%lf", &b) != EOF){
		printf("MEDIA = %.5lf\n", (((a * 3.5) + (b * 7.5)) / (3.5 + 7.5)));
	}
	return 0;
}
