#include <stdio.h>
#include <string.h>
 
#define MAX_CONTAS 100

typedef struct {

    int numero;
    char nome[50];
    float saldo;
    int ativa;
} Conta;

Conta banco[MAX_CONTAS];
int totalC = 0;

void criar_conta() {
    if (totalC >= MAX_CONTAS) {
        printf("Banco cheio!\n");
        return;
    }

    Conta *c = &banco[totalC];
    c -> numero = totalC + 1;
    c -> ativa = 1;
    c -> saldo = 0.0;

    printf("Nome do titular: ");
    scanf(" %[\n]", c ->nome);

    totalC++;

    printf("Conta %d criada para %s!\n", c->numero, c->nome);

}

Conta* buscarC(int numero){
    for (int i = 0; i < totalC; i++) {
        if (banco[i].numero == numero && banco[i].ativa)
        return &banco[i];
    }
    return NULL;
}

void deletarC(){
    int num;
    printf("Numero da conta a deletar: ");
    scanf("%d", &num);

    Conta *c = buscarC(num);
    if (!c) {
        printf("Conta nao encontrada! \n");
        return;
    }

    c -> ativa = 0;
    printf("Conta %d de %s Inativa Com Sucesso!", c->numero, c->nome);
}
