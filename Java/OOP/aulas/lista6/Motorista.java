package ado;

public class Motorista extends Funcionario{

    int CNH;

    public void setCNH(int CNH){
        this.CNH = CNH;
    }

    public void getCNH(){
        System.out.println("A CNH E: " + this.CNH);
    }

}