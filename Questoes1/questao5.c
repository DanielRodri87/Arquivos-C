#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

void contarLetrasRepetidas(const char *texto, int *ocorrencias) {
    int tamanho = strlen(texto);

    for (int i = 0; i < tamanho; i++) {
        char caractere = tolower(texto[i]);

        if (isalpha(caractere)) {
            ocorrencias[caractere - 'a']++;
        }
    }
}

void lerArquivoTexto(const char *nomeArquivo, char *texto, int tamanhoMaximo) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(EXIT_FAILURE);
    }

    fgets(texto, tamanhoMaximo, arquivo);

    size_t tamanho = strlen(texto);
    if (tamanho > 0 && texto[tamanho - 1] == '\n') {
        texto[tamanho - 1] = '\0';
    }

    fclose(arquivo);
}

int main() {
    char nomeArquivo[100];
    char texto[1000];
    int ocorrencias[26] = {0}; 

    printf("Digite o nome do arquivo de texto: ");
    scanf("%s", nomeArquivo);

    lerArquivoTexto(nomeArquivo, texto, sizeof(texto));

    contarLetrasRepetidas(texto, ocorrencias);

    printf("Ocorrências de letras repetidas:\n");
    for (int i = 0; i < 26; i++) {
        if (ocorrencias[i] > 1) {
            printf("%c: %d vezes\n", 'a' + i, ocorrencias[i]);
        }
    }

    return 0;
}
