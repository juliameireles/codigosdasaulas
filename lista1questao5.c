/* QUESTÃO = 5.Faça um algoritmo que leia um número positivo e imprima seus divisores. Exemplo:
Os divisores do número 66 são: 1, 2, 3, 6, 11, 22, 33 e 66.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int num;
    long int cont = 1;
    printf("Digite um numero positivo: "); 
    scanf("%d",&num);
    printf("OS DIVISORES DE %d SAO:\n",num);
    for(cont=1;cont<=1000000000;cont++){
        if(num % cont ==0){
            printf("%li  ",cont);
        }
    }
    return 0; 
}