/*  Criar um menu ok
1. cadastrar paciente ok
2. chamar paciente
3. lista de pacientes
4. sair
 
Cada paciente tem uma senha e será chamado pela sua senha;
A cada chamada o primeiro paciente é removido da fila*/

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

int main() {
    int opcao;
    char nome[50];
    Paciente paciente;

    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar paciente\n");
        printf("2. Chamar paciente\n");
        printf("3. Lista de pacientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
            printf("\n=== Cadastrar Paciente ===\n");
            printf("Digite o nome do paciente: ");
            scanf("%s", nome);

            enqueque(nome);
            printf("Paciente %s cadastrado com a senha %d\n", nome, fila[fim].senha);
            break;
            case 2:
            printf("\n=== Chamando Paciente ===\n");
            paciente = dequeque();
            if (paciente.senha != -1) {
                printf("Paciente chamado: %s (Senha: %d)\n", paciente.nome, paciente.senha);
            }
                break;
            case 3:
            mostrar_fila();          
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 4);

    
    return 0;
}