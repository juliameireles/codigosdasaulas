/*Professor, li que não para usar vetores assim que fui colocar os códigos no github,eu os usei
apenas para deixar o código mais eficiente e enxuto. Está compilando perfeitamente. Mil perdões. 
Prestarei mais atenção da próxima vez.
QUESTÃO: 2.Leia os quatro valores correspondentes aos eixos x e y de dois pontos quaisquer no
plano, p1(x1, y1) e p2(x2, y2) e calcule a distância entre eles, mostrando 4 casas decimais
após a vírgula, segundo a fórmula:*/
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
