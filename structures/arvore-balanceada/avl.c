#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"


pNodoA* cria_arvore(void)   //Retorna NULL para criar uma ABP vazia.
{
    return NULL;
}

pNodoA* rotacao_esquerda(pNodoA *p)
{
    pNodoA *z;
    z = p->dir;
    p->dir = z->esq;
    z->esq = p;
    p->FB = 0;
    p = z;
    return p;
}

pNodoA* rotacao_direita(pNodoA* p)
{
    pNodoA *u;
    u = p->esq;
    p->esq = u->dir;
    u->dir = p;
    p->FB = 0;
    p = u;
    return p;
}

pNodoA* rotacao_dupla_esquerda (pNodoA *p)
{
    pNodoA *z, *y;
    z = p->dir;
    y = z->esq;
    z->esq = y->dir;
    y->dir = z;
    p->dir = y->esq;
    y->esq = p;
    if (y->FB == -1) p->FB = 1;
    else p->FB = 0;
    if (y->FB == 1) z->FB = -1;
    else z->FB = 0;
    p = y;
    return p;
}

pNodoA* rotacao_dupla_direita (pNodoA* p)
{
    pNodoA *u, *v;
    u = p->esq;
    v = u->dir;
    u->dir = v->esq;
    v->esq = u;
    p->esq = v->dir;
    v->dir = p;
    if (v->FB == 1) p->FB = -1;
    else p->FB = 0;
    if (v->FB == -1) u->FB = 1;
    else u->FB = 0;
    p = v;
    return p;
}


pNodoA* InsereAVL (pNodoA *a, TipoInfo x, int *ok)
{
    /* Insere nodo em uma árvore AVL, onde A representa a raiz da árvore,
     x, a chave a ser inserida e h a altura da árvore */
    if (a == NULL)
    {
        a = (pNodoA*) malloc(sizeof(pNodoA));
        a->info = x;
        a->esq = NULL;
        a->dir = NULL;
        a->FB = 0;
        *ok = 1;
    }
    else if (x < a->info)
    {
        a->esq = InsereAVL(a->esq,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case -1:
                a->FB = 0;
                *ok = 0;
                break;
            case 0:
                a->FB = 1;
                break;
            case 1:
                a=Caso1(a,ok);
                break;
            }
        }
    }
    else
    {
        a->dir = InsereAVL(a->dir,x,ok);
        if (*ok)
        {
            switch (a->FB)
            {
            case 1:
                a->FB = 0;
                *ok = 0;
                break;
            case 0:
                a->FB = -1;
                break;
            case -1:
                a = Caso2(a,ok);
                break;
            }
        }
    }
    return a;
}

pNodoA* Caso1 (pNodoA *a, int *ok)
{
    pNodoA *z;
    z = a->esq;
    if (z->FB == 1)
        a = rotacao_direita(a);

    else
        a = rotacao_dupla_direita(a);

    a->FB = 0;
    *ok = 0;
    return a;
}

pNodoA* Caso2 (pNodoA *a, int *ok)
{
    pNodoA *z;
    z = a->dir;
    if (z->FB == -1)
        a = rotacao_esquerda(a);

    else
        a = rotacao_dupla_esquerda(a);

    a->FB = 0;
    *ok = 0;
    return a;
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

pNodoA* Maior( pNodoA* r )  //Retorna o maior nodo a partir do nodo passado para a função.
{
    if( r != NULL ) //Passa para o nodo a direita enquanto houver nodos à direita.
        while( r->dir != NULL )
            r = r->dir;

    return r;
}


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
