package ado;

import ado.Prioridade;

public class Gerente extends Funcionario implements Prioridade{

    String departamento;
    String senha;

    public void setDepartamento(String departamento){
        this.departamento = departamento;
    }

    public void setSenha(String senha){
        this.senha = senha;
    }

    public boolean autentica(String senha){
        if(this.senha.equals(senha)){
            if(this.departamento.equals("RH") || this.departamento.equals("Compras") || this.departamento.equals("Departamento Pessoal")){
                return true;
            }
            return false;
        }
        return false;
    }

}