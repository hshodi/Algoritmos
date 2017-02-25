import java.util.Scanner;

public class Main{

	public static int soma(int a, int b){
		return a + b;
	}

	public static void main(String[] args){
		Scanner io = new Scanner(System.in);
		int a = io.nextInt();
		int b = io.nextInt();

		System.out.println("X = " + soma(a, b));
	}

}
