#include <stdio.h>
#include <stdlib.h>
int main(){
int A,B,C,D;
int calc;
printf(" Digite o primeiro valor inteiro: ");
scanf("%d",&A);
printf(" Digite o segundo valor inteiro : ");
scanf("%d",&B);
printf(" Digite o terceiro valor inteiro: ");
scanf("%d",&C);
printf(" Digite o quarto valor inteiro : ");
scanf("%d",&D);
calc =( A * B) - (C * D); 

printf("=======CALCULO========\n");
printf(" 'valor de %d' * 'valor de %d' - 'valor de %d' * 'valor de %d' ",A,B,C,D);
printf("\n1======RESULTADO=======\n");
printf("valor de DIFERENCA = %d",calc);

    return 0; 
}