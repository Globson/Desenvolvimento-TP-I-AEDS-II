#ifndef LEITURA_H_INCLUDED
#define LEITURA_H_INCLUDED

#include "PATRICIA.h"

typedef struct TipoCelulaFila *TipoFilPoint;

typedef struct TipoCelulaFila {
  char letra;
  TipoFilPoint Prox;
} TipoCelulaFila;

typedef struct TipoFila {
  TipoFilPoint Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila);
int Vazia(TipoFila Fila);
void Enfileira(TipoFila *Fila, char Caract);
void Desenfileira(TipoFila *Fila, TipoChave Item);
int ContaCelula(TipoFila Fila);
TipoQtdeTermos* Leitura(TipoArvore *t, int *N);
void Busca(TipoArvore t, int N, TipoQtdeTermos *Ni);
#endif
