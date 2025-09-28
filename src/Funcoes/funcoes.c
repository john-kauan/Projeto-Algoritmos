#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

//Gera numeros crescentes
void gerar_crescente(int vetor[], int n){
    for (int i = 0; i < n; i++){
        vetor[i] = i+1;
    };
};

//Gera numeros decrescentes
void gerar_decrescente(int vetor[], int n){
    for (int i = 0; i < n; i++){
        vetor[i] = n-i;
    };
};

//Gera numeros aleatorios
void gerar_randomico(int vetor[], int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        vetor[i] = rand() % 1000000;
    };
};

//Salva dados em um arquivo
void salvar_dados(const char* nome_dados, int vetor[], int n){
    FILE* arq = fopen(nome_dados,"w");
    if (arq == NULL){
        printf("Erro na abertura do arquivo %s\n", nome_dados);
        return;
    }
    fprintf(arq, "%d\n", n);
    for (int i = 0; i < n; i++){
        fprintf(arq, "%d\n", vetor[i]);
    }
    fclose(arq);
};

//função para criar pastas
void criar_diretorios(const char* base_path, const char* nome_algoritmo) {
    char path[256];

    sprintf(path, "%s/%s", base_path, nome_algoritmo);
    mkdir(path, 0777);

    const char* sub_pastas[] = {"Entradas","Saidas", "Tempo"};
    const char* tipos[] = {"Crescente", "Decrescente", "Randomico"};

    for (int i = 0; i < 3; i++) {
        sprintf(path, "%s/%s/%s", base_path, nome_algoritmo, sub_pastas[i]);
        mkdir(path, 0777);
        for (int j = 0; j < 3; j++) {
            sprintf(path, "%s/%s/%s/%s", base_path, nome_algoritmo, sub_pastas[i], tipos[j]);
            mkdir(path, 0777);
        }
    }
}