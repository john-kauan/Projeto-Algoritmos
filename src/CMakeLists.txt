cmake_minimum_required(VERSION 3.10)
project(../Projeto-Algoritmos C)

# Lista todos os arquivos .c explicitamente
set(SOURCES
        main.c
        Funcoes/funcoes.c
        Algoritmos/Insertion_sort/insertion_sort.c
        Algoritmos/Selection_sort/selection_sort.c
        Algoritmos/Shell_sort/shell_sort.c
        Algoritmos/Bubble_Sort/bubble_sort.c

)

# Cria o executável
add_executable(Projeto-Algoritmos ${SOURCES})

# Inclui a pasta atual para headers
target_include_directories(Projeto-Algoritmos PRIVATE ..)
