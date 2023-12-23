#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void inverterString(char *str);
void criarArquivoInvertido(const char *nomeArquivoEntrada, const char *nomeArquivoSaida);

int main()
{
    char nomeArquivoEntrada[100] = "b2.txt";
    char nomeArquivoSaida[100] = "b2saida.txt";

    criarArquivoInvertido(nomeArquivoEntrada, nomeArquivoSaida);

    printf("Arquivo criado com sucesso!\n");

    return 0;
}

void inverterString(char *str)
{
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        char temp = str[inicio];
        str[inicio] = str[fim];
        str[fim] = temp;

        inicio++;
        fim--;
    }
}

void criarArquivoInvertido(const char *nomeArquivoEntrada, const char *nomeArquivoSaida)
{
    FILE *arquivoEntrada = fopen(nomeArquivoEntrada, "r");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(EXIT_FAILURE);
    }

    char linha[1000]; 

    while (fgets(linha, sizeof(linha), arquivoEntrada) != NULL) {
        inverterString(linha);
        
        fputs(linha, arquivoSaida);
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}

