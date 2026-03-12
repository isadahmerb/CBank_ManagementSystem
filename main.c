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

void lb(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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

    void depositar(){
        int num; float valor;
        printf("Numero da conta: ");
        scanf("%d", &num);
        Conta *c = buscarC(num);
        if (!c) {
            printf("Conta nao encontrada! \n");
            return;
        }
        printf("Valor para depositar: R$ ");
        scanf("%f", &valor);
            if (valor <= 0) {
                printf("VALOR INVALIDO! \n");
                return;
            }
        c -> saldo += valor;
        printf("Deposito de R$ %.2f. Saldo de R$ %.2f \n", valor, c->saldo);
    }

    void sacar() {
        int num; float valor;
        printf("Numero da conta: ");
        scanf("%d", &num);
        Conta *c = buscarC(num);
            if (!c) {
                printf("CONTA NAO ENCONTRADA! \n");
                return;
            }
        printf("Valor para sacar: R$ ");
        scanf("%f", &valor);
            if( valor <= 0){
                printf("VALOR INVALIDO! \n");
                return;
            }
            if (valor > c->saldo) {
                printf("SALDO INSUFICIENTE!! \n");
                return;
            }

            c->saldo -= valor;
            printf("Saque de R$ %.2f. Saldo: R$ %.2f\n", valor, c->saldo);
    }

        void transferir(){
            int origem, destino;
            float valor;

            printf("Conta de Origem: ");
            scanf("%d", &origem);

            printf("Conta de Destino: ");
            scanf("%d", &destino);

            Conta *co = buscarC(origem);
            Conta *cd = buscarC(destino);

            if ( !co || !cd) {
                printf("CONTA NAO ENCONTRADA!  \n");
                return;
            }

            printf("Valor: R$ ");
            scanf("%f", &valor);

                if (valor <= 0) {
                    printf("VALOR INVALIDO! \n");
                    return;
                }
                if (valor > co->saldo) {
                    printf("SALDO INSUFICIENTE! \n");
                    return;
                }

                co ->saldo -= valor;
                cd ->saldo += valor;

                printf("R$ %.2f transferidos de %s para %s\n ", valor, co->nome, cd->nome);
        }

            void listarC(){
                printf("\n----Contas Ativas----\n");
                int achou = 0;
                for (int i= 0; i < totalC; i++){
                    if (banco[i].ativa) {
                        printf("  [%d] %s --- R$ %.2f\n",
                                banco[i].numero, banco[i].nome, banco[i].saldo);
                            achou = 1;
                    }
                }

                if (!achou) {
                    printf("NENHUMA CONTA CADASTRADA \n");
                }
            }

            int main(){
                int opcao;

                do {
                    printf("\n=========BANK C=========\n");
                    printf("1. Criar Conta \n");
                    printf("2. Deletar Conta \n");
                    printf("3. Depositar \n");
                    printf("4. Sacar \n");
                    printf("5. Trasnferir \n");
                    printf("6. Listar Contas: \n");
                    printf("0. Sair\n");
                    printf("Opcao: ");
                    scanf("%d", &opcao);
                    while(getchar() != '\n');

                    switch(opcao) {
                        case 1: criar_conta(); break;
                        case 2: deletarC(); break;
                        case 3: depositar(); break;
                        case 4: sacar(); break;
                        case 5: transferir(); break;
                        case 6: listarC(); break;
                        case 0: printf("Encerrando... \n"); break;
                        default: printf("Opcao INVALIDA! \n");
                    }
                } while (opcao != 0);
                
                return 0;
            }