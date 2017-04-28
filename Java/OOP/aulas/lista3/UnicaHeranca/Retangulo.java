package HerancaUnica;

public class Retangulo extends FiguraGeometrica{

    double altura;
    double base;

    void calc_area(){
        this.area = altura * base;
    }

    void calc_perimetro(){
        this.perimetro = 2 * (altura + base);
    }

}