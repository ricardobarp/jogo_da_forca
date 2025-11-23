#include <stdio.h>
#include <ctype.h>
#include "funcoes.h"

int main() {
    int opcaoMenu = 0, erros = 0, acertos = 0, tentativa = 0;
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
        mostrarForca(erros);
        printf("A palavra oculta é: ");
        mostrarSlots();

        while (erros < 6) { // Loop apenas para testar!
            printf("%s, digite uma letra: ", nome);
            scanf(" %c", &letra);
            letra = toupper(letra);
            tentativa = atualizarSlots(letra);
            if(tentativa > 0) {
                acertos++;
                printf("\nParabéns %s, você acertou! :D", nome);
                mostrarForca(erros);
                printf("A palavra oculta é: ");
                mostrarSlots();
                continue;
            }
            if (tentativa == 0) {
                erros++;
                printf("\nPoxa %s, não foi desta vez :C", nome);
                mostrarForca(erros);
                printf("A palavra oculta é: ");
                mostrarSlots();
            }

        }
    }

    return 0;
}