package ado;

import ado.Secretaria;

public class Main{

    public static void main(String[] args){

        Secretaria um = new Secretaria();
        um.setIdioma("Portugues");
        um.setSenha("oie");
        if(um.autentica("oie")) System.out.println("AUTENTICADO");
        else System.out.println("NAO AUTENTICADO");

        Gerente dois = new Gerente();
        dois.setSenha("123");
        dois.setDepartamento("RH");
        if(dois.autentica("123")) System.out.println("AUTENTICADO");
        else System.out.println("NAO AUTENTICADO");
    }

}