package HerancaUnica;

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
        quadrado.side_size = 4;
        quadrado.calc_area();
        quadrado.calc_perimetro();
        quadrado.print_values();

        System.out.println("\n\nTriangulo");
        Triangulo triangulo = new Triangulo();
        triangulo.lado = 4;
        triangulo.base = 4;
        triangulo.altura = 5;
        triangulo.calc_area();
        triangulo.calc_perimetro();
        triangulo.print_values();

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