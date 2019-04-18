#ifndef INDICE_INVERTIDO_H_INCLUDED
#define INDICE_INVERTIDO_H_INCLUDED

typedef struct TipoCelula *TipoCelPoint;

typedef struct TipoCelula {
  int IdDoc, qtde;
  TipoCelPoint Prox;
} TipoCelula;

typedef struct {
  TipoCelPoint Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista);
void InsereIndice(TipoLista *Lista, int idDoc, int Qtde);
int ProcuraIdDoc(TipoLista *Lista, int idDoc);
void Imprime(TipoLista Lista);
#endif
