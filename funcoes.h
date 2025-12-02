#ifndef FUNCOES_H
#define FUNCOES_H

void cabecalho();
void menuPrincipal(char[20]);
int sortearPalavra(char palavras[][10], int palavrasUsadas[], char palavraSorteada[]);
void slotsPalavraSorteada(char palavraSorteada[], char slots[]);
int atualizarSlots(char tentativa, char palavraSorteada[], char slots[]);
void mostrarSlots(char slots[]);
void mostrarPalavraSorteada(char palavraSorteada[]);
void mostrarForca(int);

#endif