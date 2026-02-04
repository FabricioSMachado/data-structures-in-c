#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"

int main (void)
{
    int op = -1;
    int chaveAux, ok;
    pNodoA *abp1 = cria_arvore();
    pNodoA *abpaux = cria_arvore();

    while (op == -1)    //Loop "menu".
    {
        printf("Selecione uma opcao: \n");
        printf("1-Inserir elemento.\n");
        printf("2-Remover elemento.\n\n");
        printf("**Caminhamentos**.\n");
        printf("3-Pre fixado a esquerda.\n");
        printf("4-Central a esquerda.\n");
        printf("5-Pos fixado a esquerda.\n");
        printf("6-Pre fixado a direita.\n");
        printf("7-Central a direita.\n");
        printf("8-Pos fixado a direita.\n");
        printf("0-Sair.\n");
        scanf("%d", &op);
        system("clear");

        switch (op)
        {
        case 1:
            printf("Informe a chave do novo elemento: ");
            scanf("%d", &chaveAux);
            abp1 = InsereAVL(abp1, chaveAux, &ok);
            break;

        case 2:
            printf("Informe a chave do elemento a ser removido: ");
            scanf("%d", &chaveAux);
            abp1 = Remove(chaveAux, abp1);
            break;

        case 3:
            preFixadoEsq(abp1);
            break;

        case 4:
            centralEsq(abp1);
            break;

        case 5:
            posFixadoEsq(abp1);
            break;

        case 6:
            preFixadoDir(abp1);
            break;

        case 7:
            centralDir(abp1);
            break;

        case 8:
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
