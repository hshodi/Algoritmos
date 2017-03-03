#include <stdio.h>
#define QTD_VALUES 5


using namespace std;

class Calculus{
    public:
        int val;
        int before_val = 0;
        int padovan(int x);
};

int Calculus::padovan(int x){
    switch(x){
        case 0:
            return 1;
        case 1: 
            return 1;
        case 2:
            return 1;
        default:
            return padovan(x - 2) + padovan(x - 3);
    }

}

int prime(int x){
    if(x % 2 == 0 && x != 2 || x == 1) return 0;
    for(int i = x - 1; i > 1; i--){
        if(x % i == 0) return 0;
    }
    return 1;
}

int main(int argc, char *agrv[]){

    Calculus a;

    int counter = QTD_VALUES;
    for(int i = 0; counter > 0; i++){
        a.val = a.padovan(i);
        if(prime(a.val) && a.before_val != a.val){
            printf("%d\n", a.val);
            a.before_val = a.val;
            counter--;
        }

    }

    return 0;
}