package HerancaUnica;

public class Losango extends FiguraGeometrica{

    double diagonal_a;
    double diagonal_b;
    double lado_a;
    double lado_b;

    void calc_area(){
        this.area = (diagonal_a * diagonal_b) / 2;
    }

    void calc_perimetro(){
        this.perimetro = 2 * (lado_a + lado_b);
    }

}