#ifndef TF_IDF_H_INCLUDED
#define TF_IDF_H_INCLUDED

typedef struct TipoCel *TipoPoint;

typedef struct TipoCel {
  int iddoc;
  double Peso;
  TipoPoint prox;
} TipoCel;

typedef struct {
  TipoPoint primeiro, ultimo;
} TipoList;

typedef struct{
  int IDdoc;
  double Relevancia;
}TipoRelevancia;

typedef struct{
  int iDdOc, nTermsDist;
}TipoQtdeTermos;

void FListVazia(TipoList *Lista);
void InserePeso(TipoList *Lista, int idDoc, double peso);
double SomaPesos(TipoList Lista, int idDoc);
double CalculaPeso(int numOc, int numDocCterm, int numDocTot);
double CalculaRelevancia(double pesoTotal, int nI);
void Particao(int Esq, int Dir, int *i, int *j, TipoRelevancia *vetor);
void Ordena(int Esq, int Dir, TipoRelevancia *vetor);
void quick_sort(TipoRelevancia *vetor, int n);
#endif
