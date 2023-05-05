#include <stdio.h>
#include <math.h>
    int main(){
    int x[2],y[2];
    double distancia;
    printf("Escreva as coordenadas do ponto 1 =>");
    printf(" x1:");
    scanf("%d",&x[0]); 
    printf("y1: \n");
    scanf("%d",&y[0]); 
    printf("Escreva as coordenadas do ponto 2 =>");
    printf(" x2: ");
    scanf("%d",&x[1]);
    printf("y2: \n");
    double xnum = x[1] - x[0], xpot = 2;
    double ynum = y[1] - y[0], ypot = 2;
    double resultx = pow(xnum,xpot);
    double resulty = pow(ynum,ypot);
    distancia = sqrt(resultx + resulty);
    printf("A distancia entre os pontos x e y eh: %.4lf",distancia);
    
        return 0;
    }