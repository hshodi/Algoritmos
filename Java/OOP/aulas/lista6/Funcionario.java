package ado;

import java.util.Scanner;

public class Funcionario{

    int codigo;
    String nome;
    String endereco; 

    public void setCodigo(int codigo){
        this.codigo = codigo;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    public void setEndereco(String endereco){
        this.endereco = endereco;
    }

    public void getEndereco(){
        System.out.println("O endereco e: " + this.endereco);
    }

    public void getNome(){
        System.out.println("O nome e: " + this.nome);
    }

    public void getCodigo(){
        System.out.println("O codigo e: " + this.codigo);
    }

}