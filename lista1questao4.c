/*Professor, li que não para usar vetores assim que fui colocar os códigos no github,eu os usei
apenas para deixar o código mais eficiente e enxuto. Está compilando perfeitamente. Mil perdões. 
Prestarei mais atenção da próxima vez.
QUESTÃO = 4.Leia 2 valores com uma casa decimal (x e y), que devem representar as coordenadas
de um ponto em um plano. A seguir, determine qual o quadrante ao qual pertence o ponto, ou
se está sobre um dos eixos cartesianos ou na origem (x = y = 0). Se o ponto estiver na origem,
escreva a mensagem “Origem”. Se o ponto estiver sobre um dos eixos escreva “Eixo X” ou
“Eixo Y”, conforme for a situação.*/
#include <stdio.h>
#include <stdlib.h>
int main(){
        float P[2];
        printf("Escreva as coordenadas do ponto com uma casa decimal =>");
        printf("\nx1:");
        scanf("%f",&P[0]); 
        printf("y1:");
        scanf("%f",&P[1]); 
        printf("======RESULTADO======\n");

        if(P[0]>0 && P[1]>0){
                printf("Este ponto esta no primeiro quadrante!");
                }

        if(P[0]< 0 || P[1]<0){
                if(P[0]<0 && P[1]>0){
                printf("Este ponto esta no segundo quadrante!");
                }
                else if(P[0]>0 && P[1]<0){
                printf("Este ponto esta no quarto quadrante!"); 
                }else{
                printf("Este ponto esta no terceiro quadrante!");
                }
                }
        
        if(P[0]== 0 || P[1] == 0){
                if(P[0]== 0 && P[1]!=0){
                printf("Eixo Y");
                }else if(P[1]== 0 && P[0]!= 0){
                printf(" Eixo X");
                }else{
                printf("Origem");
                }
        }
return 0; 
}
