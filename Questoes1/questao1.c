#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

FILE *abrirArquivo(const char *nomeArquivo, const char *modo);
void fecharArquivo(FILE *arq);
void contarLetras(FILE *arq);

int main()
{
    FILE *arq;
    char palavra[100];

    arq = abrirArquivo("bd1.txt", "w+");

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }


    printf("Digite uma palavra: ");
    gets(palavra);

    fprintf(arq, "%s", palavra);

    fecharArquivo(arq);

    arq = abrirArquivo("bd1.txt", "r");

    if (arq == NULL)
    {
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    contarLetras(arq);

    fecharArquivo(arq);

    return 0;
}

FILE *abrirArquivo(const char *nomeArquivo, const char *modo)
{
    FILE *arq = fopen(nomeArquivo, modo);
    return arq;
}

void fecharArquivo(FILE *arq)
{
    fclose(arq);
}

void contarLetras(FILE *arq)
{
    
    char c;
    int cont = 0;

    while ((c = fgetc(arq)) != EOF)
    {
        cont++;
    }

    printf("A palavra possui %d letras", cont);
}
