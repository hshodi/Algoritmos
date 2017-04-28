package HerancaUnica;

public class Circulo extends FiguraGeometrica{

    double raio;
    double pi = 3.14;

    void calc_area(){
        this.area = pi * (raio * raio);
    }

    void calc_perimetro(){
        this.perimetro = 2 * raio * pi;
    }

}