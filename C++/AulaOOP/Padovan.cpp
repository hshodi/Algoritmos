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
            return Padovan(x - 2) + Padovan(x - 3);
    }

}

bool prime(int x){

    if(x % 2 == 0 && x != 2 || x == 1){
        return false;
    }else{
        for(int i = x - 1; i > 0; i--){
            if(x % i == 0){
                return false;
            }
        }
    }
    return true;

}

int main(int argc, char *agrv[]){

    Calculus a;

    int counter = QTD_VALUES;
    for(int i = 0; counter > 0; i++){
        a.val = a.padovan(i);
        if(prime(a.val) && a.before_val != a.val){
            printf("%d", a.val);
            a.before_val = a.val;
            
        }

    }

    return 0;
}