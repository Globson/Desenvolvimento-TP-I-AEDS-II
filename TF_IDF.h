
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

void FListVazia(TipoList *Lista);
void InserePeso(TipoList *Lista, int idDoc, double peso);
double SomaPesos(TipoList Lista, int idDoc);
double CalculaPeso(int numOc, int numDocCterm, int numDocTot);
double CalculaRelevancia(double pesoTotal, int nI);
