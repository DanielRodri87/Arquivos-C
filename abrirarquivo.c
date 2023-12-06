#include <stdio.h>
#include <conio.h>

int main(void)
{
    FILE * fp;
    fp = fopen("output/arquivo.txt", "r");
    if (fp == NULL)
    {
        printf("Erro ao tentar abrir o arquivo\n");
    }

    char nome[20];
    int dia, mes, ano, idade;

    fscanf(fp, "%s %d %d %d %d", nome, &idade, &dia, &mes, &ano);
    printf("Nome: %s\n", nome);
    printf("Idade: %d\n", idade);
    printf("Data de nascimento: %d/%d/%d\n", dia, mes, ano);

    return 0;
}