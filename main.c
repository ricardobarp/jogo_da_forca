#include <stdio.h>
#include "funcoes.h"

int main() {
    int opcaoMenu;

    menuPrincipal();
    if(scanf("%d\n", &opcaoMenu)!=1){
        printf("Erro! Digite apenas números.\n");
    }

    return 0;
}