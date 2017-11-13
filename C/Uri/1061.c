#include <stdio.h>
#include <stdlib.h>

typedef struct Evento {

    unsigned int dias;
    unsigned int horas;
    unsigned int minutos;
    unsigned int segundos;

} Evento;

void printEvent(Evento *x) {
    printf(
        "%d dia(s)\n"\
        "%d hora(s)\n"\
        "%d minuto(s)\n"\
        "%d segundo(s)\n"\
    , x->dias, x->horas, x->minutos, x->segundos);
}

void getEvent(Evento *x) {
    scanf(
        "Dia %d\n"\
        "%d : %d : %d\n"
    , &(x->dias), &(x->horas), &(x->minutos), &(x->segundos));
}

Evento* getEventTime(Evento *init, Evento *fim) {
    printEvent(init);
    printEvent(fim);    
    Evento *duracao = (Evento *)malloc(sizeof(Evento));

    

    return duracao;
}

int main (int argc, char **argv) {
    Evento inicio, fim;

    getEvent(&inicio);
    getEvent(&fim);
    
    printEvent(getEventTime(&inicio, &fim));

    return 0;
}