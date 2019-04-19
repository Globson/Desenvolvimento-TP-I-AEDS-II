#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PATRICIA.h"

int CalculaIndice(TipoChave k, TipoChave Palavra, int N){
  int i;
  for(i=0; i<N; i++){
    if(Palavra[i] != k[i]){
      return i;
    }
  }
  return i;
}

int ComparaChaves(TipoChave k, TipoChave Palavra, int TAM1, int TAM2){
  int i;
  if(TAM2 < TAM1){
    return CalculaIndice(k, Palavra, TAM2);
  }
  else if(TAM1 < TAM2){
    return CalculaIndice(k, Palavra, TAM1);
  }
  return CalculaIndice(k, Palavra, TAM1);
}

int ComparaLetra(int i, char Letra, TipoChave Palavra){
  if(Palavra[i] <= Letra){
    return 0;
  }
  return 1;
}

int EExterno(TipoArvore p){
  return (p->TipoDoNo == Externo);
}

TipoArvore CriaNoInt(int i, TipoArvore *Esq, TipoArvore *Dir, TipoChave Palavra){
  TipoArvore p;
  p = (TipoArvore)malloc(sizeof(TipoPatNo));
  p->TipoDoNo = Interno;
  p->NO.NInterno.Esq = *Esq;
  p->NO.NInterno.Dir = *Dir;
  p->NO.NInterno.Index = i;
  p->NO.NInterno.LetraComp = Palavra[i];
  return p;
}

TipoArvore CriaNoExt(TipoChave Palavra, int idDoc){
  TipoArvore p;
  p = (TipoArvore)malloc(sizeof(TipoPatNo));
  p->TipoDoNo = Externo;
  p->NO.Conteudo.Chave = (TipoChave)malloc(strlen(Palavra)*sizeof(char));
  FLVazia(&(p->NO.Conteudo.Lista));
  strcpy(p->NO.Conteudo.Chave, Palavra);
  InsereIndice(&(p->NO.Conteudo.Lista), idDoc, 1);
  return p;
}

void PesquisaPat(TipoChave Palavra, TipoArvore t){
  int tam, j;
  tam = strlen(Palavra);
  for(j=0; j<tam; j++){
    Palavra[j] = tolower(Palavra[j]);
  }
  if(EExterno(t)){
    if(strcmp(Palavra, t->NO.Conteudo.Chave) == 0){
      printf("Elemento encontrado\n");
      Imprime(t->NO.Conteudo.Lista);
    }
    else{
      printf("Elemento nao encontrado\n");
    }
    return;
  }
  if(ComparaLetra(t->NO.NInterno.Index, t->NO.NInterno.LetraComp, Palavra) == 0){
    PesquisaPat(Palavra, t->NO.NInterno.Esq);
  }
  else{
    PesquisaPat(Palavra, t->NO.NInterno.Dir);
  }
}

TipoArvore PesquisaNO(TipoChave Palavra,TipoArvore t){
  if(EExterno(t)){
    if(strcmp(Palavra, t->NO.Conteudo.Chave) == 0){
     return t;
    }
    else{
      return NULL;
    }
  }
  if(ComparaLetra(t->NO.NInterno.Index, t->NO.NInterno.LetraComp, Palavra) == 0){
    return PesquisaNO(Palavra, t->NO.NInterno.Esq);
  }
  else{
    return PesquisaNO(Palavra, t->NO.NInterno.Dir);
  }
}

TipoArvore InsereEntre(TipoChave Palavra, TipoArvore *t, int i, int idDoc){
  TipoArvore p;
  if(EExterno(*t)){
    p = CriaNoExt(Palavra, idDoc);
    if(ComparaLetra(i, (*t)->NO.Conteudo.Chave[i], Palavra) == 1){
      return (CriaNoInt(i, t, &p, (*t)->NO.Conteudo.Chave));
    }
    else{
      return (CriaNoInt(i, &p, t, Palavra));
    }
  }
  else{
    if(ComparaLetra((*t)->NO.NInterno.Index, (*t)->NO.NInterno.LetraComp, Palavra) == 1){
      (*t)->NO.NInterno.Dir = InsereEntre(Palavra, &(*t)->NO.NInterno.Dir, i, idDoc);
    }
    else{
      (*t)->NO.NInterno.Esq = InsereEntre(Palavra, &(*t)->NO.NInterno.Esq, i, idDoc);
    }
    return (*t);
  }
}

TipoArvore Insere(TipoChave Palavra, TipoArvore *t, int idDoc, TipoQtdeTermos *Ni){
  TipoArvore *p;
  int i, TAM1, TAM2;
  if(*t == NULL){
    return (CriaNoExt(Palavra, idDoc));
  }
  else{
    p = t;
    while(!EExterno(*p)){
      if(ComparaLetra((*p)->NO.NInterno.Index, (*p)->NO.NInterno.LetraComp, Palavra) == 1){
        p = &(*p)->NO.NInterno.Dir;
      }
      else{
        p = &(*p)->NO.NInterno.Esq;
      }
    }
    TAM2 = strlen(Palavra);
    TAM1 = strlen((*p)->NO.Conteudo.Chave);
    i = ComparaChaves((*p)->NO.Conteudo.Chave, Palavra, TAM1, TAM2);
    if(TAM1 == TAM2){
      if(i == TAM1){
        printf("Atencao: Chave (%s) ja esta na arvore!\n", (*p)->NO.Conteudo.Chave);
        int Verifica;
        Verifica = ProcuraIdDoc(&(*p)->NO.Conteudo.Lista, idDoc, Ni);
        if(Verifica == 0){
          InsereIndice(&(*p)->NO.Conteudo.Lista, idDoc, 1);
        }
        return (*t);
      }
      else{
        return (InsereEntre(Palavra, t, i, idDoc));
      }
    }
    else{
      return (InsereEntre(Palavra, t, i, idDoc));
    }
  }
}
