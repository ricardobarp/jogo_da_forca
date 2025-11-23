#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "funcoes.h"

#include <ctype.h>
#include <string.h>

char palavras[13][10] = {"CASA", "CACHORRO", "PAZ", "CARRO", "MESA", "LIVRO",
"ANIMAL", "ESCOLA", "FLORES", "JANELA", "FRUTA", "CAMISA", "MUNDO"};
char slots[20], palavraSorteada[20];

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
    printf("%s, escolha uma opção: ", nome);
}

int sortearPalavra(){
    srand(time(NULL));
    int n = rand() % 13;
    return n;
}

void slotsPalavraSorteada(int n){
    for(int i = 0; palavras[n][i] != '\0'; i++) {
        palavraSorteada[i] = palavras[n][i];
    }
    int tam = strlen(palavraSorteada);
    for(int i = 0; i < tam; i++) {
        slots[i] = '_';
    }
}

int atualizarSlots(char letra) {
    int tam = strlen(slots);
    int letrasCertas = 0;
    for (int i = 0; i < tam; i++) {
        if (palavraSorteada[i] == letra) {
            slots[i] = letra;
            letrasCertas++;
        }
    }
    return letrasCertas;
}

void mostrarSlots() {
    int tam = strlen(slots);
    for (int i = 0; i < tam; i++) {
        printf("%c", slots[i]);
    }
    printf("\n");
}

void mostrarForca(int erros) {
    switch (erros) {
        case 0:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |        \n");
            printf(" |        \n");
            printf(" |        \n");
            printf("_|_\n");
            break;
        case 1:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |        \n");
            printf(" |        \n");
            printf("_|_\n");
            break;
        case 2:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |       |\n");
            printf(" |        \n");
            printf("_|_\n");
            break;
        case 3:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\n");
            printf(" |        \n");
            printf("_|_\n");
            break;
        case 4:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\\\n");
            printf(" |        \n");
            printf("_|_\n");
            break;
        case 5:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\\\n");
            printf(" |      / \n");
            printf("_|_\n");
            break;
        case 6:
            printf("\n");
            printf("  _______\n");
            printf(" |       |\n");
            printf(" |       O\n");
            printf(" |      /|\\\n");
            printf(" |      / \\\n");
            printf("_|_\n");
            printf("\nVOCÊ PERDEU\n");
            break;
    }
}