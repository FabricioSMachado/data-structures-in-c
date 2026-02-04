/*Tipo definido da lista encadeada*/

struct s_InfoNo
{
    char titulo[20];
    char distr[20];
    char diretor[20];
};
typedef struct s_InfoNo TipoInfoNo;

/*Declaração do ponteiro da lista encadeada*/
struct s_PtNo
{
    TipoInfoNo info;
    struct s_PtNo * prox;
};
typedef struct s_PtNo TipoPtNo;

/*Declaração dos métodos*/
TipoPtNo* inicializa(void);

void imprime(TipoPtNo* ptLista);

void consulta(TipoPtNo* ptLista, char titulo[]);

TipoPtNo* insereInicio (TipoPtNo* ptLista, TipoInfoNo dados);

TipoPtNo* insereFim (TipoPtNo* ptLista, TipoInfoNo dados);

TipoPtNo* remover(TipoPtNo* ptLista, char titulo[]);

TipoPtNo* destroi(TipoPtNo* ptLista);
