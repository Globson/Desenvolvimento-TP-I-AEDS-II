#include <stdio.h>
#include <stdlib.h>
#include "INDICE_INVERTIDO.h"

void FLVazia(TipoLista *Lista){
  Lista -> Primeiro = (TipoCelPoint) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

void InsereIndice(TipoLista *Lista, int idDoc, int Qtde){
  Lista -> Ultimo -> Prox = (TipoCelPoint) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> IdDoc = idDoc;
  Lista -> Ultimo -> qtde = Qtde;
  Lista -> Ultimo -> Prox = NULL;
}

int ProcuraIdDoc(TipoLista *Lista, int idDoc, TipoQtdeTermos *Ni){
  TipoCelPoint Aux;
  Aux = Lista -> Primeiro -> Prox;
  while (Aux != NULL && Aux->IdDoc != idDoc){
    Aux = Aux -> Prox;
  }
  if(Aux != NULL){
    Aux->qtde++;
    Ni->nTermsDist--;
    return 1;
  }
  return 0;
}

void Imprime(TipoLista Lista){
  TipoCelPoint Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL){
    printf("\n\t\t-------Inicio da Celula-------\n");
    printf("\t\t->idDoc: %d\n", Aux->IdDoc);
    printf("\t\t->Qtde: %d\n", Aux->qtde);
    printf("\t\t---------Fim da Celula--------\n\n");
    Aux = Aux -> Prox;
  }
}

int ContaCelulaLista(TipoLista Lista){
  TipoCelPoint Aux;
  int cont = 0;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) {
	  cont++;
    Aux = Aux->Prox;
  }
  return cont;
}

void RetornaQtdeEidDocs(TipoLista Lista, int *F, int *D){
  TipoCelPoint Aux;
  int i=0;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL) {
    F[i] = Aux->qtde;
    D[i] = Aux->IdDoc;
    i++;
    Aux = Aux->Prox;
  }
}
