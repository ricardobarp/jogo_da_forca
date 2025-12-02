#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcoes.h"

int main() {
    char palavras[13][10] = {"CASA", "CACHORRO", "PAZ", "CARRO", "MESA", "LIVRO",
    "ANIMAL", "ESCOLA", "FLORES", "JANELA", "FRUTA", "CAMISA", "MUNDO"};
    char slots[20] = {0}, palavraSorteada[20] = {0};
    int palavrasUsadas[13] = {0};

    int opcaoMenu = 0, erros = 0, letraCorreta = 0;
    int qtdLetrasUsadas = 0, proximaFase = 1, passardeFase = 0, fases = 1;
    char nome[20], letraUsada[26] = {0}, tentativa[20], letra;
    srand(time(NULL));

    cabecalho();
    printf("Informe seu nome:");
    scanf("%s", nome);

    while (opcaoMenu == 0) {

        menuPrincipal(nome);

        if(scanf("%d", &opcaoMenu)!=1){
            printf("Erro! Digite apenas números.\n");
            return 1;
        }

        if(opcaoMenu == 1) {
            while (proximaFase == 1) { //Vai entrar neste while em todas as fases novas
                while (passardeFase == 1) {
                    printf("\n1 - Continuar\n2 - Sair do Jogo\n%s, escolha uma opção: ", nome);
                    if (scanf("%d", &passardeFase) != 1) {
                        getchar(); // limpar buffer
                        printf("Entrada inválida! %s, escolha uma das opções abaixo.", nome);
                        passardeFase = 1;
                        continue;
                    }
                    if (passardeFase != 1 && passardeFase != 2) {
                        printf("Entrada inválida! %s, escolha uma das opções abaixo.", nome);
                        passardeFase = 1;
                        continue;
                    }
                    if (passardeFase == 2) {
                        printf("Saindo...");
                        return 0;
                    }
                    printf("Indo para a próxima fase...\n");
                    fases++;
                    break;
                }
                erros = 0;
                qtdLetrasUsadas = 0;
                proximaFase = 0;
                passardeFase = 0;
                for (int i = 0; i < 26; i++) {
                    letraUsada[i] = 0;
                }
                if (sortearPalavra(palavras, palavrasUsadas, palavraSorteada) == -1) {
                    int voltarMenu = 0;
                    opcaoMenu = 0;
                    printf("%s, você venceu o jogo! Todas as palavras foram descobertas.\n", nome);
                    do {
                        printf("\n1 - Voltar ao menu principal\n2 - Sair do Jogo\n%s, escolha uma opção: ", nome);
                        if (scanf("%d", &voltarMenu) != 1) {
                            getchar(); // limpar buffer
                            printf("Entrada inválida! %s, escolha uma das opções abaixo.", nome);
                            voltarMenu = 0;
                            continue;
                        }
                        if (voltarMenu != 1 && voltarMenu != 2) {
                            printf("Entrada inválida! %s, escolha uma das opções abaixo.", nome);
                            proximaFase = 0;
                            voltarMenu = 0;
                            continue;
                        }
                        if (voltarMenu == 2) {
                            printf("Saindo...");
                            return 0;
                        }
                        if (voltarMenu == 1) {
                            for (int i = 0; i < 13; i++) {
                                palavrasUsadas[i] = 0;
                            }
                            proximaFase = 1;
                            opcaoMenu = 0;
                        }
                    }while (voltarMenu == 0);
                    break;
                }
                slotsPalavraSorteada(palavraSorteada, slots);
                printf("\nFase: %d-13", fases);
                mostrarForca(erros);
                printf("A palavra oculta é: ");
                mostrarSlots(slots);

                while (erros < 6 && proximaFase == 0) { //While da fase
                    while (1) {
                        printf("%s, arrisque uma palavra ou digite uma letra: ", nome);
                        scanf(" %s", tentativa);

                        int tam = strlen(tentativa);
                        int valida = 0;

                        for (int i = 0; i < tam; i++) {
                            if (isalpha(tentativa[i])) {
                                valida++;
                            }
                        }
                        if (valida != tam) {
                            printf("Entrada Inválida, tente novamente\n");
                            continue;
                        }

                        break;
                    }
                        if (strlen(tentativa) > 1) {
                            int tam = strlen(palavraSorteada);
                            for (int i = 0; i < tam; i++) {
                                tentativa[i] = toupper(tentativa[i]); //para deixar a palavra maiúscula
                            }

                            if (strcmp(palavraSorteada, tentativa) == 0) {
                                strcpy(slots, palavraSorteada);
                                printf("Parabéns, você descobriu a palavra oculta!\n");
                                printf("A palavra oculta era: ");
                                mostrarSlots(slots);
                                proximaFase = 1;
                                passardeFase = 1;
                                break;
                            }
                            if (strcmp(tentativa, palavraSorteada) != 0) {
                                erros = 6;
                                mostrarForca(erros);
                                break;
                            }
                        }

                    if (strlen(tentativa) == 1) {
                        letra = toupper(tentativa[0]);

                        // Verifica se a letra já foi usada anteriormente
                        int letraRepetida = 0;
                        for (int i = 0; i < qtdLetrasUsadas; i++) {
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
                        letraUsada[qtdLetrasUsadas] = letra;
                    }
                    letraCorreta = atualizarSlots(letra, palavraSorteada, slots);
                    if(letraCorreta > 0) {
                        if (strcmp(palavraSorteada, slots) != 0) {
                            printf("\nParabéns %s, você acertou! :D", nome);
                            printf("\nFase: %d-13", fases);
                            mostrarForca(erros);
                            printf("A palavra oculta é: ");
                            mostrarSlots(slots);
                            qtdLetrasUsadas++;
                            continue;
                        }
                        printf("Parabéns, você descobriu a palavra oculta!\n");
                        printf("A palavra oculta era: ");
                        mostrarSlots(slots);
                        proximaFase = 1;
                        passardeFase = 1;
                        break;

                    }
                    if (letraCorreta == 0) {
                        printf("\nPoxa %s, não foi desta vez :C", nome);
                        erros++;
                        printf("\nFase: %d-13", fases);
                        mostrarForca(erros);
                        if (erros < 6) {
                            printf("A palavra oculta é: ");
                            mostrarSlots(slots);
                        }
                        qtdLetrasUsadas++;
                    }

                }
                //Se o jogador perder o jogo a palavra oculta é revelada
                if (erros == 6) {
                    printf("A palavra oculta era: ");
                    mostrarPalavraSorteada(palavraSorteada);
                }

            }
        }
        if(opcaoMenu == 2) {
            cabecalho();
            printf("\n");
            opcaoMenu = 0;
        }
        if(opcaoMenu == 3) {
            printf("Desenvolvido por Ricardo Barp\n");
            opcaoMenu = 0;
        }
        if(opcaoMenu == 4) {
            printf("Saindo...\n");
            return 0;
        }
    }
    return 0;
}