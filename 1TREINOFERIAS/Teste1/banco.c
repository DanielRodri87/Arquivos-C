#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_USUARIO 100
#define MAX_SENHA 100

typedef struct {
    char usuario[MAX_USUARIO];
    char senha[MAX_SENHA];
    float saldo;
} Conta;

void criarConta(FILE *arq);
void realizarLogin(FILE *arq);
void depositar(FILE *arq);
void consultarsaudo(FILE *arq);


int main()
{
    FILE *arq;
    int op;

    while (1) {
        arq = fopen("arquivo.txt", "r+");

        if (arq == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        printf("MENU DO BANCO\n1 - Criar conta\n2 - Login\n3 - Depositar\n4 - Consultar saldo\n9 - Sair\n--> ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                criarConta(arq);
                break;

            case 2:
                realizarLogin(arq);
                break;

            case 3:
                depositar(arq);
                break;
            
            case 4:
                consultarsaudo(arq);
                break;

            case 9:
                fclose(arq);
                return 0;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        fclose(arq);
    }

    return 0;
}

void lerSenha(char *senha, int tamanho)
{
    int i = 0;
    char ch;

    while (1)
    {
        ch = getch();


        if (ch == 13)
            break;

        printf("*");

        senha[i] = ch;
        i++;

        if (i == tamanho - 1)
            break;
    }

    senha[i] = '\0';
}

void criarConta(FILE *arq)
{
    Conta novaConta;

    printf("Informe seu usuário: ");
    scanf("%s", novaConta.usuario);

    printf("Informe sua senha: ");
    lerSenha(novaConta.senha, MAX_SENHA);
    printf("\n");

    fprintf(arq, "%s %s %d\n", novaConta.usuario, novaConta.senha, 0);
    printf("Conta criada com sucesso!\n");
}

void realizarLogin(FILE *arq)
{
    int oplogin;
    printf("Possui conta aqui? 1 - Sim | 2 - Não: ");
    scanf("%d", &oplogin);

    if (oplogin == 1)
    {
        Conta loginConta;
        printf("Informe o seu usuário: ");
        scanf("%s", loginConta.usuario);

        printf("Informe a sua senha: ");
        lerSenha(loginConta.senha, MAX_SENHA);
        printf("\n");

        fseek(arq, 0, SEEK_SET);

        Conta arquivoConta;

        while (fscanf(arq, "%s %s %f", arquivoConta.usuario, arquivoConta.senha, &arquivoConta.saldo) == 3)
        {
            if (strcmp(arquivoConta.usuario, loginConta.usuario) == 0 &&
                strcmp(arquivoConta.senha, loginConta.senha) == 0)
            {
                printf("Login bem-sucedido!\n");
                return;
            }
        }

        printf("Usuário ou senha incorretos. Tente novamente.\n");
    } else
    {
        printf("Crie sua conta\n");
        criarConta(arq);
    }
}

void depositar(FILE *arq) {
    char usuario[MAX_USUARIO];
    float valor;

    printf("Informe o seu usuário: ");
    scanf("%s", usuario);

    fseek(arq, 0, SEEK_SET); //Lembre-se Daniel, isso volta para o início do arquivo

    Conta conta;

    while (fscanf(arq, "%s %s %f", conta.usuario, conta.senha, &conta.saldo) == 3)
    {
        if (strcmp(conta.usuario, usuario) == 0)
        {
            printf("Informe o valor a ser depositado: ");
            scanf("%f", &valor);

            fseek(arq, -sizeof(float), SEEK_CUR);
            fprintf(arq, " %.2f\n", conta.saldo + valor);

            printf("Depósito realizado com sucesso!\n");
            return;
        }
    }

    printf("Usuário não encontrado. Operação de depósito cancelada.\n");
}

void consultarsaudo(FILE *arq)
{
    // peço o usuario e a senha para verificar o saudo no arquivo.txt
    char usuario[MAX_USUARIO];
    char senha[MAX_SENHA];
    float saldo;

    printf("Informe o seu usuário: ");
    scanf("%s", usuario);

    printf("Informe a sua senha: ");
    lerSenha(senha, MAX_SENHA);
    printf("\n");

    fseek(arq, 0, SEEK_SET); //Lembre-se Daniel, isso volta para o início do arquivo

    Conta conta;

    while (fscanf(arq, "%s %s %f", conta.usuario, conta.senha, &conta.saldo) == 3)
    {
        if (strcmp(conta.usuario, usuario) == 0)
        {
            printf("Seu saldo é: %.2f\n", conta.saldo);
            return;
        }
        else 
            printf("Usuário não encontrado. Operação de consulta de saldo cancelada.\n");
    }
}
