package ado2.Time;

import java.util.ArrayList;

public class Time{

    String nome;
    Jogador jogadores;

    Time(String aux, int qtdJogadores){
        nome = aux;
        jogadores = new ArrayList<>();
    }

    public void ComprarJogador(String nome, String position){
        Jogador aux = new Jogador(nome, position);
        this.jogadores.add(aux);
    }

    public int getPlayersQtd(){
        return this.jogadores.size();
    }

    public void setName(String x){
        this.nome = x;
    }

    public String getName(){
        return this.nome;
    }

}