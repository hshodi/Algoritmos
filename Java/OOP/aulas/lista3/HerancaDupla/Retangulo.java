package HerancaDupla;

public class Retangulo extends Quadrilatero{

    void calc_area(){
        this.area = this.altura * this.base;
    }

    void calc_perimetro(){
        this.perimetro = 2 * (this.altura + this.base);
    }

}