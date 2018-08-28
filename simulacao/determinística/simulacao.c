#include <stdio.h>
#include <stdlib.h>

/** 
 *  Simulação determinística do deslocamento de uma partícula
 *  com movimento uniforme.
**/

void connect_velocity_gnuplot(FILE **gnuplot) {
    *gnuplot = popen("gnuplot --persist", "w");
    if (*gnuplot == NULL) {
        fprintf(stderr, "Erro ao abrir o gnuplot no modo persistente\n.");
    }
    fprintf(*gnuplot, "set terminal png\n");
    fprintf(*gnuplot, "set output '%s'\n", "velocity.png");
    fprintf(*gnuplot, "set ylabel \"Velocidade (m/s)\"\n");
    fprintf(*gnuplot, "set xlabel \"Tempo (s)\"\n");
    fprintf(*gnuplot, "plot '-' with lines\n");
}

void connect_aceleration_gnuplot(FILE **gnuplot) {
    *gnuplot = popen("gnuplot --persist", "w");
    if (*gnuplot == NULL) {
        fprintf(stderr, "Erro ao abrir o gnuplot no modo persistente\n.");
    }
    fprintf(*gnuplot, "set terminal png\n");
    fprintf(*gnuplot, "set output '%s'\n", "aceleration.png");
    fprintf(*gnuplot, "set ylabel \"Aceleração (m/s²)\"\n");
    fprintf(*gnuplot, "set xlabel \"Tempo (s)\"\n");
    fprintf(*gnuplot, "plot '-' with lines\n");
}

void close_gnuplot(FILE **gnuplot) {
    fprintf(*gnuplot, "e\n");
    pclose(*gnuplot);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Passe o parâmetro 'nome do arquivo'.\n");
        exit(1);
    }
    FILE *p = fopen(argv[1], "r");
    FILE *v_gnuplot, *a_gnuplot;
    connect_velocity_gnuplot(&v_gnuplot);
    connect_aceleration_gnuplot(&a_gnuplot);
    if (p == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        exit(1);
    }
    /** Variaveis de entrada da simulação */
    double v_initial;       // em Metros/segundo
    double aceleration;     // em Metros/segundo²

    fscanf(p, "%lf %lf", &v_initial, &aceleration);

    double velocity = v_initial;
    register unsigned int i = 0;
    do {
        velocity = velocity + aceleration;
        printf("Aceleracao: %lf\t", aceleration);
        printf("Velocidade:\t%.2lf\n", velocity);
        fprintf(v_gnuplot, "%u %lf\n", i, velocity);
        fprintf(a_gnuplot, "%u %lf\n", i, aceleration);
        i++;
    } while (fscanf(p, "%lf", &aceleration) != EOF);
    fclose(p);
    close_gnuplot(&v_gnuplot);
    close_gnuplot(&a_gnuplot);
    return 0;
}