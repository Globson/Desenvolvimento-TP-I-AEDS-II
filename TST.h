
typedef struct TipoNoTST* TipoApontador;

//Um nó da TST
typedef struct TipoNoTST{
    char Chave;
    //Verdadeiro se o caracter é o último caracter das palavras
    unsigned FimDeString: 1;
    TipoApontador Esq, Meio, Dir;
}TipoNoTST;

void Inicializa(TipoApontador *Raiz);
void Insercao(TipoApontador *Raiz, char *Palavra);
void Pesquisa(TipoApontador Raiz, char *Palavra);
