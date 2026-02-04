#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lse.h"

/*Cria uma lista vazia.*/
TipoPtNo* inicializa(void)
{
    return NULL;    //Retorna um ponteiro para o próximo elemento da lista com o valor 'NULL'.
}

/*Imprime todos os elementos da lista.*/
void imprime(TipoPtNo* ptLista) //Passa para a função o ponteiro para o primeiro elemento da lista.
{
    TipoPtNo* ptaux;    //Declara um ponteiro auxiliar.
    if (ptLista == NULL)    //Testa se a lista está vazia.
        puts("Lista vazia\n");
    else
        for (ptaux=ptLista; ptaux!=NULL; ptaux=ptaux->prox) //Se houver elementos na lista, loop utiliza o 'ptaux' para percorrer a lista e imprimir os dados de cada elemento.
            printf("Titulo = %s Distribuidor = %s Diretor = %s\n",
                   ptaux->info.titulo,
                   ptaux->info.distr,
                   ptaux->info.diretor);
}

/*Consulta um elemento da lista pelo título*/
void consulta(TipoPtNo* ptLista, char titulo[])
{
    TipoPtNo* ptaux = ptLista;  //Ponteiro auxiliar recebe ponteiro para primeiro elemento da lista.

    if (ptaux == NULL)  //Testa se lista está vazia.
        puts("Lista vazia\n");
    else
        while ((ptaux != NULL) && (strcmp(ptaux->info.titulo, titulo))) //Se houver elementos, loop itera até encontrar elemento correspondente ou chegar no final da lista.
        {
            ptaux = ptaux->prox;
        }
        if (ptaux == NULL)  //Testa se chegou no final da lista
            puts("Nao encontrado\n");
            else
            printf("Titulo = %s Distribuidor = %s Diretor = %s\n",  //Se encontrou, imprime as informações.
                   ptaux->info.titulo,
                   ptaux->info.distr,
                   ptaux->info.diretor);
}

/*Insere um novo elemento no início da lista.*/
TipoPtNo* insereInicio (TipoPtNo* ptLista, TipoInfoNo dados)  //Passa o ponteiro para o primeiro elemento da lista e os dados do novo elemento.
{
    TipoPtNo *novo; //Declara um novo ponteiro da lista.

    novo = (TipoPtNo*)malloc(sizeof(TipoPtNo)); //Aloca espaço para o novo elemento da lista.
    novo->info = dados; //Atributo 'info' do ponteiro recebe os dados do elemento.
    novo->prox = ptLista;   //Ponteiro para o próximo elemento da lista recebe o ponteiro para o primeiro elemento.
    ptLista = novo; //Ponteiro para o primeiro elemento recebe o ponteiro para o novo elemento.

    return ptLista; //Retorna o ponteiro para o primeiro elemento.
}

/*Insere um novo elemento no fim da lista.*/
TipoPtNo* insereFim (TipoPtNo* ptLista, TipoInfoNo dados)   //Passa o ponteiro para o primeiro elemento, e os dados.
{
    TipoPtNo *novo, *ptaux = ptLista;   //Declara um novo ponteiro para o novo elemento da lista, e um ponteiro auxiliar, que recebe o ponteiro para o começo da lista.

    novo = (TipoPtNo*)malloc(sizeof(TipoPtNo)); //Aloca espaço para o novo elemento.
    novo->info = dados; //Atributo 'info' do novo ponteiro recebe as informações do novo elemento.
    novo->prox = NULL;  //Ponteiro para o próximo elemento do novo elemento recebe 'NULL', já que será o último elemento da lista.

    if(ptaux)   //Testa se a lista não está vazia.
    {
        for(ptaux = ptLista; ptaux->prox; ptaux = ptaux->prox); //Loop para o ponteiro auxiliar percorrer toda lista, até o último elemento.
        ptaux->prox = novo; //Chega no último elemento, e o ponteiro para próximo elemento do último elemento recebe ponteiro para o novo elemento.
    }
    else
        ptLista = novo; //Se a lista estiver vazia, ponteiro para o início da lista aponta para o novo elemento.

    return ptLista; //Retorna a lista modificada.
}
/*Remove um elemento, selecionando pelo título.*/
TipoPtNo* remover(TipoPtNo* ptLista, char titulo[]) //Passa ponteiro para início da lista e string com título à ser deletado.
{
    TipoPtNo *ant = NULL;   //Ponteiro 'ant' e 'ptaux' utilizados como ponteiros auxiliares.
    TipoPtNo *ptaux = ptLista;

    while (ptaux !=NULL && (strcmp(ptaux->info.titulo, titulo)))    //While testando se ponteiro auxiliar percorrendo a lista chega ao final ou encontra o elemento.
    {
        ant = ptaux;    //Ponteiro 'ant' recebe 'ptaux', armazenando assim o ponteiro para o elemento anterior.
        ptaux = ptaux->prox;    //Ponteiro 'ptaux' recebe 'prox' do elemento, percorrendo assim a lista.
    }
    if (ptaux == NULL)  //Testa se 'ptaux' chegou ao final da lista sem encontrar o elemento, e retorna a lista não modificada.
        return ptLista;
    if (ant == NULL)
        ptLista = ptLista->prox;
    else
        ant->prox = ptaux->prox;    //Else senão chegou ao final, libera o espaço de 'ptaux'.
    free(ptaux);
    return ptLista; //Retorna a lista modificada.
}
/*Libera o espaço da lista.*/
TipoPtNo* destroi(TipoPtNo* ptLista)    //Passa apenas o ponteiro para o início da lista.
{
    TipoPtNo *ptaux; //Ponteiro 'ptaux' que percorre a lista.
    while (ptLista != NULL) //Enquanto a lista não estiver vazia, libera os espaços.
    {
        ptaux = ptLista;
        ptLista = ptLista->prox;
        free(ptaux);
    }
    free(ptLista);  //Libera o espaço do ponteiro para o primeiro elemento da lista e retorna 'NULL'.
    return NULL;
}
