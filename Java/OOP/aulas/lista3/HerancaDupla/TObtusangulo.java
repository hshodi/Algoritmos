package HerancaDupla;

public class TObtusangulo extends Triangulo{

    double outro_lado;

    void calc_area(){
        this.area = this.altura * this.base / 2;
    }
    void calc_perimetro(){
        this.perimetro = this.altura + this.base + this.outro_lado;
    }

}