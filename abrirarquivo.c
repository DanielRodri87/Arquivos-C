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

    int ano;

    fscanf(fp, "daniel 18 26 05 2005", &ano);
    printf("Data de nascimento: %d\n", ano);

    return 0;
}