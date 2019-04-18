#include <stdio.h>
#include <stdlib.h>
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

void Leitura(TipoArvore *t){
  FILE *Arquivo = NULL;
	char caracter, caracter2;
	TipoChave string;
	char NomeArq[13];
	TipoFila Fila;
	int i, TAMFila, idDoc, Verificador,Verificador2;
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
    idDoc = ((int)NomeArq[7]) - 48;
  	while(!feof(Arquivo)){
  		fscanf(Arquivo,"%c", &caracter);
  		while(caracter != ' ' && caracter != '.' && caracter != '!' && caracter != '?' && caracter != ',' && caracter != ':' && caracter != ';'){
  			Enfileira(&Fila,caracter);
  			fscanf(Arquivo,"%c", &caracter);
  		}
  		if(!Vazia(Fila)){
  			TAMFila = ContaCelula(Fila);
  			string = (TipoChave)malloc((TAMFila+1)*sizeof(char));
  			for(i=0; i<TAMFila; i++){
  				Desenfileira(&Fila,&caracter2);
  				string[i] = caracter2;
  			}
  			string[TAMFila] = '\0';
        (*t) = Insere(string, &(*t), idDoc);
        free(string);
  		}
  	}
  	fclose(Arquivo);
    while(Verificador != 1 && Verificador != 0){
    printf("\nDeseja adicionar textos de outro arquivo?\n\tSim - 1\n\tNao - 0\nEntre com a opcao desejada:");
    scanf("%d", &Verificador);
    if(Verificador != 1 && Verificador != 0){
      printf("\nErro! Opcao invalida!\n");}}
  }while(Verificador != 0);
}
