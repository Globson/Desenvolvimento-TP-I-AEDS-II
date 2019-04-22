all: main.c INDICE_INVERTIDO.c LEITURA.c PATRICIA.c TST.c TF_IDF.c
	gcc main.c -o EXEC INDICE_INVERTIDO.c LEITURA.c PATRICIA.c TST.c TF_IDF.c -lm

run: EXEC
	./EXEC

clear: EXEC
	rm EXEC