public class Fibonacci{

    //Nao entendi o problema, pois o 5 numero da sequencia de Fibonacci nao é 8
    //Sequencia:  0 1 1 2 3 5 8
    //Para obtermos 8 como resultado deveriamos ter como parametro para a funcao o valor 7

    public static int calculaFibonacci(int a){
        if (a <= 1) return a;
        return calculaFibonacci(a - 1) + calculaFibonacci(a - 2);
    }

}