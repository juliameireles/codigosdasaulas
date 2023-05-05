/* QUESTÃO = 9.Elabore um algoritmo que permita ao usuário realizar a compra de frutas. 
Assim, apresente a lista de frutas disponíveis, abaixo, com seus respectivos valores.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    char m = 'm';
    int quantabacaxi,quantmaca,quantpera;
    float calc;

    do{ system("cls");
        printf("======MENU FRUTAS======\n"); 
        printf("1 => ABACAXI --5,00 a unidade\n");
        printf("2 => MACA -- 1,00 a unidade\n");
        printf("3 => PERA -- 4,00 a unidade\n");

        printf("Indique a quantidade de cada fruta (se nao quiser determinada fruta, digite 0):\n");
        printf("ABACAXI: ");
        scanf("%d",&quantabacaxi);
        printf("MACA: ");
        scanf("%d",&quantmaca);
        printf("PERA: ");
        scanf("%d",&quantpera);
        calc = quantabacaxi*5.0 + quantmaca*1.0 + quantpera*4.0;
        printf("O valor total da compra foi: %.2f\n",calc);

        printf("Digite 'm' para retornar ao menu: ");
         m = getchar();
    }while(m = getchar());
    return 0; 
}
