#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lse.h"

int main (void)
{
    //Declaração de variáveis auxiliares.
    int op = -1;
    TipoPtNo* ptLista = inicializa();   //Inicializa a lista.
    char titulo[100];
    TipoInfoNo novo;

    while (op == -1)    //Loop "menu".
    {
        printf("Selecione uma opcao: \n");
        printf("1-Imprime lista.\n");
        printf("2-Consulta lista.\n");
        printf("3-Insere elemento no inicio.\n");
        printf("4-Insere elemento no final.\n");
        printf("5-Remover elemento.\n");
        printf("6-Destruir lista.\n");
        printf("7-Sair.\n");
        scanf("%d", &op);
        system("clear");

        switch (op)
        {
            case 1:
                imprime(ptLista);   //Chama função 'imprime', passando o ponteiro para o primeiro elemento da lista.
                break;

            case 2:
                printf("Informe o titulo: \n");
                scanf("%s", titulo);
                consulta(ptLista, titulo);  //Chama função 'consulta', passando ponteiro para primeiro elemento da lista e o título a ser consultado.
                break;

            case 3:
                printf("Novo titulo: \n");
                scanf("%s", novo.titulo);
                printf("Novo distribuidor: \n");
                scanf("%s", novo.distr);
                printf("Novo diretor: \n");
                scanf("%s", novo.diretor);
                ptLista = insereInicio(ptLista, novo);  //Lê dados do novo elemento e chama função 'insereInicio'.
                break;

            case 4:
                printf("Novo titulo: \n");
                scanf("%s", novo.titulo);
                printf("Novo distribuidor: \n");
                scanf("%s", novo.distr);
                printf("Novo diretor: \n");
                scanf("%s", novo.diretor);
                ptLista = insereFim(ptLista, novo); ////Lê dados do novo elemento e chama função 'insereFim'.
                break;

            case 5:
                printf("Informe o titulo do elemento a ser removido: ");
                scanf("%s", titulo);
                ptLista = remover(ptLista, titulo); //Lê o título do elemento a ser removido e chama a função 'remover'.
                break;

            case 6:
                ptLista = destroi(ptLista); //Chama função 'destroi'.
                break;

            case 7:
                return 0;   //Sair do "menu".
                break;

            default:
                break;
        }
        op = -1;
    }

    return 0;
}
