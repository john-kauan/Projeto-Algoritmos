#include "heap_sort_min.h"
#include "src/Funcoes/funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

//Algoritmo Heap Sort Min

// ------------------------
// Funções auxiliares (internas)
// ------------------------
static void troca_int(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

static int indice_pai(int i) {
    return (i - 1) / 2;
}
static int indice_esquerdo(int i) {
    return 2 * i + 1;
}
static int indice_direito(int i) {
    return 2 * i + 2;
}

static void imprimir_heap(int heap[], int heap_size) {
    printf("[");
    for (int i = 0; i < heap_size; ++i) {
        printf("%d", heap[i]);
        if (i < heap_size - 1) printf(", ");
    }
    printf("]\n");
}

// ------------------------
// min_heapify: mantém a propriedade de min-heap no índice i
// ------------------------
static void min_heapify(int heap[], int heap_size, int i) {
    int l = indice_esquerdo(i);
    int r = indice_direito(i);
    int menor = i;

    if (l < heap_size && heap[l] < heap[menor]) menor = l;
    if (r < heap_size && heap[r] < heap[menor]) menor = r;

    if (menor != i) {
        troca_int(&heap[i], &heap[menor]);
        min_heapify(heap, heap_size, menor);
    }
}

// ------------------------
// build_min_heap: transforma vetor em min-heap
// ------------------------
static void build_min_heap(int heap[], int heap_size) {
    if (heap_size <= 1) return;
    for (int i = (heap_size / 2) - 1; i >= 0; --i) {
        min_heapify(heap, heap_size, i);
    }
}

// ------------------------
// build_min_heap + extrair mínimos para array auxiliar
// ------------------------
void heap(int vetor[], int n) {
    if (n <= 1) return;

    // constrói min-heap
    build_min_heap(vetor, n);

    // array auxiliar para armazenar a ordem crescente (extração de mínimos)
    int *aux = (int*) malloc(n * sizeof(int));
    if (aux == NULL) {
        printf("Erro de alocacao no heapsort (aux).\n");
        return;
    }

    int heap_size = n;
    for (int i = 0; i < n; ++i) {
        aux[i] = vetor[0]; // menor elemento
        // substituir raiz pelo último elemento do heap
        vetor[0] = vetor[heap_size - 1];
        heap_size--;
        if (heap_size > 0) min_heapify(vetor, heap_size, 0);
    }

    // copiar de aux para vetor (ordenado crescente)
    for (int i = 0; i < n; ++i) vetor[i] = aux[i];

    free(aux);
}

// ------------------------
// Funções da fila de prioridade
// ------------------------

// retorna o menor elemento (consulta)
static int heap_minimum(int heap[], int heap_size) {
    if (heap_size <= 0) {
        fprintf(stderr, "heap_minimum: heap vazio\n");
        return INT_MIN;
    }
    return heap[0];
}

// remove e retorna o menor elemento (atualiza heap_size via ponteiro)
static int heap_extract_min(int heap[], int *heap_size_ptr) {
    int heap_size = *heap_size_ptr;
    if (heap_size < 1) {
        fprintf(stderr, "heap_extract_min: underflow\n");
        return INT_MIN;
    }
    int min = heap[0];
    heap[0] = heap[heap_size - 1];
    (*heap_size_ptr)--;
    if (*heap_size_ptr > 0) min_heapify(heap, *heap_size_ptr, 0);
    return min;
}

// aumenta a chave na posição index para new_val (new_val > heap[index])
static void heap_increase_key(int heap[], int heap_size, int index, int new_val) {
    if (index < 0 || index >= heap_size) {
        printf("heap_increase_key: indice invalido\n");
        return;
    }
    if (new_val < heap[index]) {
        printf("heap_increase_key: novo valor menor que o atual (use decrease para diminuir)\n");
        return;
    }
    heap[index] = new_val;
    // como aumentou, pode precisar "descer" o nó
    min_heapify(heap, heap_size, index);
}


//  insere no final e sobe enquanto necessario (para min-heap)
static void max_heap_insert(int heap[], int *heap_size_ptr, int capacity, int value) {
    int heap_size = *heap_size_ptr;
    if (heap_size >= capacity) {
        printf("max_heap_insert: capacidade excedida (cap=%d)\n", capacity);
        return;
    }
    heap[heap_size] = value;
    int i = heap_size;
    heap_size++;
    while (i != 0 && heap[i] < heap[indice_pai(i)]) {
        troca_int(&heap[i], &heap[indice_pai(i)]);
        i = indice_pai(i);
    }
    *heap_size_ptr = heap_size;
}

// ------------------------
// Menu do HEAP SORT MIN
// ------------------------
void heap_min_menu(){
    char opcao_entrada;
    int tamanho_entrada;
    int tamanho[] = {10,100,1000,10000,100000,1000000};


    do{
        printf("===HEAP SORT MIN - TIPO DE ENTRADA===\n");
        printf("c - Crescente\n");
        printf("d - Decrescente\n");
        printf("r - Randomico\n");
        printf("--------------------------------------\n");
        printf("m - HEAP_MINIMUM (mostrar menor) \n");
        printf("e - HEAP_EXTRACT_MIN (remover menor)\n");
        printf("k - HEAP_INCREASE_KEY (aumentar chave)\n");
        printf("i - MAX_HEAP_INSERT (inserir valor)\n");
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
                        sprintf(entrada_path, "Resultados/HeapSortMin/Entradas/%s/Entrada%s%d.txt", nome_tipo, nome_tipo, n);
                        salvar_dados(entrada_path, vetor, n);

                        // Medir o tempo de execução e ordenar
                        printf("Ordenando %d elementos de forma %s...\n", n, nome_tipo);
                        clock_t start_time = clock();
                        heap(vetor, n);
                        clock_t end_time = clock();
                        double time_spent = (double)(end_time - start_time) / CLOCKS_PER_SEC;

                        // Salvar o arquivo de saída
                        char saida_path[256];
                        sprintf(saida_path, "Resultados/HeapSortMin/Saidas/%s/Saida%s%d.txt", nome_tipo, nome_tipo, n);
                        salvar_dados(saida_path, vetor, n);

                        // Salvar o arquivo de tempo
                        char tempo_path[256];
                        sprintf(tempo_path, "Resultados/HeapSortMin/Tempo/%s/Tempo%s%d.txt", nome_tipo, nome_tipo, n);
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

            case 'm': { // HEAP_MINIMUM - testar no console
                int n = 10;
                int *vet = (int*) malloc(n * sizeof(int));
                if (!vet) { printf("Erro de alocacao.\n"); break; }
                gerar_randomico(vet, n);
                printf("Vetor original:\n");
                imprimir_heap(vet, n);
                build_min_heap(vet, n);
                printf("Heap (apos BUILD_MIN_HEAP):\n");
                imprimir_heap(vet, n);
                int minimo = heap_minimum(vet, n);
                if (minimo != INT_MIN) printf("HEAP_MINIMUM = %d\n", minimo);
                free(vet);
                break;
            }

            case 'e': { // HEAP_EXTRACT_MIN - testar no console
                int n = 10;
                int *vet = (int*) malloc(n * sizeof(int));
                if (!vet) { printf("Erro de alocacao.\n"); break; }
                gerar_randomico(vet, n);
                printf("Vetor original:\n");
                imprimir_heap(vet, n);
                build_min_heap(vet, n);
                printf("Heap (apos BUILD_MIN_HEAP):\n");
                imprimir_heap(vet, n);
                int heap_size = n;
                int min = heap_extract_min(vet, &heap_size);
                if (min != INT_MIN) printf("Elemento extraido (min): %d\n", min);
                printf("Heap depois de HEAP_EXTRACT_MIN:\n");
                imprimir_heap(vet, heap_size);
                free(vet);
                break;
            }

            case 'k': { // HEAP_INCREASE_KEY
                int n = 10;
                int *vet = (int*) malloc(n * sizeof(int));
                if (!vet) { printf("Erro de alocacao.\n"); break; }
                gerar_randomico(vet, n);
                build_min_heap(vet, n);
                printf("Heap (apos BUILD_MIN_HEAP):\n");
                imprimir_heap(vet, n);
                int idx, novo;
                printf("Digite o indice (0..%d) a ser aumentado: ", n-1);
                scanf("%d", &idx);
                printf("Digite o novo valor (maior que o atual): ");
                scanf("%d", &novo);
                printf("Valor atual em [%d] = %d\n", idx, vet[idx]);
                heap_increase_key(vet, n, idx, novo);
                printf("Heap apos HEAP_INCREASE_KEY:\n");
                imprimir_heap(vet, n);
                free(vet);
                break;
            }

            case 'i': { // MAX_HEAP_INSERT (interpretado como inserir no min-heap)
                int n = 10;
                int capacity = n + 10;
                int *vet = (int*) malloc(capacity * sizeof(int));
                if (!vet) { printf("Erro de alocacao.\n"); break; }
                gerar_randomico(vet, n);
                build_min_heap(vet, n);
                printf("Heap (apos BUILD_MIN_HEAP):\n");
                imprimir_heap(vet, n);
                int heap_size = n;
                int valor;
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);
                max_heap_insert(vet, &heap_size, capacity, valor);
                printf("Heap apos insercao:\n");
                imprimir_heap(vet, heap_size);
                free(vet);
                break;
            }

            case '0':
                printf("Voltando ao menu principal...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao_entrada != '0');
}
