#ifndef PATRICIA_H_INCLUDED
#define PATRICIA_H_INCLUDED

#include "INDICE_INVERTIDO.h"

typedef enum{
  Interno, Externo
}TipoNo;

typedef struct TipoPatNo* TipoArvore;
typedef char* TipoChave;

typedef struct{
  TipoLista Lista;
  TipoChave Chave;
}TipoDados;

typedef struct TipoPatNo{
  TipoNo TipoDoNo;
  union{
    struct{
      int Index;
      char LetraComp;
      TipoArvore Esq, Dir;
    }NInterno;
    TipoDados Conteudo;
  }NO;
}TipoPatNo;

int CalculaIndice(TipoChave k, TipoChave Palavra, int N);
int ComparaChaves(TipoChave k, TipoChave Palavra, int TAM1, int TAM2);
int ComparaLetra(int i, char Letra, TipoChave Palavra);
int EExterno(TipoArvore p);
TipoArvore CriaNoInt(int i, TipoArvore *Esq, TipoArvore *Dir, TipoChave Palavra);
TipoArvore CriaNoExt(TipoChave Palavra, int idDoc);
void PesquisaPat(TipoChave Palavra, TipoArvore t);
TipoArvore PesquisaNO(TipoChave Palavra,TipoArvore t);
TipoArvore InsereEntre(TipoChave Palavra, TipoArvore *t, int i, int idDoc);
TipoArvore Insere(TipoChave Palavra, TipoArvore *t, int idDoc, TipoQtdeTermos *Ni);
void ImprimePat(TipoArvore t);
#endif
