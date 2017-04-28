package HerancaDupla;

public class Main{

    public static void main(String[] args){

        System.out.println("\n\nCirculo");        
        Circulo circulo = new Circulo();
        circulo.raio = 5;
        circulo.calc_area();
        circulo.calc_perimetro();
        circulo.print_values();

        System.out.println("\n\nQuadrado");
        Quadrado quadrado = new Quadrado();
        quadrado.base = 4;
        quadrado.altura = 4;
        quadrado.calc_area();
        quadrado.calc_perimetro();
        quadrado.print_values();

        System.out.println("\n\nTriangulo Retangulo");
        TRetangulo triangulo_retangulo = new TRetangulo();
        triangulo_retangulo.altura = 5;
        triangulo_retangulo.base = 7;
        triangulo_retangulo.hipotenusa = 10;
        triangulo_retangulo.calc_area();
        triangulo_retangulo.calc_perimetro();
        triangulo_retangulo.print_values();

        System.out.println("\n\nTriangulo Acutangulo");
        TAcutangulo triangulo_actuangulo = new TAcutangulo();
        triangulo_actuangulo.base = 5;
        triangulo_actuangulo.altura = 7;
        triangulo_actuangulo.outro_lado = 9;
        triangulo_actuangulo.calc_area();
        triangulo_actuangulo.calc_perimetro();
        triangulo_actuangulo.print_values();

        System.out.println("\n\nTriangulo Obtusangulo");
        TObtusangulo triangulo_obtusangulo = new TObtusangulo();
        triangulo_obtusangulo.base = 3;
        triangulo_obtusangulo.altura = 2.7;
        triangulo_obtusangulo.outro_lado = 3.2;
        triangulo_obtusangulo.calc_area();
        triangulo_obtusangulo.calc_perimetro();
        triangulo_obtusangulo.print_values();

        System.out.println("\n\nLosango");
        Losango losango = new Losango();
        losango.diagonal_a = 6;
        losango.diagonal_b = 4;
        losango.lado_a = 2;
        losango.lado_b = 2;
        losango.calc_area();
        losango.calc_perimetro();
        losango.print_values();

        System.out.println("\n\nRetangulo");
        Retangulo retangulo = new Retangulo();
        retangulo.altura = 3;
        retangulo.base = 10;
        retangulo.calc_area();
        retangulo.calc_perimetro();
        retangulo.print_values();

        System.out.println("\n\nParalelogramo");
        Paralelogramo paralelogramo = new Paralelogramo();
        paralelogramo.base = 5;
        paralelogramo.altura = 3;
        paralelogramo.lado = 3;
        paralelogramo.calc_area();
        paralelogramo.calc_perimetro();
        paralelogramo.print_values();

    }

}