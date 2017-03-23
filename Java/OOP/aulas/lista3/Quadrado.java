package lista3;

public class Quadrado extends FiguraGeometrica{

    double side_size;

    void calc_area(){
        this.area = side_size * side_size;
    }

    void calc_perimetro(){
        this.perimetro = 4 * side_size;
    }

}