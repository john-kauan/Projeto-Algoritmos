#include "merge_sort.h"
#include "src/Funcoes/funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Algoritmo Merge Sort
void mergeIntercala(int vetor[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int temp[fim - inicio + 1];

    while (i <= meio && j <= fim) {
        if (vetor[i] <= vetor[j]) {
            temp[k++] = vetor[i++];
        } else {
            temp[k++] = vetor[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = vetor[i++];
    }

    while (j <= fim) {
        temp[k++] = vetor[j++];
    }

    for (i = inicio, k = 0; i <= fim; i++, k++) {
        vetor[i] = temp[k];
    }
}

void mergeRec(int vetor[], int inicio, int fim) {

    if (inicio < fim) {
        int meio = (inicio + fim) / 2;

        mergeRec(vetor, inicio, meio);
        mergeRec(vetor, meio + 1, fim);
        mergeIntercala(vetor, inicio, meio, fim);
    }
}

void merge(int vetor[], int n){
    mergeRec(vetor , 0, n - 1);
}

//Função menu do MERGE SORT
void merge_menu(){
    char opcao_entrada;
    int tamanho_entrada;
    int tamanho[] = {10,100,1000,10000,100000,1000000};


    do{
        printf("===MERGE SORT - TIPO DE ENTRADA===\n");
        printf("c - Crescente\n");
        printf("d - Decrescente\n");
        printf("r - Randomico\n");
        printf("0 - Voltar\n");
        printf("======================================\n");
        printf("Digite a sua escolha: ");
        scanf(" %c", &opcao_entrada);

        switch (opcao_entrada) {
            case 'c':
            case 'd':
            case 'r':
                do {
                    printf("\n=== TAMANHO DA ENTRADA ===\n");
                    printf("1 - 10\n");
                    printf("2 - 100\n");
                    printf("3 - 1.000\n");
                    printf("4 - 10.000\n");
                    printf("5 - 100.000\n");
                    printf("6 - 1.000.000\n");
                    printf("0 - Voltar\n");
                    printf("======================================\n");
                    printf("Digite sua escolha: ");
                    scanf("%d", &tamanho_entrada);

                    if (tamanho_entrada >= 1 && tamanho_entrada <= 6) {
                        int n = tamanho[tamanho_entrada - 1];
                        int* vetor = (int*)malloc(n * sizeof(int));
                        if (vetor == NULL) {
                            printf("Erro de alocacao de memoria para o tamanho %d.\n", n);
                            continue;
                        }

                        char nome_tipo[20];


                        if (opcao_entrada == 'c') {
                            strcpy(nome_tipo, "Crescente");
                            gerar_crescente(vetor, n);
                        } else if (opcao_entrada == 'd') {
                            strcpy(nome_tipo, "Decrescente");
                            gerar_decrescente(vetor, n);
                        } else {
                            strcpy(nome_tipo, "Randomico");
                            gerar_randomico(vetor, n);
                        }

                        //salvar o arquivo de entrada
                        char entrada_path[256];
                        sprintf(entrada_path, "Resultados/MergeSort/Entradas/%s/Entrada%s%d.txt", nome_tipo, nome_tipo, n);
                        salvar_dados(entrada_path, vetor, n);

                        // Medir o tempo de execução e ordenar
                        printf("Ordenando %d elementos de forma %s...\n", n, nome_tipo);
                        clock_t start_time = clock();
                        merge(vetor, n);
                        clock_t end_time = clock();
                        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                        // Salvar o arquivo de saída
                        char saida_path[256];
                        sprintf(saida_path, "Resultados/MergeSort/Saidas/%s/Saida%s%d.txt", nome_tipo, nome_tipo, n);
                        salvar_dados(saida_path, vetor, n);

                        // Salvar o arquivo de tempo
                        char tempo_path[256];
                        sprintf(tempo_path, "Resultados/MergeSort/Tempo/%s/Tempo%s%d.txt", nome_tipo, nome_tipo, n);
                        FILE* tempo_file = fopen(tempo_path, "w");
                        if (tempo_file != NULL) {
                            fprintf(tempo_file, "Tempo gasto: %.6f segundos\n", time_spent);
                            fclose(tempo_file);
                        }

                        printf("======RESULTADO DA ORDENAÇÃO=======\n");
                        printf("Tipo de Entrada: %s\n", nome_tipo);
                        printf("Tamanho da Entrada: %d\n", n);
                        printf("Tempo de Execucao: %.6f segundos\n", time_spent);
                        printf("Arquivos gerados com sucesso!\n");
                        printf("========================================\n\n");

                        free(vetor);
                    } else if (tamanho_entrada != 0) {
                        printf("Opcao de tamanho invalida.\n");
                    }
                } while (tamanho_entrada != 0);
                break;
            case '0':
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao_entrada != '0');
}