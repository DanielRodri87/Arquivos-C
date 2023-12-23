#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>

typedef struct {
    char nome[100];
    int dia, mes, ano;
} Pessoa;

void calcularIdade(Pessoa *pessoa, int *idadeAtual, int *idadeProxima);

void lerArquivoEntrada(const char *nomeArquivo, Pessoa *pessoas, int *totalPessoas);

void criarArquivoSaida(const char *nomeArquivo, Pessoa *pessoas, int totalPessoas);

int main() {
    char nomeArquivoEntrada[100];
    char nomeArquivoSaida[100];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada);

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeArquivoSaida);

    Pessoa pessoas[100]; 
    int totalPessoas = 0;

    lerArquivoEntrada(nomeArquivoEntrada, pessoas, &totalPessoas);

    criarArquivoSaida(nomeArquivoSaida, pessoas, totalPessoas);

    printf("Arquivo criado com sucesso!\n");

    return 0;
}

void calcularIdade(Pessoa *pessoa, int *idadeAtual, int *idadeProxima) {
    time_t agora;
    time(&agora);

    struct tm *dataNascimento = localtime(&agora);
    dataNascimento->tm_year = pessoa->ano - 1900;
    dataNascimento->tm_mon = pessoa->mes - 1;
    dataNascimento->tm_mday = pessoa->dia;

    time_t nascimento = mktime(dataNascimento);
    double diferencaSegundos = difftime(agora, nascimento);

    *idadeAtual = diferencaSegundos / (60 * 60 * 24 * 365.25);
    *idadeProxima = *idadeAtual + 1;
}

void lerArquivoEntrada(const char *nomeArquivo, Pessoa *pessoas, int *totalPessoas) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        exit(EXIT_FAILURE);
    }

    while (fscanf(arquivo, "%s %d/%d/%d", pessoas[*totalPessoas].nome,
                  &pessoas[*totalPessoas].dia, &pessoas[*totalPessoas].mes, &pessoas[*totalPessoas].ano) == 4) {
        (*totalPessoas)++;
    }

    fclose(arquivo);
}

void criarArquivoSaida(const char *nomeArquivo, Pessoa *pessoas, int totalPessoas) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de saida.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < totalPessoas; i++) {
        int idadeAtual, idadeProxima;
        calcularIdade(&pessoas[i], &idadeAtual, &idadeProxima);

        fprintf(arquivo, "Nome: %s, Idade Atual: %d anos, Idade Proxima: %d anos\n",
                pessoas[i].nome, idadeAtual, idadeProxima);
    }

    fclose(arquivo);
}
