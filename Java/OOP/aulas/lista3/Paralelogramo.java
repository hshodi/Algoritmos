package lista3;

public class Paralelogramo extends FiguraGeometrica{

    double base;
    double altura;
    double lado;

    void calc_area(){
        this.area = base * altura;
    }
    void calc_perimetro(){
        this.perimetro = 2 * (base + lado);
    }

}