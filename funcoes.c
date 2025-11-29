#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include <string.h>

char palavras[13][10] = {"CASA", "CACHORRO", "PAZ", "CARRO", "MESA", "LIVRO",
"ANIMAL", "ESCOLA", "FLORES", "JANELA", "FRUTA", "CAMISA", "MUNDO"};
char slots[20] = {0}, palavraSorteada[20] = {0};
int palavrasUsadas[13] = {0};

void cabecalho() {
    printf("===== BEM-VINDO AO JOGO DA FORCA =====\n");
    printf("- O seu objetivo é descobrir a palavra oculta\n");
    printf("antes que o bonequinho fique completamente desenhado.\n");
    printf("Regras do jogo:\n");
    printf("- Escolha uma letra. Se a letra existir na palavra, a letra será exibida.\n");
    printf("Se a letra não existir o bonequinho será desenhado\n");
    printf("- Você só pode errar 6 vezes a cada fase.\n");
    printf("- Se a palavra oculta for descoberta, você passa de fase\n");
    printf("=====================================\n");
}

void menuPrincipal(char nome[20]) {
    printf("1 - Jogar\n");
    printf("2 - Regras\n");
    printf("3 - Sobre\n");
    printf("4 - Mostrar palavras\n");
    printf("5 - Sair\n");
    printf("%s, escolha uma opção: ", nome);
}

int sortearPalavra(){
    int totalPalavras = 13;
    int palavrasRestantes = 0;

    for (int i = 0; i < totalPalavras; i++) {
        if (!palavrasUsadas[i]) {
            palavrasRestantes++;
        }
    }

    if (palavrasRestantes == 0) {
        return -1;
    }

    int n;
    do {
        n = rand() % totalPalavras;
    } while (palavrasUsadas[n]);

    palavrasUsadas[n] = 1;

    int i;
    for(i = 0; palavras[n][i] != '\0'; i++) {
        palavraSorteada[i] = palavras[n][i];
    }
    palavraSorteada[i] = '\0';
    return 0;
}

void slotsPalavraSorteada(){
    for (int i = 0; i < 20; i++) {
        slots[i] = 0;
    }

    int tam = strlen(palavraSorteada);
    for(int i = 0; i < tam; i++) {
        slots[i] = '_';
    }
    slots[tam] = '\0';
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

void mostrarPalavraSorteada() {
    int tam = strlen(palavraSorteada);
    for (int i = 0; i < tam; i++) {
        printf("%c", palavraSorteada[i]);
    }
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

void listarPalavras() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; palavras[i][j] != '\0'; j++) {
            printf("%c", palavras[i][j]);
        }
        printf(" ");
    }
}