#include <stdio.h>
#include <ctype.h>
#include "funcoes.h"

int main() {
    int opcaoMenu = 0;
    char nome[20], letra;

    cabecalho();
    printf("Informe seu nome:");
    scanf("%s", nome);

    menuPrincipal(nome);

    if(scanf("%d", &opcaoMenu)!=1){
        printf("Erro! Digite apenas números.\n");
        return 1;
    }

    if(opcaoMenu == 1) {
        int n = sortearPalavra();
        slotsPalavraSorteada(n);
        mostrarSlots();
        while (opcaoMenu == 1) { // Loop apenas para testar!
            printf("%s, digite uma letra: ", nome);
            scanf(" %c", &letra);
            letra = toupper(letra);
            atualizarSlots(letra);
            mostrarSlots();
        }
    }

    return 0;
}