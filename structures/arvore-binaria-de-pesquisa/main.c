#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"

int main (void)
{
    int op = -1;
    int chaveAux;
    pNodoA *abp1 = cria_arvore();
    pNodoA *abpaux = cria_arvore();

    while (op == -1)    //Loop "menu".
    {
        printf("Selecione uma opcao: \n");
        printf("1-Inserir elemento.\n");
        printf("2-Remover elemento.\n");
        printf("3-Consultar.\n");
        printf("**Caminhamentos**.\n");
        printf("4-Pre fixado a esquerda.\n");
        printf("5-Central a esquerda.\n");
        printf("6-Pos fixado a esquerda.\n");
        printf("7-Pre fixado a direita.\n");
        printf("8-Central a direita.\n");
        printf("9-Pos fixado a direita.\n");
        printf("0-Sair.\n");
        scanf("%d", &op);
        system("clear");

        switch (op)
        {
            case 1:
                printf("Informe a chave do novo elemento: ");
                scanf("%d", &chaveAux);
                abp1 = InsereArvore(abp1, chaveAux);
                break;

            case 2:
                printf("Informe a chave do elemento a ser removido: ");
                scanf("%d", &chaveAux);
                abp1 = Remove(chaveAux, abp1);
                break;

            case 3:
                printf("Informe a chave do elemento a ser consultado: ");
                scanf("%d", &chaveAux);
                abpaux = consultaABP(abp1, chaveAux);
                if (abpaux != NULL)
                    printf("Chave %d encontrada\n", chaveAux);
                    else
                        printf("Chave nao encontrada\n");
                break;

            case 4:
                preFixadoEsq(abp1);
                break;

            case 5:
                centralEsq(abp1);
                break;

            case 6:
                posFixadoEsq(abp1);
                break;

            case 7:
                preFixadoDir(abp1);
                break;

            case 8:
                centralDir(abp1);
                break;

            case 9:
                posFixadoDir(abp1);
                break;

            case 0:
                return 0;
                break;

            default:
                break;
        }
        op = -1;
    }
    return 0;
}
