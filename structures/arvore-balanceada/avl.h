typedef int TipoInfo;

struct TNodoA
{
    TipoInfo info;
    int FB;
    struct TNodoA *esq;
    struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

pNodoA* cria_arvore(void);

pNodoA* rotacao_esquerda(pNodoA *p);

pNodoA* rotacao_direita(pNodoA* p);

pNodoA* rotacao_dupla_esquerda (pNodoA *p);

pNodoA* rotacao_dupla_direita (pNodoA* p);

pNodoA* InsereAVL (pNodoA *a, TipoInfo x, int *ok);

pNodoA* Caso1 (pNodoA *a, int *ok);

pNodoA* Caso2 (pNodoA *a, int *ok);

pNodoA* Remove(int X, pNodoA* T);

pNodoA* Maior(pNodoA* r);

void preFixadoEsq(pNodoA *a);

void centralEsq(pNodoA *a);

void posFixadoEsq(pNodoA *a);

void preFixadoDir(pNodoA *a);

void centralDir(pNodoA *a);

void posFixadoDir(pNodoA *a);
