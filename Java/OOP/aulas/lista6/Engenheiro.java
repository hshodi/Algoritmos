package ado;
import ado.Funcionario;
public class Engenheiro extends Funcionario{

    int CREA;

    public void setCREA(int crea){
        this.CREA = crea;
    }

    public void getCREA(){
        System.out.println("O CREA e: " + this.CREA);
    }

}