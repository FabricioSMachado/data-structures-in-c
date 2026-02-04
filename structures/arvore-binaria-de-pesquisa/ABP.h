//Declaração do tipo de dado para ABP, com a info sendo um número inteiro.
struct TNodoA
{
    int info;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;


//Declaração das funções.
pNodoA* cria_arvore(void);

void preFixadoEsq(pNodoA *a);

void centralEsq(pNodoA *a);

void posFixadoEsq(pNodoA *a);

void preFixadoDir(pNodoA *a);

void centralDir(pNodoA *a);

void posFixadoDir(pNodoA *a);

pNodoA* InsereArvore(pNodoA *a, int ch);

pNodoA* Remove(int X, pNodoA* T);

pNodoA* Maior(pNodoA* r);

pNodoA* consultaABP(pNodoA *a, int chave);
