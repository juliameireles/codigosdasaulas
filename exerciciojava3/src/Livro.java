

public class Livro {
    public String titulo; 
    public String autor; 
    public int numPaginas; 
    
   public Livro(String titulo,String autor, int numPaginas){
       this.titulo = titulo;
        this.autor = autor;
        this.numPaginas = numPaginas;  
   }
 
 public Livro(){
     
 }
        
    public void imprimirInfo(){
        System.out.println("Titulo: "+titulo);
        System.out.println("autor: "+autor);
        System.out.println("Numero de paginas: "+numPaginas);
        
    }
    
    
    
    
}