package HerancaDupla;

public class TRetangulo extends Triangulo{

    double hipotenusa;

    void calc_area(){
        this.area = (this.altura * this.base) / 2;
    }
    void calc_perimetro(){
        this.perimetro = this.altura + this.base + this.hipotenusa;
    }

}