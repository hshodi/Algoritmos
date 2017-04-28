public class Jogador{

    String nome;
    String time;
    String posicao;
    int golQtd;
    int idade;

    Jogador(String name, String position){

        nome = name;
        posicao = position;
        
    }

    public void FazGol(){
        this.golQtd++;
    }

    public void setAge(int i){
        this.idade = i;
    }

    public void setPosition(String x){
        this.posicao = x;
    }

    public int getAge(){
        return this.idade;
    }

    public String getName(){
        return this.nome;
    }

    public int getGolQtd(){
        return this.golQtd;
    }

    public String getPosition(){
        return this.posicao;
    }

}

public class Time{

    String nome;

    Time(String aux, int qtdJogadores){
        nome = aux;
    }

    public void ComprarJogador(String nome, String position){
        Jogador aux = new Jogador(nome, position);
        this.jogadores.add(aux);
    }

    public void setName(String x){
        this.nome = x;
    }

    public String getName(){
        return this.nome;
    }

}