#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10


typedef struct {
    int senha;
    char nome[50];
} Paciente;

Paciente fila[MAX];
int inicio = 0, fim = -1, qtd = 0;
int prox_senha = 1;

void enqueque(const char* nome) {
    if (qtd == MAX) {
        printf("Fila cheia!\n");
        return;
    }

    fim = (fim + 1) % MAX;
    fila[fim].senha = prox_senha++;
    strncpy(fila[fim].nome, nome, sizeof(fila[fim].nome));
    qtd++;

    printf("Paciente cadastrado com sucesso!\n");
}

Paciente dequeque() {
    Paciente paciente = {-1, ""};
    if (qtd == 0) {
        printf("Nenhum paciente na fila\n");
        return paciente;
    }

    paciente = fila[inicio];
    inicio = (inicio + 1) % MAX;
    qtd--;
    return paciente;
}

void mostrar_fila() {
    if (qtd == 0) {
        printf("Nenhum paciente na fila.\n");
    } else {
        printf("\n --- Lista de Pacientes ---\n");
        for (int i = 0; i < qtd; i++) {
            int idx = (inicio + i) % MAX;
            printf("[%d - %s] ", fila[idx].senha, fila[idx].nome);
        }
    }
}