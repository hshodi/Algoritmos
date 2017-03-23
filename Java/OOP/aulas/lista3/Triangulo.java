package lista3;

public class Triangulo extends FiguraGeometrica{

    double lado;
    double base;
    double altura;

    void calc_area(){
        this.area = (base * altura) / 2;
    }

    void calc_perimetro(){
        this.perimetro = (lado * 2) + base;
    }


}