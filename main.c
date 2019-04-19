#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LEITURA.h"
#include "TST.h"

//Programa principal para testar as funções acima
int main(){
  TipoArvore P = NULL;
  TipoQtdeTermos *Ni;
  int N=0;
  //char quem[5], casa[5], tbm[7], apto[12], tds[6], ngm[8], em[3];
  Ni = Leitura(&P, &N);
  Busca(P, N, Ni);
  /*strcpy(quem,"quem");
  strcpy(casa,"casa");
  strcpy(tbm,"tambem");
  strcpy(apto,"apartamento");
  strcpy(tds,"todos");
  strcpy(ngm,"ninguem");
  strcpy(em,"em");*/
  /*TipoApontador Raiz;
  char mat[7], jos[6], sam[7], joa[5], am[4], para[15], luc[6];
  strcpy(mat,"Mateus");
  strcpy(jos,"JoSue");
  strcpy(sam,"Samuel");
  strcpy(joa,"JOAO");
  strcpy(am,"ama");
  strcpy(para,"paralelepipedo");
  strcpy(luc,"lucas");
  Inicializa(&Raiz);
  Insercao(&Raiz,"cat");
  Insercao(&Raiz,"cats");
  Insercao(&Raiz,"up");
  Insercao(&Raiz,"bug");

  printf("Following is traversal of ternary search tree\n");
  traverseTST(root);

  printf("------------------------\n");
  printf("TST\n");
  printf("Resultados das Pesquisas para cats, bu, cat, up e ca respectivamente\n");
  Pesquisa(Raiz, "cats");
  Pesquisa(Raiz, "bu");
  Pesquisa(Raiz, "cat");
  Pesquisa(Raiz, "up");
  Pesquisa(Raiz, "ca");
  printf("Fim TST\n\n");
  printf("------------------------\n");
  printf("PATRICIA\n");
  printf("Inserindo ama...\n");
  P = Insere(am, &P, 1);
  printf("Inserindo Mateus...\n");
  P = Insere(mat, &P, 2);
  printf("Inserindo JoSue...\n");
  P = Insere(jos, &P, 1);
  printf("Inserindo Samuel...\n");
  P = Insere(sam, &P, 2);
  printf("Inserindo paralelepipedo...\n");
  P = Insere(para, &P, 1);
  printf("Inserindo josue de novo...\n");
  P = Insere(jos, &P, 1);
  printf("Inserindo JOAO...\n");
  P = Insere(joa, &P, 2);
  printf("Inserindo ama de novo...\n");
  P = Insere(am, &P, 2);*/
  /*printf("------------------------\n");
  //Elementos do arquivo 1
  printf("Pesquisando apartamento...\n");
  PesquisaPat(apto, P);
  printf("Pesquisando tambem...\n");
  PesquisaPat(tbm, P);
  //Elementos dos arquivos 1 e 2
  printf("Pesquisando quem...\n");
  PesquisaPat(quem, P);
  printf("Pesquisando casa...\n");
  PesquisaPat(casa, P);
  //Elementos do arquivo 2
  printf("Pesquisando todos...\n");
  PesquisaPat(tds, P);
  printf("Pesquisando ninguem...\n");
  PesquisaPat(ngm, P);
  printf("Pesquisando em...\n");
  PesquisaPat(em, P);
  printf("------------------------\n");*/
  return 0;
}
