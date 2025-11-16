#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoes.h"

char palavras[13][10] = {"CASA", "CACHORRO", "PAZ", "CARRO", "MESA", "LIVRO",
"ANIMAL", "ESCOLA", "FLORES", "JANELA", "FRUTA", "CAMISA", "MUNDO"};

void cabecalho() {
    printf("===== BEM-VINDO AO JOGO DA FORCA =====\n");
    printf("- O seu objetivo é descobrir a palavra oculta\n");
    printf("antes que o bonequinho fique completamente desenhado.\n");
    printf("Regras do jogo:\n");
    printf("- Escolha uma letra. Se a letra existir na palavra, a letra será exibida.\n");
    printf("Se a letra não existir o bonequinho será desenhado\n");
    printf("- Você só pode errar 6 vezes a cada fase.\n");
    printf("- Você pode tentar chutar uma palavra, mas se errar você perde o jogo.\n");
    printf("- Se a palavra oculta for descoberta, você passa de fase\n");
    printf("=====================================\n");
}

void menuPrincipal(char nome[20]) {
    printf("1 - Jogar\n");
    printf("2 - Regras\n");
    printf("3 - Sobre\n");
    printf("4 - Sair\n");
    printf("%s escolha uma opção: ", nome);
}

int sortearPalavra(){
    srand(time(NULL));
    int n = rand() % 13;
    return n;
}

void apresentarPalavra(int n){
    printf("%s", palavras[n]);
}