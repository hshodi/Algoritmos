package HerancaDupla;

public class Paralelogramo extends Quadrilatero{

    double lado;

    void calc_area(){
        this.area = this.base * this.altura;
    }
    void calc_perimetro(){
        this.perimetro = 2 * (this.base + this.lado);
    }

}