#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lde.h"

/*Cria uma lista vazia.*/
PtNo* inicializa(void)
{
    return NULL;    //Retorna um ponteiro para o próximo elemento da lista com o valor 'NULL'.
}

/*Imprime todos os elementos da lista.*/
void imprime(PtNo* PtLista)
{
    PtNo* PtAux=PtLista;
    if (PtLista == NULL)
        puts("Lista vazia.\n");
    else
        do
        {
            printf("Codigo = %d Nome = %s Preco = %.2f\n",
                   PtAux->info.codigo,
                   PtAux->info.nome,
                   PtAux->info.preco);
            PtAux = PtAux->prox;
        }
        while (PtAux != NULL);
}

void imprimeInvertida(PtNo *PtLista)
{
    PtNo *PtAux;
    if (PtLista==NULL)
    {
        printf("Lista vazia.\n\n");
    }
    else
    {
        PtAux=PtLista;
        while (PtAux->prox!=NULL)
            PtAux=PtAux->prox;
        while (PtAux!=NULL)
        {
            printf("Codigo = %d Nome = %s Preco = %.2f\n",
                   PtAux->info.codigo,
                   PtAux->info.nome,
                   PtAux->info.preco);
            PtAux= PtAux->ant;
        }
    }
}

/*Insere um novo elemento no início da lista.*/
PtNo* insereInicio(PtNo *PtLista, InfoNo Dado)
{
    PtNo *novo;
    novo = (PtNo*) malloc(sizeof(PtNo));
    novo->info = Dado;
    novo->ant = NULL;
    novo->prox = PtLista;
    if (PtLista != NULL)
        PtLista->ant = novo;
    PtLista = novo;
    return PtLista;
}

/*Insere um novo elemento no fim da lista.*/
PtNo* insereFim(PtNo *PtLista, InfoNo Dado)
{
    PtNo *novo, *PtAux;
    novo = (PtNo*) malloc(sizeof(PtNo)); //aloca novo nodo
    novo->info = Dado; //coloca dados no novo nodo
    novo->prox = NULL;
    if ((PtLista) == NULL)  //lista vazia
    {
        PtLista = novo;
        novo->ant = NULL;
    }
    else   // lista tem pelo menos um nodo
    {
        PtAux = PtLista; //auxiliar no início da lista
        while (PtAux->prox != NULL) // avança até o último elemento da lista
            PtAux=PtAux->prox;
        PtAux->prox = novo;
        novo->ant = PtAux; //Encadeia novo após PtAux
    }
    novo->prox = NULL;
    return PtLista;
}

PtNo* insereOrdem(PtNo *ptLista, InfoNo Dado)
{
    PtNo *novo;
    PtNo *ptaux = ptLista;
    novo = (PtNo*) malloc(sizeof(PtNo));
    novo->info = Dado;

    if(ptLista == NULL)
    {
        novo->ant = NULL;
        novo->prox = NULL;
        ptLista = novo;
        return ptLista;
    }

    if (Dado.codigo < ptLista->info.codigo)
    {
        ptLista = insereInicio(ptLista, Dado);
        return ptLista;
    }

    while (ptaux->prox != NULL && ptaux->info.codigo < Dado.codigo)
    {
        ptaux = ptaux->prox;
    }

    if (ptaux->info.codigo < Dado.codigo)
    {
        ptLista = insereFim(ptLista, Dado);
        return ptLista;
    } else
    {
        novo->ant = ptaux->ant;
        novo->prox = ptaux;
        ptaux->ant = novo;
        novo->ant->prox = novo;
    }
    return ptLista;
}

/*Remove um elemento, selecionando pelo código.*/
PtNo* remover(PtNo* PtLista, int cod) //Passa ponteiro para início da lista e string com título à ser deletado.
{
    PtNo *PtAux = PtLista;

    if (PtLista == NULL)
    {
        printf("Produto nao encontrado.");
        return PtLista;
    }

    while ((PtAux != NULL) && (PtAux->info.codigo != cod))
    {
        PtAux = PtAux->prox;
    }

    if (PtAux->ant == NULL)
    {
        PtLista = PtAux->prox;
        free(PtAux);
        return PtLista;
    }else{
        PtAux->ant->prox = PtAux->prox;
        PtAux->prox->ant = PtAux->ant;
        free(PtAux);
        return PtLista;
        }
}

/*Libera o espaço da lista.*/
PtNo* destroi(PtNo* ptLista)
{
    PtNo *PtAux; //ponteiro auxiliar para percorrer a lista
    while (ptLista != NULL)
    {
        PtAux = ptLista;
        ptLista = ptLista->prox;
        free(PtAux);
    }
    free(ptLista);
    return NULL;
}

