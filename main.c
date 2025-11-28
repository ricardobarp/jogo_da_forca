#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "funcoes.h"

int main() {
    extern char palavraSorteada[], slots[];
    int opcaoMenu = 0, erros = 0, acertos = 0, letraCorreta = 0, tentativas = 0, proximaFase = 1, fases = 0;
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
        while (proximaFase == 1) { //Vai entrar neste while em todas as fases novas
            erros = 0;
            tentativas = 0;
            proximaFase = 0;
            for (int i = 0; i < 26; i++) {
                letraUsada[i] = 0;
            }
            if (sortearPalavra() == -1) {
                printf("%s, você venceu o jogo! Todas as palavras foram descobertas.\n", nome);
                return 0;
            }
            slotsPalavraSorteada();
            mostrarForca(erros);
            printf("A palavra oculta é: ");
            mostrarSlots();

            while (erros < 6 && proximaFase == 0) { //While da fase
                while (1) {
                    printf("%s, digite uma letra: ", nome);
                    scanf(" %c", &letra);
                    if (isalpha(letra)) {
                        break;
                    }
                    printf("Entrada inválida!\n");
                }

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
                    if (strcmp(palavraSorteada, slots) != 0) {
                        printf("\nParabéns %s, você acertou! :D", nome);
                        acertos++;
                        mostrarForca(erros);
                        printf("A palavra oculta é: ");
                        mostrarSlots();
                        tentativas++;
                        continue;
                    }
                    printf("Parabéns, você descobriu a palavra oculta!\n");
                    printf("A palavra oculta era: ");
                    mostrarSlots();
                    do {
                        printf("\n1 - Continuar\n2 - Sair do Jogo\n%s, escolha uma opção: ", nome);
                        if (scanf("%d", &proximaFase) != 1) {
                            getchar(); // limpar buffer
                            printf("Entrada inválida! %s, escolha uma das opções abaixo.", nome);
                            proximaFase = 0;
                            continue;
                        }
                        if (proximaFase != 1 && proximaFase != 2) {
                            printf("Entrada inválida! %s, escolha uma das opções abaixo.", nome);
                            proximaFase = 0;
                            continue;
                        }
                        if (proximaFase == 2) {
                            printf("Saindo...");
                            return 0;
                        }
                        printf("Indo para a próxima fase...");
                        fases++;
                    }while (proximaFase == 0);

                }
                if (letraCorreta == 0) {
                    printf("\nPoxa %s, não foi desta vez :C", nome);
                    erros++;
                    mostrarForca(erros);
                    if (erros < 6) {
                        printf("A palavra oculta é: ");
                        mostrarSlots();
                    }
                    tentativas++;
                }

            }
            //Se o jogador perder o jogo a palavra oculta é revelada
            if (erros == 6) {
                printf("A palavra oculta era: ");
                mostrarPalavraSorteada();
            }
        }
    }

    return 0;
}