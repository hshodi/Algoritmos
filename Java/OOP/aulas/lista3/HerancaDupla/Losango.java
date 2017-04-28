package HerancaDupla;

public class Losango extends Quadrilatero{

    double diagonal_a;
    double diagonal_b;
    double lado_a;
    double lado_b;

    void calc_area(){
        this.area = (this.diagonal_a * this.diagonal_b) / 2;
    }

    void calc_perimetro(){
        this.perimetro = 2 * (this.lado_a + this.lado_b);
    }

}