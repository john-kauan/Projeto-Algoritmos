#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "insertion_sort.h"

//função para criar pastas
void criar_diretorios(const char* base_path, const char* nome_algoritmo) {
    char path[256];

    sprintf(path, "%s/%s", base_path, nome_algoritmo);
    mkdir(path, 0777);

    const char* sub_pastas[] = {"Entradas","Saidas", "Tempo"};
    const char* tipos[] = {"Crescente", "Decrescente", "Randomicos"};

    for (int i = 0; i < 3; i++) {
        sprintf(path, "%s/%s/%s", base_path, nome_algoritmo, sub_pastas[i]);
        mkdir(path, 0777);
        for (int j = 0; j < 3; j++) {
            sprintf(path, "%s/%s/%s/%s", base_path, nome_algoritmo, sub_pastas[i], tipos[j]);
            mkdir(path, 0777);
        }
    }
}

//função do menu principal
void menu_principal() {
    int opcao_algoritmo;

    do {
        printf("===ESCOLHA UM ALGORITMO===\n");
        printf("1 - Insertion Sort\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Digite a sua escolha: ");
        scanf("%d", &opcao_algoritmo);

        switch (opcao_algoritmo) {
            case 1:
                insertion_menu();
                break;
            case 0:
                printf("Saindo.....\n");
                break;
        }
    } while (opcao_algoritmo != 0);
}

int main() {

    const char* base_pasta = "Resultados";

    mkdir(base_pasta, 0777);
    criar_diretorios(base_pasta, "InsertionSort");

    menu_principal();

    return 0;
}