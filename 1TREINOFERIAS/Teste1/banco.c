#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarConta(FILE *arq);
void realizarLogin(FILE *arq);
void depositar(FILE *arq);

int main()
{
    FILE *arq;
    int op;

    while (1)
    {
        arq = fopen("arquivo.txt", "a+");

        if (arq == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

        printf("MENU DO BANCO\n1 - Criar conta\n2 - Login\n3 - Depositar\n9 - Sair\n--> ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            criarConta(arq);
            break;

        case 2:
            realizarLogin(arq);
            break;
        
        case 3:
            depositar(arq);
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

void criarConta(FILE *arq)
{
    char criarSenha[100], criarSenha2[100], criarUser[100];

    printf("Informe seu usuário: ");
    scanf("%s", criarUser);
    printf("Informe sua senha: ");
    scanf("%s", criarSenha);
    printf("Informe novamente a sua senha: ");
    scanf("%s", criarSenha2);

    switch (strcmp(criarSenha, criarSenha2))
    {
    case 0:
        fprintf(arq, "%s %s %f\n", criarUser, criarSenha, 0.0);
        printf("Conta criada com sucesso!\n");
        break;

    default:
        printf("Senhas distintas. Tente novamente.\n");
        break;
    }
}

void realizarLogin(FILE *arq)
{
    char senhalogin[100], userlogin[100];
    int oplogin;
    printf("Possui conta aqui? 1 - Sim | 2 - Não: ");
    scanf("%d", &oplogin);
    if (oplogin == 1)
    {
        printf("Informe o seu usuário: ");
        scanf("%s", userlogin);
        printf("Informe a sua senha: ");
        scanf("%s", senhalogin);

        fseek(arq, 0, SEEK_SET);

        int encontrado = 0;
        char usuarioArquivo[100], senhaArquivo[100];

        while (fscanf(arq, "%s %s", usuarioArquivo, senhaArquivo) == 2)
        {
            if (strcmp(usuarioArquivo, userlogin) == 0 && strcmp(senhaArquivo, senhalogin) == 0)
            {
                encontrado = 1;
                break;
            }
        }

        switch (encontrado)
        {
        case 1:
            printf("Login bem-sucedido!\n");
            break;

        default:
            printf("Usuário ou senha incorretos. Tente novamente.\n");
            break;
        }
    } else
    {
        printf("Crie sua conta\n");
        criarConta(arq);
    }
}

void depositar(FILE *arq)
{
    char usuario[100];
    float valor;

    printf("Informe o seu usuário: ");
    scanf("%s", usuario);

    fseek(arq, 0, SEEK_SET);

    int encontrado = 0;
    char usuarioArquivo[100], senhaArquivo[100];
    float saldoArquivo;

    while (fscanf(arq, "%s %s %f", usuarioArquivo, senhaArquivo, &saldoArquivo) == 3)
    {
        if (strcmp(usuarioArquivo, usuario) == 0)
        {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
    {
        printf("Informe o valor a ser depositado: ");
        scanf("%f", &valor);

        fseek(arq, -sizeof(float), SEEK_CUR);
        fprintf(arq, " %f\n", saldoArquivo + valor);

        printf("Depósito realizado com sucesso!\n");
    }
    else
    {
        printf("Usuário não encontrado. Operação de depósito cancelada.\n");
    }
}
