import java.util.Scanner;
import javax.swing.JOptionPane;
public class Main {
 public static void main(String[] args) {
      // instanciar a classe = criar objeto 
      Pessoa p1 = new Pessoa();
      Pessoa p2 = new Pessoa();
      Pessoa p3 = new Pessoa(); 
   
      
      p1.nome = JOptionPane.showInputDialog("Digite o nome");
      p1.idade = Integer.parseInt(JOptionPane.showInputDialog("Digite a idade"));
       JOptionPane.showMessageDialog(null,"Nome: "+ p1.nome + "\nIdade: " +p1.idade);
        Scanner scanner = new Scanner(System.in);
      System.out.print("Qual o seu nome: ");
        p2.nome = scanner.next();
     System.out.println("Qual a sua idade: ");
     p2.idade = scanner.nextInt();
          p2.mostrarDados();
     
     System.out.print("Qual o seu nome: ");
        p3.nome = scanner.next();
     System.out.println("Qual a sua idade: ");
     p3.idade = scanner.nextInt();
     System.out.println("Sua idade é: " +p3.idade);
     p3.mostrarDados();
             
       
       
       
   
    }
    
}
