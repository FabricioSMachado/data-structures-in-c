
/*Tipo definido da lista duplamente encadeada*/
struct TipoInfoNo
{
    int codigo;
    char nome[20];
    float preco;
};
typedef struct TipoInfoNo InfoNo;

/*Declaração do ponteiro da lista duplamente encadeada*/
struct TipoPtNo
{
    InfoNo info;
    struct TipoPtNo* ant;
    struct TipoPtNo* prox;
};
typedef struct TipoPtNo PtNo;

/*Declaração dos métodos*/
PtNo* inicializa(void);

void imprime(PtNo* ptLista);

void imprimeInvertida(PtNo *ptLista);

PtNo* insereInicio(PtNo *ptLista, InfoNo Dado);

PtNo* insereFim(PtNo *ptLista, InfoNo Dado);

PtNo* insereOrdem(PtNo *ptLista, InfoNo Dado);

PtNo* remover(PtNo* ptLista, int cod);

PtNo* destroi(PtNo* ptLista);
