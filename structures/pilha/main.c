#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main (void)
{
    int op = -1;
    TipoPilha *p1 = InicializaPilha();
    TipoInfo dado;

    while (op == -1)    //Loop "menu".
    {
        printf("Selecione uma opcao: \n");
        printf("1-Imprime a pilha.\n");
        printf("2-Push.\n");
        printf("3-Pop.\n");
        printf("4-Consultar pilha.\n");
        printf("5-Destruir pilha.\n");
        printf("6-Sair.\n");
        scanf("%d", &op);
        system("clear");

        switch (op)
        {
            case 1:
                ImprimePilha(p1);
                break;

            case 2:
                printf("Novo dado: ");
                scanf("%d", &dado);
                p1 = PushPilha(p1, dado);
                ImprimePilha(p1);
                break;

            case 3:
                PopPilha(&p1, &dado);
                printf("Pop: %d\n", dado);
                ImprimePilha(p1);
                break;

            case 4:
                dado = ConsultaPilha(p1);
                if (dado == -1)
                {
                    printf("Pilha vazia.\n");
                }
                else
                {
                    printf("Topo = %d\n", dado);
                }
                break;

            case 5:
                p1 = DestroiPilha(p1);
                break;

            case 6:
                return 0;
                break;

            default:
                break;
        }
        op = -1;
    }
    return 0;
}
