#include <stdio.h>
#include <string.h>

#define ESTUDANTE 15
#define DISCIPLINA 2
#define PROFESSOR 3

struct Professor
{
    char nome[90];
    int funcional;
    char titulacao[20];
};

struct Disciplina
{
    char nome[90];
    int codigo;
    int carga_horaria;
    Professor professor_responsavel;
};

struct Estudante
{
    char nome[90];
    int matricula;
    int idade;
};

void bubble_sort(Estudante *estudante, int n)
{
    int i, j;
    Estudante temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (estudante[j].idade > estudante[j + 1].idade)
            {
                temp = estudante[j];
                estudante[j] = estudante[j + 1];
                estudante[j + 1] = temp;
            }
        }
    }
}

int le_valida_idade()
{
    int idade;
    do
    {
        printf("Digite a idade do estudante (entre 16 e 26): ");
        scanf("%d", &idade);
    } while (idade < 16 || idade > 26);
    return idade;
}

int main()
{
    Professor professor[PROFESSOR];
    Disciplina disciplina[DISCIPLINA];
    Estudante estudante[ESTUDANTE];

    int i, j, n1 = 0, n2 = 0;

printf("========CADRASTRO DOS PROFESSORES========\n");
    for (i = 0; i < PROFESSOR; i++)
    {
        printf("Cadastro de Professor %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", professor[i].nome);
        fflush(stdin);
        printf("Funcional: ");
        scanf("%d", &professor[i].funcional);
        fflush(stdin);
        printf("Titulacao (especialista, mestre ou doutor): ");
        scanf("%s", professor[i].titulacao);
        fflush(stdin);

        printf("\n");
    }

printf("========CADRASTRO DAS DISCIPLINAS========\n");
    for (i = 0; i < DISCIPLINA; i++)
    {
        printf("Cadastro de Disciplina %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", disciplina[i].nome);
        fflush(stdin);
        printf("Codigo: ");
        scanf("%d", &disciplina[i].codigo);
        fflush(stdin);
        printf("Carga Horaria: ");
        scanf("%d", &disciplina[i].carga_horaria);
        fflush(stdin);

        //  Vai selecionar o professor responsavel
        printf("Selecione o professor responsavel:\n");
        for (j = 0; j < PROFESSOR; j++)
        {
            printf("%d - %s\n", j + 1, professor[j].nome);
        }
        int opcao;
        do
        {
        	printf("Escreva aqui: ");
            scanf("%d", &opcao);
        } while (opcao < 1 || opcao >PROFESSOR);
        disciplina[i].professor_responsavel = professor[opcao - 1];
        printf("\n");
    }

printf("========CADRASTRO DOS ESTUDANTES=======\n");
    for (i = 0; i < ESTUDANTE; i++)
    {
        printf("Cadastro de Estudante %d\n", i + 1);
        printf("Nome: ");
        scanf("%s", estudante[i].nome);
        fflush(stdin);
        printf("Matricula: ");
        scanf("%d", &estudante[i].matricula);
        fflush(stdin);
        estudante[i].idade = le_valida_idade();

        // Vai selecionar a disciplina
        printf("Selecione a disciplina:\n");
        for (j = 0; j < DISCIPLINA; j++)
        {
            printf("%d - %s\n", j + 1, disciplina[j].nome);
            fflush(stdin);
        }
        int opcao;
        do
        {
        	printf("Escreva aqui: ");
            scanf("%d", &opcao);
            fflush(stdin);
        } while (opcao < 1 || opcao > DISCIPLINA);

        // Vai verificar se a disciplina ja possui 10 estudantes
        if (opcao == 1 && n1 < 10)
        {
            n1++;
        }
        else if (opcao == 2 && n2 < 10)
        {
            n2++;
        }
        else
        {
            printf(" A disciplina nao pode ter mais de 10 estudantes matriculados!\n");
            i--;
            continue;
        }

        // Adiciona o estudante na disciplina selecionada
        disciplina[opcao - 1].professor_responsavel = professor[opcao - 1];
        printf("\n");
    }

    // Relatorio de alunos matriculados na primeira disciplina ordenados por idade
    printf("=====Relatorio de Alunos Matriculados na Primeira Disciplina Ordenados por Idade=====\n");
    printf("Codigo da Disciplina\tNome do Professor\tNome do Estudante\tIdade do Estudante\n");
    bubble_sort(estudante, n1);
    for (i = 0; i < n1; i++)
    {
        printf("%d\t%s\t%s\t%d\t\n", disciplina[0].codigo, disciplina[0].professor_responsavel.nome, estudante[i].nome, estudante[i].idade);
    }

    // Relatorio de alunos matriculados na segunda disciplina ordenados por idade em ordem decrescente
    printf("\n====Relatorio de Alunos Matriculados na Segunda Disciplina Ordenados por Idade em Ordem Decrescente====\n");
    printf("Codigo da Disciplina\tNome do Professor\tNome do Estudante\tIdade do Estudante\n");
    bubble_sort(estudante + n1, n2);
    for (i = n2 - 1; i >= 0; i--)
    {
        printf("%d\t%s\t%s\t%d\t\n", disciplina[1].codigo, disciplina[1].professor_responsavel.nome, estudante[n1 + i].nome, estudante[n1 + i].idade);
    }

    return 0;
}
