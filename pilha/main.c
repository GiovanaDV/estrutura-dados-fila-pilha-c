#include <stdio.h>
#include <string.h>
#define MAX 5 
#define TAM 50    


int topo = -1; 
char pilha[MAX][TAM];

void push( char acao[]) {
    if (topo == MAX - 1) {
        printf("Atingiu o limite de operações \n");
        return; 
    }
    strcpy(pilha[++topo], acao);
}
char* pop() {
    if (topo == -1) {
        printf("Não ha nada para desfazer \n");
        return NULL;
        }
    printf("desfez a ação: %s", pilha[topo]);
    return pilha[topo--];
}

char* top() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return NULL; 
    }
    return pilha[topo];
}

void mostrarPilhaAcoes() {
    for (int i = 0; i <= topo; i++) {
        printf("%s", pilha[i]);
    }
    printf("\n");
}