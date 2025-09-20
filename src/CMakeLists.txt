cmake_minimum_required(VERSION 3.10)
project(../Projeto-Algoritmos C)

# Lista todos os arquivos .c explicitamente
set(SOURCES
        main.c
        insertion_sort.c
)

# Cria o executável
add_executable(Projeto-Algoritmos ${SOURCES})

# Inclui a pasta atual para headers
target_include_directories(Projeto-Algoritmos PRIVATE ..)
