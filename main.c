#include <stdio.h>
#include <ctype.h>
#include "funcoes.h"

int main() {
    int opcaoMenu = 0, erros = 0, acertos = 0, letraCorreta = 0, tentativas = 0;
    char nome[20], letra;
    char letraUsada[26] = {0};

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

        while (erros < 6) {
            printf("%s, digite uma letra: ", nome);
            scanf(" %c", &letra);
            letra = toupper(letra);

            // Verifica se a letra já foi usada anteriormente
            int letraRepetida = 0;
            for (int i = 0; i < tentativas; i++) {
                if (letraUsada[i] == letra) {
                    letraRepetida = 1;
                    break;
                }
            }

            if (letraRepetida == 1) {
                printf("Você já digitou esta letra, tente outra.\n");
                continue;
            }
            // Se a letra não foi usada, guarda no vetor de letras usadas:
            letraUsada[tentativas] = letra;

            letraCorreta = atualizarSlots(letra);
            if(letraCorreta > 0) {
                printf("\nParabéns %s, você acertou! :D", nome);
                acertos++;
                mostrarForca(erros);
                printf("A palavra oculta é: ");
                mostrarSlots();
                tentativas++;
                continue;
            }
            if (letraCorreta == 0) {
                printf("\nPoxa %s, não foi desta vez :C", nome);
                erros++;
                mostrarForca(erros);
                printf("A palavra oculta é: ");
                mostrarSlots();
                tentativas++;
            }

        }
    }

    return 0;
}