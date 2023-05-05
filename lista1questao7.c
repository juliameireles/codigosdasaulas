/* QUESTÃO = 7.Escreva um programa que leia um número inteiro, maior ou igual a zero, do usuário.
Imprima o enésimo termo da sequência de Fibonacci. Essa sequência começa no termo de
ordem zero, e, a partir do segundo termo, seu valor é dado pela soma dos dois termos
anteriores. Alguns termos dessa sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34.*/
#include <stdio.h>
#include <stdlib.h>
int main(void){
    int n,seq = 1, seqa = 0, seqaux; 
    printf("Quantos termos da sequencia de Fibonacci voce quer ver? ");
    scanf("%d", &n);
    printf("\n0 ");
    n--;

    while(n)
    {
        printf("%d ", seq);
        seqaux = seq;
        seq += seqa;
        seqa = seqaux;
        n--;
    }

    printf("\n\n");

    return 0;
}