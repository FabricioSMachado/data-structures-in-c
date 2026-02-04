#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lde.h"

int main (void)
{
    //Declaração de variáveis auxiliares.
    int op = -1;
    PtNo* ptLista = inicializa();   //Inicializa a lista.
    int cod = -1;
    InfoNo novo;

    while (op == -1)    //Loop "menu".
    {
        printf("Selecione uma opcao: \n");
        printf("1-Imprime lista.\n");
        printf("2-Imprime lista invertida.\n");
        printf("3-Insere elemento no inicio.\n");
        printf("4-Insere elemento no final.\n");
        printf("5-Insere elemento em ordem crescente.\n");
        printf("6-Remover elemento.\n");
        printf("7-Destruir lista.\n");
        printf("8-Sair.\n");
        scanf("%d", &op);
        system("clear");

        switch (op)
        {
            case 1:
                imprime(ptLista);   //Chama função 'imprime', passando o ponteiro para o primeiro elemento da lista.
                break;

            case 2:
                imprimeInvertida(ptLista);
                break;

            case 3:
                printf("Novo codigo: \n");
                scanf("%d", &novo.codigo);
                printf("Novo produto: \n");
                scanf("%s", novo.nome);
                printf("Novo preco: \n");
                scanf("%f", &novo.preco);
                ptLista = insereInicio(ptLista, novo);  //Lê dados do novo elemento e chama função 'insereInicio'.
                break;

            case 4:
                printf("Novo codigo: \n");
                scanf("%d", &novo.codigo);
                printf("Novo produto: \n");
                scanf("%s", novo.nome);
                printf("Novo preco: \n");
                scanf("%f", &novo.preco);
                ptLista = insereFim(ptLista, novo); ////Lê dados do novo elemento e chama função 'insereFim'.
                break;

            case 5:
                printf("Novo codigo: \n");
                scanf("%d", &novo.codigo);
                printf("Novo produto: \n");
                scanf("%s", novo.nome);
                printf("Novo preco: \n");
                scanf("%f", &novo.preco);
                ptLista = insereOrdem(ptLista, novo); ////Lê dados do novo elemento e chama função 'insereOrdem'.
                break;

            case 6:
                printf("Informe o codigo do produto a ser removido: ");
                scanf("%d", &cod);
                ptLista = remover(ptLista, cod);
                break;

            case 7:
                ptLista = destroi(ptLista); //Chama função 'destroi'.
                break;

            case 8:
                return 0;   //Sair do "menu".
                break;

            default:
                break;
        }
        op = -1;
    }

    return 0;
}

