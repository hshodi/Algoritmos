package HerancaDupla;

public class Triangulo extends FiguraGeometrica{

    double base;
    double altura;

    void calc_area(){
        this.area = (this.base * this.altura) / 2;
    }

}