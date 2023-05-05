/* QUESTÃO = 10.Faça um programa que leia 10 inteiros e imprima sua média.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int valor1,valor2,valor3,valor4,valor5,valor6,valor7,valor8,valor9,valor10,soma;
    float media;
    printf("Digite o %do valor inteiro: ", 1);
    scanf("%d", &valor1);
    printf("Digite o %do valor inteiro: ", 2);
    scanf("%d", &valor2);
    printf("Digite o %do valor inteiro: ", 3);
    scanf("%d", &valor3);
    printf("Digite o %do valor inteiro: ", 4);
    scanf("%d", &valor4);
    printf("Digite o %do valor inteiro: ", 5);
    scanf("%d", &valor5);
    printf("Digite o %do valor inteiro: ", 6);
    scanf("%d", &valor6);
    printf("Digite o %do valor inteiro: ", 7);
    scanf("%d", &valor7);
    printf("Digite o %do valor inteiro: ", 8);
    scanf("%d", &valor8);
    printf("Digite o %do valor inteiro: ", 9);
    scanf("%d", &valor9);
    printf("Digite o %do valor inteiro: ", 10);
    scanf("%d", &valor10);
    soma = valor1 + valor2 + valor3 + valor4 + valor5 + valor6 + valor7 + valor8 + valor9 + valor10;

    printf("======MEDIA DOS NUMEROS INSERIDOS=====\n");
        media = soma/10.0;
        printf("O resultado eh = %.2f",media);

    return 0;
    }