#include <stdio.h>

using namespace std;

int dia_counter(double food){
    if(food <= 1){
        return 0;
    }else{
        return 1 + dia_counter(food / 2);
    }
}

int main(int argc, char *argv[]){

    int count;
    double qtd_food;
    scanf("%d", &count);
    while(count--){
        scanf("%lf", &qtd_food);
        printf("%d dias\n", dia_counter(qtd_food));
    }


    return 0;
}