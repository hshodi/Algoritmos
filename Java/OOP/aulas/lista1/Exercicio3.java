public class Exercicio3 {

        public static void main(String[] args){
                int min = 33;
                int max = 143;
		int i;
                int counter = 0;
                for(i = min; i <= max; i++){
                        if(i % 7 == 0){
                                System.out.println(i);
                                counter++;
                        }
                }
                System.out.println("Quantidade de iteracoes: " + counter);
        }

}

