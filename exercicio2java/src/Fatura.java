
public class Fatura {
    private String numero;
    private String descricao;
    private int quantidade;
    private double preco;
    
  public Fatura(){
      
  }
 
 public Fatura(String numero, String descricao, int quantidade,double preco){
     getNumero();
     setNumero(numero);
     getDescricao();
     setDescricao(descricao);
     getQuantidade();
     setQuantidade(quantidade);
     getPreco();
     setPreco(preco);
    
 }
    
    
 public String getNumero(){
    return numero;
    }
public String getDescricao(){
    return descricao;
}
 public int getQuantidade(){
    return quantidade;
 }
 public double getPreco(){
    return preco;
 }
 
 public void setNumero(String numero){
     //se meu parâmetro é igual ao meu atributo, uso o this.
     this.numero = numero;
 }
 public void setDescricao(String descricao){
     this.descricao = descricao;
 }
 public void setQuantidade(int quantidade){
     this.quantidade = quantidade;
 }
public void setPreco(double preco){
    this.preco = preco;
    if(preco<0){
        this.preco = 0.0;
    }else{ 
        this.preco = preco;
    }
}

    
public double getTotalFatura(){
    //colocar restrução dentro do set
    double totalFatura;
    totalFatura = preco * quantidade;
    if(totalFatura<=0){
        totalFatura = 0;
    }
    System.out.println("Total da fatura: "+totalFatura);
    return totalFatura;
}
    
    
 
    
}
