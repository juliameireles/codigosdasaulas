#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define MAX_DESCRICAO 100
#define MAX_MARCA 50
#define MAX_SITE 100
#define MAX_TELEFONE 20

typedef struct
{
    char marca[MAX_MARCA];
    char site[MAX_SITE];
    char telefone[MAX_TELEFONE];
    char uf[3];
} Fabricante;

typedef struct
{
    char descricao[MAX_DESCRICAO];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    Fabricante fabricante;
} Produto;

void le_valida_peso(float *peso);
void le_valida_valor(float *valor, const char *nomeValor);
void le_valida_uf(char *uf);
void cadastrar_fabricantes(Fabricante *fabricantes, int numFabricantes);
void cadastrar_produtos(Produto *produtos, int numProdutos, const Fabricante *fabricantes, int numFabricantes);
int comparar_produtos(const void *a, const void *b);
int comparar_marcas(const void *a, const void *b);
void listar_todas_marcas(const Fabricante *fabricantes, int numFabricantes);
void listar_todos_produtos(const Produto *produtos, int numProdutos);
void listar_produtos_por_estado(const Produto *produtos, int numProdutos);
void listar_produtos_por_marca(const Produto *produtos, int numProdutos);
void encontrar_estado_produto_mais_caro(const Produto *produtos, int numProdutos);
void encontrar_fabricante_produto_mais_barato(const Produto *produtos, int numProdutos);
void listar_produtos_ordem_valor_venda(const Produto *produtos, int numProdutos);
void listar_produtos_ordem_valor_lucro(const Produto *produtos, int numProdutos);
void listar_produtos_ordem_percentual_lucro(const Produto *produtos, int numProdutos);

int main()
{
    Fabricante fabricantes[MAX_FABRICANTES];
    Produto produtos[MAX_PRODUTOS];
    int numFabricantes, numProdutos;
    char opcao;
 do {
        printf("Numero de fabricantes (minimo 2, maximo 5): ");
        scanf("%d", &numFabricantes);

        if (numFabricantes < 2 || numFabricantes > MAX_FABRICANTES) {
            printf("Valor invalido. Tente novamente.\n");
        }
    } while (numFabricantes < 2 || numFabricantes > MAX_FABRICANTES);

    cadastrar_fabricantes(fabricantes, numFabricantes);
   do {
        printf("Numero de produtos (minimo 5, maximo 50): ");
        scanf("%d", &numProdutos);

        if (numProdutos < 5 || numProdutos > MAX_PRODUTOS) {
            printf("Valor invalido. Tente novamente.\n");
        }
    } while (numProdutos < 5 || numProdutos > MAX_PRODUTOS);

    cadastrar_produtos(produtos, numProdutos, fabricantes, numFabricantes);


    while (1)
    {
        printf("\nOpcoes:\n");
        printf("[A] Listar todos os produtos ordem alfabetica (crescente)\n");
        printf("[Z] Listar todas as marcas em ordem alfabetica (decrescente)\n");
        printf("[1] Listar todas as marcas\n");
        printf("[2] Listar todos os produtos\n");
        printf("[3] Listar produtos por estado\n");
        printf("[4] Listar produtos por marca\n");
        printf("[5] Encontrar estado onde esta registrado o produto mais caro\n");
        printf("[6] Encontrar fabricante onde esta registrado o produto mais barato\n");
        printf("[7] Listar produtos em ordem crescente de valor de venda\n");
        printf("[8] Listar produtos em ordem crescente de valor de lucro\n");
        printf("[9] Listar produtos em ordem crescente de percentual de lucro\n");
        printf("[0] Sair\n");
        printf("Escolha uma opcao: ");
        scanf(" %c", &opcao);
        printf("\n");

        switch (opcao)
        {
        case 'A':
        	listar_todos_produtos (produtos, numProdutos);
        	break;
        case 'Z':
        	listar_todas_marcas(fabricantes, numFabricantes);
            break;
        case '1':
            listar_todas_marcas(fabricantes, numFabricantes);
            break;
        case '2':
            listar_todos_produtos(produtos, numProdutos);
            break;
        case '3':
            listar_produtos_por_estado(produtos, numProdutos);
            break;
        case '4':
            listar_produtos_por_marca(produtos, numProdutos);
            break;
        case '5':
            encontrar_estado_produto_mais_caro(produtos, numProdutos);
            break;
        case '6':
            encontrar_fabricante_produto_mais_barato(produtos, numProdutos);
            break;
        case '7':
            listar_produtos_ordem_valor_venda(produtos, numProdutos);
            break;
        case '8':
            listar_produtos_ordem_valor_lucro(produtos, numProdutos);
            break;
        case '9':
            listar_produtos_ordem_percentual_lucro(produtos, numProdutos);
            break;
        case '0':
            exit(0);
        default:
            printf("Opçao invalida. Tente novamente.\n");
        }
    }

    return 0;
}

void le_valida_peso(float *peso)
{
    do
    {
        printf("Peso (minimo 50g, maximo 50.000g): ");
        scanf("%f", peso);
        if (*peso < 0.05 || *peso > 50000.0)
        {
            printf("Valor invalido. ");
        }
    } while (*peso < 0.05 || *peso > 50000.0);
}

void le_valida_valor_compra(float *valor, const char *nomeValor)
{
    do
    {
        printf("%s (minimo R$ 0.50, maximo R$ 8,000.00): ", nomeValor);
        scanf("%f", valor);
        if (*valor < 0.5 || *valor > 8000.0)
        {
            printf("Valor invalido. ");
        }
        
    } while (*valor < 0.5 || *valor > 8000.0);
}
void le_valida_valor_venda(float *valorvenda, const char *nomeValor)
{
    do
    {
        printf("%s (minimo R$ 1, maximo R$ 10,000.00): ", nomeValor);
        scanf("%f", valorvenda);
        if (*valorvenda < 1.0 || *valorvenda > 10000.0)
        {
            printf("Valor invalido. ");
        }
        
    } while (*valorvenda < 1.0 || *valorvenda > 10000.0);
}

void le_valida_uf(char *uf)
{
    char ufsValidas[] = "DFACALAMAPAMGBGOMAMGPAPEPBPERJRJRSSCTOSESP";
    char input[3];
    int valido = 0;

    do
    {
        printf("UF (2 letras maiusculas): ");
        scanf("%s", input);
        *uf = toupper(input[0]);
        *(uf + 1) = toupper(input[1]);
        if (strlen(input) != 2 || strchr(ufsValidas, *uf) == NULL)
        {
            printf("UF invalida. ");
        }
        else
        {
            valido = 1;
        }
    } while (!valido);
}

void cadastrar_fabricantes(Fabricante *fabricantes, int numFabricantes)
{
    int i;
    for (i = 0; i < numFabricantes; i++)
    {
        printf("\nFabricante %d:\n", i + 1);
        printf("Marca: ");
        scanf(" %[^\n]s", fabricantes[i].marca);
        printf("Site: ");
        scanf(" %[^\n]s", fabricantes[i].site);
        printf("Telefone: ");
        scanf(" %[^\n]s", fabricantes[i].telefone);
        le_valida_uf(fabricantes[i].uf);
    }
}

void cadastrar_produtos(Produto *produtos, int numProdutos, const Fabricante *fabricantes, int numFabricantes)
{
    int i, j, indiceFabricante;
    for (i = 0; i < numProdutos; i++)
    {
        printf("\nProduto %d:\n", i + 1);
        printf("Descricao: ");
        scanf(" %[^\n]s", produtos[i].descricao);
        le_valida_peso(&(produtos[i].peso));
        le_valida_valor_compra(&(produtos[i].valorCompra), "Valor de compra");
        le_valida_valor_venda(&(produtos[i].valorVenda), "Valor de venda");
        produtos[i].valorLucro = produtos[i].valorVenda - produtos[i].valorCompra;
        produtos[i].percentualLucro = (produtos[i].valorLucro / produtos[i].valorCompra) * 100.0;

        printf("Fabricante:\n");
        for (j = 0; j < numFabricantes; j++)
        {
            printf("%d. %s\n", j + 1, fabricantes[j].marca);
        }
        printf("Escolha o fabricante (1-%d): ", numFabricantes);
        scanf("%d", &indiceFabricante);
        indiceFabricante = indiceFabricante < 1 ? 1 : (indiceFabricante > numFabricantes ? numFabricantes : indiceFabricante);
        produtos[i].fabricante = fabricantes[indiceFabricante - 1];
    }
}

int comparar_produtos(const void *a, const void *b)
{
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;
    return strcmp(produtoA->descricao, produtoB->descricao);
}

int comparar_marcas(const void *a, const void *b)
{
    Fabricante *fabricanteA = (Fabricante *)a;
    Fabricante *fabricanteB = (Fabricante *)b;
    return strcmp(fabricanteB->marca, fabricanteA->marca);
}

void listar_todas_marcas(const Fabricante *fabricantes, int numFabricantes)
{
    Fabricante *fabricantesOrdenados = (Fabricante *)malloc(numFabricantes * sizeof(Fabricante));
    memcpy(fabricantesOrdenados, fabricantes, numFabricantes * sizeof(Fabricante));
    qsort(fabricantesOrdenados, numFabricantes, sizeof(Fabricante), comparar_marcas);

    printf("\nLista de todas as marcas :\n");
    for (int i = 0; i < numFabricantes; i++)
    {
        printf("Marca: %s\n", fabricantesOrdenados[i].marca);
    }

    free(fabricantesOrdenados);
}

void listar_todos_produtos(const Produto *produtos, int numProdutos)
{
    Produto *produtosOrdenados = (Produto *)malloc(numProdutos * sizeof(Produto));
    memcpy(produtosOrdenados, produtos, numProdutos * sizeof(Produto));
    qsort(produtosOrdenados, numProdutos, sizeof(Produto), comparar_produtos);

    printf("\nLista de todos os produtos :\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto: %s\n", produtosOrdenados[i].descricao);
    }

    free(produtosOrdenados);
}

void listar_produtos_por_estado(const Produto* produtos, int numProdutos) {
    char uf[3];
    printf("UF: ");
    scanf(" %[^\n]s", uf);

    printf("\nProdutos registrados no estado %s:\n", uf);
    int encontrados = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante.uf, uf) == 0) {
            printf("Produto: %s\n", produtos[i].descricao);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum produto registrado no estado %s.\n", uf);
    }
}

void listar_produtos_por_marca(const Produto* produtos, int numProdutos) {
    char marca[MAX_MARCA];
    printf("Marca: ");
    scanf(" %[^\n]s", marca);

    printf("\nProdutos da marca %s:\n", marca);
    int encontrados = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (strcasecmp(produtos[i].fabricante.marca, marca) == 0) {
            printf("Produto: %s\n", produtos[i].descricao);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum produto da marca %s encontrado.\n", marca);
    }
}

void encontrar_estado_produto_mais_caro(const Produto *produtos, int numProdutos)
{
    float maiorValor = 0.0;
    char estadoMaisCaro[3];

    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda > maiorValor)
        {
            maiorValor = produtos[i].valorVenda;
            strcpy(estadoMaisCaro, produtos[i].fabricante.uf);
        }
    }

    printf("Estado onde esta registrado o produto mais caro: %s\n", estadoMaisCaro);
}

void encontrar_fabricante_produto_mais_barato(const Produto *produtos, int numProdutos)
{
    float menorValor = produtos[0].valorVenda;
    const Fabricante *fabricanteMaisBarato = &(produtos[0].fabricante);

    for (int i = 1; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda < menorValor)
        {
            menorValor = produtos[i].valorVenda;
            fabricanteMaisBarato = &(produtos[i].fabricante);
        }
    }

    printf("Fabricante onde esta registrado o produto mais barato:\n");
    printf("Marca: %s\n", fabricanteMaisBarato->marca);
    printf("Site: %s\n", fabricanteMaisBarato->site);
    printf("Telefone: %s\n", fabricanteMaisBarato->telefone);
    printf("UF: %s\n", fabricanteMaisBarato->uf);
}

void listar_produtos_ordem_valor_venda(const Produto *produtos, int numProdutos)
{
    Produto *produtosOrdenados = (Produto *)malloc(numProdutos * sizeof(Produto));
    memcpy(produtosOrdenados, produtos, numProdutos * sizeof(Produto));
    qsort(produtosOrdenados, numProdutos, sizeof(Produto), comparar_produtos);

    printf("\nLista de produtos em ordem crescente de valor de venda:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto: %s - Valor de venda: R$ %.2f\n", produtosOrdenados[i].descricao, produtosOrdenados[i].valorVenda);
    }

    free(produtosOrdenados);
}

void listar_produtos_ordem_valor_lucro(const Produto *produtos, int numProdutos)
{
    Produto *produtosOrdenados = (Produto *)malloc(numProdutos * sizeof(Produto));
    memcpy(produtosOrdenados, produtos, numProdutos * sizeof(Produto));
    qsort(produtosOrdenados, numProdutos, sizeof(Produto), comparar_produtos);

    printf("\nLista de produtos em ordem crescente de valor de lucro:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto: %s - Valor de lucro: R$ %.2f\n", produtosOrdenados[i].descricao, produtosOrdenados[i].valorLucro);
    }

    free(produtosOrdenados);
}

void listar_produtos_ordem_percentual_lucro(const Produto *produtos, int numProdutos)
{
    Produto *produtosOrdenados = (Produto *)malloc(numProdutos * sizeof(Produto));
    memcpy(produtosOrdenados, produtos, numProdutos * sizeof(Produto));
    qsort(produtosOrdenados, numProdutos, sizeof(Produto), comparar_produtos);

    printf("\nLista de produtos em ordem crescente de percentual de lucro:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto: %s - Percentual de lucro: %.2f%%\n", produtosOrdenados[i].descricao, produtosOrdenados[i].percentualLucro);
    }

    free(produtosOrdenados);
}
