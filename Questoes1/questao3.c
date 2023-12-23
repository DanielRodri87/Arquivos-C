#include <stdio.h>
#include <stdlib.h>

void mesclarArquivos(const char *nomeArquivo1, const char *nomeArquivo2, const char *nomeArquivoSaida);

int main()
{
    char nomeArquivoEntrada1[100];
    char nomeArquivoEntrada2[100];
    char nomeArquivoSaida[100];

    printf("Digite o nome do primeiro arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada1);

    printf("Digite o nome do segundo arquivo de entrada: ");
    scanf("%s", nomeArquivoEntrada2);

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeArquivoSaida);

    mesclarArquivos(nomeArquivoEntrada1, nomeArquivoEntrada2, nomeArquivoSaida);

    printf("Arquivo criado com sucesso!\n");

    return 0;
}

void mesclarArquivos(const char *nomeArquivo1, const char *nomeArquivo2, const char *nomeArquivoSaida)
{
    FILE *arquivo1 = fopen(nomeArquivo1, "r");
    FILE *arquivo2 = fopen(nomeArquivo2, "r");
    FILE *arquivoSaida = fopen(nomeArquivoSaida, "w");

    if (arquivo1 == NULL || arquivo2 == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(EXIT_FAILURE);
    }

    char linha1[1000];
    char linha2[1000];

    while (fgets(linha1, sizeof(linha1), arquivo1) != NULL || fgets(linha2, sizeof(linha2), arquivo2) != NULL) {
        if (linha1[0] != '\0') {
            fputs(linha1, arquivoSaida);
            linha1[0] = '\0'; 
        }

        if (linha2[0] != '\0') {
            fputs(linha2, arquivoSaida);
            linha2[0] = '\0'; 
        }
    }

    fclose(arquivo1);
    fclose(arquivo2);
    fclose(arquivoSaida);
}
