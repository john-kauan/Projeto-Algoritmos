cmake_minimum_required(VERSION 3.10)
project(../ProjetoAlgoritmos C)

# Lista todos os arquivos .c explicitamente
set(SOURCES
        main.c
        insertion_sort.c
)

# Cria o executável
add_executable(ProjetoAlgoritmos ${SOURCES})

# Inclui a pasta atual para headers
target_include_directories(ProjetoAlgoritmos PRIVATE ..)
