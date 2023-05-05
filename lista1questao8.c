/* QUESTÃO = 8. Elabore um programa que faça a leitura de vários números inteiros até que se digite um número negativo. 
O programa tem de retornar o maior e o menor número lido*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int valor, maior=0,menor=9999;
    do{
        printf("Digite um valor inteiro: ");
        scanf("%d",&valor);
        if(valor>maior){
            maior = valor;
        }
        if(valor< menor ){
            menor =valor;
        }
    }while(valor >=0 );

    printf("O menor valor digitado foi: %d\n",menor);
    printf("O maior valor digitado foi: %d\n",maior); 

    return 0;
}


