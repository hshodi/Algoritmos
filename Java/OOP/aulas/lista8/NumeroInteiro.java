package ado8;

public class NumeroInteiro{

    int a;
    int b;

    NumeroInteiro(int first, int second){
        this.a = first;
        this.b = second;
    }

    public void soma(){
        System.out.println(this.a + this.b);
    }

    public void subtracao(){
        System.out.println(this.a - this.b);
    }

    public void multiplicacao(){
        System.out.println(this.a * this.b);
    }

    public void divisao(){
        try{
            System.out.println(this.a / this.b);
        }catch (Exception e){
            System.out.println("Nao foi possível dividir " + this.a + " por " + this.b);
        }
    }

}