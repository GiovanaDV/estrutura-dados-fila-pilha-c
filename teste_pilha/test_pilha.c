#include <stdio.h>
#include <string.h>
#define MAX 5

char historico[MAX][100];
int topo = -1;

void push(const char* acao) {
    if (topo == MAX - 1) {
        printf("Historico cheio!\n");
        return;
    }
    strcpy(historico[++topo], acao);
}

void mostrarHistorico() {
    printf("Historico de acoes: ");
    for (int i = 0; i <= topo; i++) {
        printf("[%s] ", historico[i]);
    }
    printf("\n");
}

void desfazer() {
    if (topo == -1) {
        printf("Nada para desfazer!\n");
        return;
    }
    printf("Desfez: %s\n", historico[topo]);
    topo--;
}

int main() {
    push("Escreveu palavra 'Ola'");
    push("Apagou letra 'a'");
    push("Escreveu palavra 'Mundo'");
    push("Copiou texto");
    push("Colou texto");
    mostrarHistorico();

    while (topo >= 0) {
        desfazer();
        mostrarHistorico();
    }
    return 0;
}