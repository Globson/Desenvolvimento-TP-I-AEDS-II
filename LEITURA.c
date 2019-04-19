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

int Leitura(TipoArvore *t, int *N){
  FILE *Arquivo;
	char caracter, caracter2;
	TipoChave string;
	char NomeArq[13];
	TipoFila Fila;
	int i, TAMFila, idDoc, Verificador, contaDoc = 0, contaPalavras = 0;
	FFVazia(&Fila);
  do{
  	printf("Digite o nome do arquivo da seguinte forma: arquivo(N).txt\n");
  	scanf("%s", &NomeArq);
    (*N)++;
  	idDoc = ((int)NomeArq[7]) - 48;
  	Arquivo = fopen(NomeArq, "r");
  	while(!feof(Arquivo)){
  		fscanf(Arquivo,"%c", &caracter);
  		while((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)){
  			Enfileira(&Fila,caracter);
  			fscanf(Arquivo,"%c", &caracter);
  		}
  		if(!Vazia(Fila)){
  			TAMFila = ContaCelula(Fila);
        if(TAMFila > 2){
          string = (TipoChave)malloc((TAMFila+1)*sizeof(char));
    			for(i=0; i<TAMFila; i++){
    				Desenfileira(&Fila,&caracter2);
            caracter2 = tolower(caracter2);
    				string[i] = caracter2;
    			}
    			string[TAMFila] = '\0';
          (*t) = Insere(string, &(*t), idDoc);
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
    printf("Deseja adicionar textos de outro arquivo?\nSim - 1\nNao - 0\n");
    scanf("%d", &Verificador);
  }while(Verificador != 0);
}

void Busca(TipoArvore t, int N){
  TipoArvore Aux;
  TipoList listaPeso;
  TipoRelevancia *VetorRlva;
  int d, i;
  int *f, *id;
  double peso, PesoTotal;
  FListVazia(&listaPeso);
  VetorRlva = (TipoRelevancia *)malloc(N*sizeof(TipoRelevancia));
  //Começo doWhile
  //Digita a(s) palavra(s)
  Aux = PesquisaNO(/*Palavra*/, t);
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
  //Perguntar se deseja buscar mais palavras
  //fim doWhile
  for(i=1; i<=N; i++){
    PesoTotal = SomaPesos(listaPeso, i);
    VetorRlva[i-1].IDdoc = i;
    VetorRlva[i-1].Relevancia = CalculaRelevancia(PesoTotal, /*Ni*/);
  }
  //Ordena e exibe
}
