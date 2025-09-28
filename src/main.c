#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "Funcoes/funcoes.h"
#include "Algoritmos/Bubble_Sort/bubble_sort.h"
#include "Algoritmos/Insertion_sort/insertion_sort.h"
#include "Algoritmos/Selection_sort/selection_sort.h"
#include "Algoritmos/Shell_sort/shell_sort.h"


//função do menu principal
void menu_principal() {
    int opcao_algoritmo;

    do {
        printf("===ESCOLHA UM ALGORITMO===\n");
        printf("1 - Insertion Sort\n");
        printf("2 - Selection Sort\n");
        printf("3 - Shell Sort\n");
        printf("4 - Bubble Sort\n");
        printf("0 - Sair\n");
        printf("==========================\n");
        printf("Digite a sua escolha: ");
        scanf("%d", &opcao_algoritmo);

        switch (opcao_algoritmo) {
            case 1:
                insertion_menu();
                break;
            case 2:
                selection_menu();
                break;
            case 3:
                shell_menu();
                break;
            case 4:
                bubble_menu();
                break;
            case 0:
                printf("Saindo.....\n");
                break;
            default:
                printf("Opcao de algoritmo invalida.\n");
                break;
        }
    } while (opcao_algoritmo != 0);
}

int main() {

    const char* base_pasta = "Resultados";

    mkdir(base_pasta, 0777);
    criar_diretorios(base_pasta, "InsertionSort");
    criar_diretorios(base_pasta, "SelectionSort");
    criar_diretorios(base_pasta, "ShellSort");
    criar_diretorios(base_pasta, "BubbleSort");

    menu_principal();

    return 0;
}