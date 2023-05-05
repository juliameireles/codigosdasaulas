/* QUESTÃO = 3.Faça um programa que calcule e mostre a área da superfície e o volume de uma esfera
sendo fornecido o valor de seu raio (R). A fórmula para calcular o volume é: (4/3) * pi * R³. A
fórmula para calcular a área é: 4 * pi * R². Considere (atribua) para pi o valor 3.14159. Use o
conceito de constante Dica: Ao utilizar a fórmula, procure usar (4/3.0) ou (4.0/3), pois algumas
linguagens (dentre elas o C++), assumem que o resultado da divisão entre dois inteiros é
outro inteiro*/
#include <stdio.h>
#include <math.h>
#define PI 3.14159
    int main(){
        double raio,Volume,Area;
        printf("Digite um valor para o raio da esfera: ");
        scanf("%lf",&raio);
        double Apotbase = raio, Apot= 3.0;
        double Aresult = pow(Apotbase,Apot);
        Volume = 4.0/3 * PI * Aresult;
        double Vpotbase = raio ,Vpot = 2.0;
        double Vresult = pow(Vpotbase,Vpot);
        Area = 4 * PI * Vresult;
        printf("=======RESULTADOS======\n");
        printf("Area da superficie: %.5lf\n",Area);
        printf("Volume da esfera %.5lf",Volume);
        printf("\n==========================");

    return 0;
    }
