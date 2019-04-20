#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LEITURA.h"

void FFVazia(TipoFila *Fila){
  Fila->Frente = (TipoFilPoint) malloc(sizeof(TipoCelulaFila));
  Fila->Tras = Fila->Frente;
  Fila->Frente->Prox = NULL;
}

int Vazia(TipoFila Fila){
  return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoFila *Fila, char Caract){
  Fila->Tras->Prox = (TipoFilPoint) malloc(sizeof(TipoCelulaFila));
  Fila->Tras = Fila->Tras->Prox;
  Fila->Tras->letra = Caract;
  Fila->Tras->Prox = NULL;
}

void Desenfileira(TipoFila *Fila, TipoChave Item){
  TipoFilPoint q;
  if (Vazia(*Fila)) {
    printf("Erro fila esta vazia\n");
	return;
  }
  q = Fila->Frente;
  Fila->Frente = Fila->Frente->Prox;
  *Item = Fila->Frente->letra;
  free(q);
}

int ContaCelula(TipoFila Fila){
  TipoFilPoint Aux;
  int cont = 0;
  Aux = Fila.Frente->Prox;
  while (Aux != NULL) {
	  cont++;
      Aux = Aux->Prox;
  }
  return cont;
}

TipoQtdeTermos* Leitura(TipoArvore *t, int *N){
  FILE *Arquivo = NULL;
	char caracter, caracter2;
	TipoChave string;
	char NomeArq[13];
	TipoFila Fila;
  TipoQtdeTermos *NiAux = NULL;
	int i, j=0, TAMFila, idDoc, Verificador,Verificador2;
	FFVazia(&Fila);
  do{
    Verificador = 2;
    Verificador2 = 0;
    while(Verificador2 == 0){
  	printf("\nDigite o nome do arquivo da seguinte forma -> 'arquivo(N).txt' :");
  	scanf("%s",NomeArq);
    Arquivo = fopen(NomeArq, "r");
    if(Arquivo == NULL){
      printf("\n\tErro!Nao foi possivel abrir arquivo!\n");}
    else{
      Verificador2 = 1;}}
    (*N)++;
    NiAux = (TipoQtdeTermos *)realloc(NiAux, (*N)*sizeof(TipoQtdeTermos));
  	idDoc = ((int)NomeArq[7]) - 48;
    NiAux[j].iDdOc = idDoc;
    NiAux[j].nTermsDist = 0;
  	while(!feof(Arquivo)){
  		fscanf(Arquivo,"%c", &caracter);
  		while((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)){
  			Enfileira(&Fila,caracter);
  			fscanf(Arquivo,"%c", &caracter);
  		}
  		if(!Vazia(Fila)){
  			TAMFila = ContaCelula(Fila);
        if(TAMFila > 2){ //sameul testou no linux com 2
          string = (TipoChave)malloc((TAMFila+1)*sizeof(char));
    			for(i=0; i<TAMFila; i++){
    				Desenfileira(&Fila,&caracter2);
            caracter2 = tolower(caracter2);
    				string[i] = caracter2;
    			}
    			string[TAMFila] = '\0';
          NiAux[j].nTermsDist++;
          (*t) = Insere(string, &(*t), idDoc, &(NiAux[j]));
          free(string);
        }
        else{
          for(i=0; i<TAMFila; i++){
    				Desenfileira(&Fila,&caracter2);
    			}
        }
  		}
  	}
  	fclose(Arquivo);
    while(Verificador != 1 && Verificador != 0){
    printf("\nDeseja adicionar textos de outro arquivo?\n\tSim - 1\n\tNao - 0\nEntre com a opcao desejada:");
    scanf("%d", &Verificador);
    if(Verificador != 1 && Verificador != 0){
      printf("\nErro! Opcao invalida!\n");}}
    j++;
  }while(Verificador != 0);
  return NiAux;
}

void Busca(TipoArvore t, int N, TipoQtdeTermos *Ni){
  TipoArvore Aux;
  TipoList listaPeso;
  TipoRelevancia *VetorRlva;
  int d, i, j, nI, Verificador, TAM;
  int *f, *id;
  char *str;
  double peso, PesoTotal;
  FListVazia(&listaPeso);
  VetorRlva = (TipoRelevancia *)malloc(N*sizeof(TipoRelevancia));
  do{//Começo doWhile
    printf("\nDigite o tamanho da palavra que deseja buscar:");
    scanf("%d", &TAM);
    str = (char *)malloc((TAM+1)*sizeof(char));
    printf("\nDigite a palavra que deseja:");
    scanf("%s", str);
    Aux = PesquisaNO(str, t);
    free(str);
    d = ContaCelulaLista(Aux->NO.Conteudo.Lista);
    f = (int *)malloc(d*sizeof(int));//Vetor de quantidades
    id = (int *)malloc(d*sizeof(int));//Vetor de idDocs
    RetornaQtdeEidDocs(Aux->NO.Conteudo.Lista, f, id);
    for(i=0; i<d; i++){
      peso = CalculaPeso(f[i], d, N);
      InserePeso(&listaPeso, id[i], peso);
    }
    free(f);
    free(id);
    printf("\nDeseja buscar mais palavras?\n\tSim - 1\n\tNao - 0\nEntre com a opcao desejada:");
    scanf("%d", &Verificador);
  }while(Verificador != 0);//fim doWhile
  for(i=1; i<=N; i++){
    PesoTotal = SomaPesos(listaPeso, i);
    VetorRlva[i-1].IDdoc = i;
    for(j=0; j<N; j++){
      if(Ni[j].iDdOc == i){
        nI = Ni[j].nTermsDist;
        break;
      }
    }
    VetorRlva[i-1].Relevancia = CalculaRelevancia(PesoTotal, nI);
  }
  quick_sort(VetorRlva, N);
  printf("A partir do TF-IDF, os documentos mais relevantes sao:\n");
  for(i=0; i<N; i++){
    if(VetorRlva[i].Relevancia == 0.0){
      break;
    }
    printf("Texto %d: (arquivo%d.txt)\n", VetorRlva[i].IDdoc, VetorRlva[i].IDdoc);
  }
  free(VetorRlva);
}
