#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TF_IDF.h"

void FListVazia(TipoList *Lista){
  Lista -> primeiro = (TipoPoint) malloc(sizeof(TipoCel));
  Lista -> ultimo = Lista -> primeiro;
  Lista -> primeiro -> prox = NULL;
}

void InserePeso(TipoList *Lista, int idDoc, double peso){
  Lista -> ultimo -> prox = (TipoPoint) malloc(sizeof(TipoCel));
  Lista -> ultimo = Lista -> ultimo -> prox;
  Lista -> ultimo -> iddoc = idDoc;
  Lista -> ultimo -> Peso = peso;
  Lista -> ultimo -> prox = NULL;
}

double SomaPesos(TipoList Lista, int idDoc){
  TipoPoint Aux;
  double cont = 0.0;
  Aux = Lista.primeiro -> prox;
  while (Aux != NULL) {
    if(Aux->iddoc == idDoc){
      cont += Aux->Peso;
    }
    Aux = Aux->prox;
  }
  return cont;
}

double CalculaPeso(int numOc, int numDocCterm, int numDocTot){
  double w;
  double a = (log10(numDocTot))/(log10(2));
  w = (numOc) * ((a)/(numDocCterm));
  return w;
}

double CalculaRelevancia(double pesoTotal, int nI){
  return (pesoTotal/nI);
}

void Particao(int Esq, int Dir, int *i, int *j, TipoRelevancia *vetor){
  TipoRelevancia pivo, aux;
  *i = Esq;
  *j = Dir;
  pivo = vetor[(*i + *j)/2];
  do{
    while(pivo.Relevancia < vetor[*i].Relevancia){
      (*i)++;
    }
    while(pivo.Relevancia > vetor[*j].Relevancia){
      (*j)--;
    }
    if(*i <= *j){
      aux = vetor[*i];
      vetor[*i] = vetor[*j];
      vetor[*j] = aux;
      (*i)++;
      (*j)--;
    }
  }while(*i <= *j);
}

void Ordena(int Esq, int Dir, TipoRelevancia *vetor){
  int i, j;
  Particao(Esq, Dir, &i, &j, vetor);
  if(Esq < j){
    Ordena(Esq, j, vetor);
  }
  if(i < Dir){
    Ordena(i, Dir, vetor);
  }
}

void quick_sort(TipoRelevancia *vetor, int n){
  Ordena(0, n-1, vetor);
}
