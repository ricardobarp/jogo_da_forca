#include <stdio.h>
#include "funcoes.h"

int main() {
    int opcaoMenu = 0;

    menuPrincipal();
    if(scanf("%d", &opcaoMenu)!=1){
        printf("Erro! Digite apenas números.\n");
        return 1;
    }

    if(opcaoMenu == 1) {
        int n = sortearPalavra();
        apresentarPalavra(n);
    }

    return 0;
}