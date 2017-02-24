#include <stdio.h>
#include <stdlib.h>

#define A 65
#define Z 90
#define a 97
#define z 122

#define init(a)\
    printf("["__FILE__"] Compiled in ("__TIME__") >>> "#a);

void print(char** argv){
	printf("["__FILE__"] Compiled in ("__TIME__") >>> %s\n", *argv);
}

void scan(char* var){
	init();
	scanf("%[^\n]s", var);
}

int main(int agrc, char* argv[]){

    char* __cyphered_text__;
    __cyphered_text__ = (char *)malloc(200 * sizeof(char));
    scan( __cyphered_text__ );
    print( &__cyphered_text__ );
    free( __cyphered_text__ );

    return 0;
}
