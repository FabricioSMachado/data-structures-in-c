#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abp.h"


pNodoA* cria_arvore(void)   //Retorna NULL para criar uma ABP vazia.
{
    return NULL;
}

pNodoA* InsereArvore(pNodoA *a, int ch) //Insere novos nodos na ABP de forma ordenada.
{
    if (a == NULL)  //Se a ABP estiver vazia, elemento inserido será a raiz.
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = ch;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if (ch < a->info)  //Se houver elementos, compara a info com o elemento atual, e chama novamente a função, inserindo no local apropriado.
        a->esq = InsereArvore(a->esq,ch);
    else
        a->dir = InsereArvore(a->dir,ch);
    return a;
}

pNodoA* Maior( pNodoA* r )  //Retorna o maior nodo a partir do nodo passado para a função.
{
    if( r != NULL ) //Passa para o nodo a direita enquanto houver nodos à direita.
        while( r->dir != NULL )
            r = r->dir;

    return r;
}

pNodoA* Remove(int X, pNodoA* T)  //Remove um nodo da ABP, reorganizando-a adequadamente.
{
    pNodoA* TmpCell;

    if( T == NULL ) //Se ABP estiver vazia, informa e retorna T.
        printf( "Elemento nao encontrado.\n" );
    else if( X < T->info ) /* vai para a subarvore esquerda */
        T->esq = Remove( X, T->esq );
    else if( X > T->info ) /* vai para a subarvore direita */
        T->dir = Remove( X, T->dir );
    else  /* achou o elemento a ser removido */
        if( T->esq && T->dir )  /* o elemento tem as 2 subarvores */
        {
            /* substitui pelo maior valor da sub�rvore esquerda */
            TmpCell = Maior( T->esq );
            T->info = TmpCell->info;
            T->esq = Remove( T->info, T->esq );
        }
        else  /* uma ou nenhuma sub-�rvore */
        {
            TmpCell = T;
            if( T->esq == NULL ) /* substitui pelo filho dir -- se n�o tiver filhos, substitui por NULL*/
                T = T->dir;
            else if( T->dir == NULL )
                T = T->esq; /*substitui pelo filho esq*/
            free( TmpCell );
        }

    return T;
}

pNodoA* consultaABP(pNodoA *a, int chave)   //Recebe uma ABP e uma chave e consulta se chave existe na ABP.
{
    if (a==NULL)
        return NULL;
    else if (a->info == chave)
        return a;
    else if (a->info > chave)
        return consultaABP(a->esq,chave);
    else
        return consultaABP(a->dir,chave);
}

//Os 6 caminhamentos, pré-fixado, central e pós-fixado, tanto à direita quanto à esquerda.
void preFixadoEsq(pNodoA *a)
{
    if (a!= NULL)
    {
        printf("%d\n",a->info);
        preFixadoEsq(a->esq);
        preFixadoEsq(a->dir);
    }
}

void centralEsq(pNodoA *a)
{
    if (a!= NULL)
    {
        centralEsq(a->esq);
        printf("%d\n",a->info);
        centralEsq(a->dir);
    }
}

void posFixadoEsq(pNodoA *a)
{
    if (a!= NULL)
    {
        posFixadoEsq(a->esq);
        posFixadoEsq(a->dir);
        printf("%d\n",a->info);
    }
}


void preFixadoDir(pNodoA *a)
{
    if (a!= NULL)
    {
        printf("%d\n",a->info);
        preFixadoDir(a->dir);
        preFixadoDir(a->esq);
    }
}

void centralDir(pNodoA *a)
{
    if (a!= NULL)
    {
        centralDir(a->dir);
        printf("%d\n",a->info);
        centralDir(a->esq);
    }
}

void posFixadoDir(pNodoA *a)
{
    if (a!= NULL)
    {
        posFixadoDir(a->dir);
        posFixadoDir(a->esq);
        printf("%d\n",a->info);
    }
}
