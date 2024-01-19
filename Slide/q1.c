#include <stdio.h>
#include <stdlib.h>

int main()
{
    float nota1, nota2, nota3, media;
    char nome[100];
    FILE *arq;

    printf("Digite o seu nome: ");
    scanf("%s", nome);

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);

    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    media = (nota1 + nota2 + nota3) / 3;

    arq = fopen("notas.txt", "w+");

    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(arq, "%s %.2f\n", nome, media);

    // Neném, não sei se você já viu isso, mas é uma função que "rebobina" o arquivo. Eu leio o arquivo, e depois de ler, eu volto para o início dele.  
    rewind(arq); 

    char nomeArquivo[100];
    float mediaArquivo;

    fscanf(arq, "%s %f", nomeArquivo, &mediaArquivo);

    printf("Nome: %s\n", nomeArquivo);
    printf("Média: %.2f\n", mediaArquivo);

    if (mediaArquivo >= 7)
    {
        printf("Aprovado!\n");
    }
    else if (mediaArquivo < 4)
    {
        printf("Reprovado!\n");
    }
    else
    {
        printf("Avaliação final!\n");
    }

    fclose(arq);

    return 0;
}
