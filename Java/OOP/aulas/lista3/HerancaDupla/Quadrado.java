package HerancaDupla;

public class Quadrado extends Quadrilatero{

    void calc_area(){
        this.area = this.altura * this.base;
    }

    void calc_perimetro(){
        this.perimetro = 2 * (this.base + this.altura);
    }

}