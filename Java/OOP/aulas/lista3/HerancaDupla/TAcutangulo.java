package HerancaDupla; 

public class TAcutangulo extends Triangulo{

    double outro_lado;

    void calc_area(){
        this.area = (this.base * this.altura) / 2;
    }
    void calc_perimetro(){
        this.perimetro = this.outro_lado + this.base + this.altura;
    }

}