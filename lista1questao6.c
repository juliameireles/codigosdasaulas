/* QUESTÃO = 6.Faça um programa que exiba a soma de todos os números naturais abaixo de 1.000
que são múltiplos de 3 ou 5.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("=====SOMA DE TODOS OS NUMEROS NATURAIS ABAIXO DE 1000, MULTIPLOS DE 3 OU 5 =====\n");
    int soma=0, i=0;
    for(i=0;i<1000;i++){
        if(i % 3==0 && i % 5==0){
            soma = soma + i;
        }
    }
    printf("RESULTADO: %d",soma);

    return 0;
}