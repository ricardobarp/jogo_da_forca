#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoes.h"

char palavras[13][10] = {"CASA", "CACHORRO", "PAZ", "CARRO", "MESA", "LIVRO",
"ANIMAL", "ESCOLA", "FLORES", "JANELA", "FRUTA", "CAMISA", "MUNDO"};

void menuPrincipal() {
    printf("===== BEM-VINDO AO JOGO DA FORCA =====\n");
    printf("1 - Jogar\n");
    printf("2 - Regras\n");
    printf("3 - Sobre\n");
    printf("4 - Sair\n");
    printf("======================================\n");
    printf("Escolha uma opção: ");
}

int sortearPalavra(){
    srand(time(NULL));
    int n = rand() % 13;
    return n;
}

void apresentarPalavra(int n){
    printf("%s", palavras[n]);
}