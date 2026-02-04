typedef int TipoInfo;

struct TPtPilha{
    TipoInfo dado;
    struct TPtPilha *elo;
}; typedef struct TPtPilha TipoPilha;

TipoPilha* InicializaPilha (void);  //Cria pilha vazia.

int VaziaPilha (TipoPilha *Topo);   //Retorna 1 (true) se pilha vazia, 0 (false) caso contr�rio.

int PopPilha (TipoPilha **Topo, TipoInfo *Dado);    //Remove o elemento do topo da pilha.

TipoPilha* PushPilha (TipoPilha *Topo, TipoInfo Dado);  //Insere novo elemento no topo da pilha, e retorna o novo topo.

TipoInfo ConsultaPilha (TipoPilha *Topo);   //Retorna informa��o do elemento do topo da pilha

TipoPilha* DestroiPilha (TipoPilha *Topo);  //Destr�i a pilha.

void ImprimePilha (TipoPilha *Topo);
