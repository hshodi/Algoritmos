package ado;
 
import ado.Prioridade;

public class Secretaria extends Funcionario implements Prioridade{

    String idioma;
    String senha;

    public void setSenha(String senha){
        this.senha = senha;
    }

    public void setIdioma(String idioma){
        this.idioma = idioma;
    }

    public void getIdioma(){
        System.out.println("O idioma falado e: " + this.idioma);
    }

    public boolean autentica(String senha){
        if(this.senha.equals(senha)){
            if(this.idioma.equals("Ingles")){
                return true;
            }
            return false;
        }
        return false;
    }
 
}