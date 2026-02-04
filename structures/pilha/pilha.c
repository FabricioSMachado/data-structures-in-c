#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

TipoPilha* InicializaPilha(void) //Cria pilha vazia.
{
    return NULL;
}


int VaziaPilha(TipoPilha *Topo)
    {
        if (Topo == NULL)
            return 1;
        else
            return 0;
    }


int PopPilha (TipoPilha **Topo, TipoInfo *Dado) //Retorna 1 se pilha ficou vazia, 0 se n�o.
{
    TipoPilha* ptaux;
    if (VaziaPilha(*Topo))  //Teste para pilha vazia.
        return 0;
    else
    {
        *Dado = (*Topo)->dado; // devolve o valor do topo
        ptaux = *Topo; //guarda o endere�o do topo
        *Topo = (*Topo)->elo; //o pr�ximo passa a ser o topo
        free(ptaux); //libera o que estava no topo
        ptaux=NULL;
        return 1;
    }

}


    TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado)   //Insere novo elemento no topo da pilha.
    {
        TipoPilha *novo;    //Declara��o do novo elemento.
        novo = (TipoPilha*) malloc(sizeof(TipoPilha));  //Aloca��o do espa�o para novo elemento.
        novo->dado = Dado;  //Dados do 'novo' recebe 'dado'.
        novo->elo = Topo;   //Atualiza o topo.

        return novo;    //Retorna o novo topo.
    }


    TipoInfo ConsultaPilha (TipoPilha *Topo)    //Consulta o elemento do topo.
    {
        if (! VaziaPilha(Topo)) //Teste para pilha vazia, retornando o elemento do topo se houver.
            return Topo->dado;
        else
            return -1;    //Retornando 'NULL' se pilha estiver vazia.
    }


    TipoPilha* DestroiPilha (TipoPilha *Topo)   //Destr�i a pilha.
    {
        TipoPilha *ptaux;
        while (Topo != NULL)    //Loop enquanto topo n�o for 'NULL'.
        {
            ptaux = Topo;   //Guarda o endere�o do topo.
            Topo = Topo->elo;   //Pr�ximo elemento passa a ser o topo.
            free(ptaux);    //Libera o espa�o que era o topo.
        }
        return NULL;    //Retorna 'NULL' para pilha vazia.
    }


    void ImprimePilha (TipoPilha *Topo)
    {
        TipoPilha* ptaux = Topo;

        if (Topo == NULL)
        {
            printf("Pilha vazia.\n");
            return;
        }

        while (ptaux != NULL)
        {
            printf("%d\n", ptaux->dado);
            ptaux = ptaux->elo;
        }
        return;
    }
