#include <stdio.h>
#include <stdlib.h>
#include "INDICE_INVERTIDO.h"

void FLVazia(TipoLista *Lista){
  Lista -> Primeiro = (TipoCelPoint) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}

/*int Vazia(TipoLista Lista){
  return (Lista.Primeiro == Lista.Ultimo);
}*/

void InsereIndice(TipoLista *Lista, int idDoc, int Qtde){
  Lista -> Ultimo -> Prox = (TipoCelPoint) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Ultimo -> Prox;
  Lista -> Ultimo -> IdDoc = idDoc;
  Lista -> Ultimo -> qtde = Qtde;
  Lista -> Ultimo -> Prox = NULL;
}

int ProcuraIdDoc(TipoLista *Lista, int idDoc){
  TipoCelPoint Aux;
  Aux = Lista -> Primeiro -> Prox;
  while (Aux != NULL && Aux->IdDoc != idDoc){
    Aux = Aux -> Prox;
  }
  if(Aux != NULL){
    Aux->qtde++;
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


/*void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
  // ---   Obs.: o item a ser retirado e  o seguinte ao apontado por  p --- //
  TipoApontador q;
  if (Vazia(*Lista) || p == NULL || p -> Prox == NULL)
  { printf(" Erro   Lista vazia ou posi  c   a o n  a o existe\n");
    return;
  }
  q = p -> Prox;
  *Item = q -> Item;
  p -> Prox = q -> Prox;
  if (p -> Prox == NULL) Lista -> Ultimo = p;
  free(q);
}*/
