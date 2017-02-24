#include <stdio.h>

int calc(double food){
    if(food <= 1){
        return 0;
    }
    else{
        return 1 + calc(food / 2);
    }
}

int main(int argc, char *argv[]){

    int counter;
    double food_qtd;

    scanf("%d", &counter);
    while(counter--){
        scanf("%lf", &food_qtd);
        printf("%d dias\n", calc(food_qtd));
    }

    return 0;
}