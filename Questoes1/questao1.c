#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int main()
{
    FILE *arq;
    char palavra[100];
    arq = fopen("bd1.txt", "w+");

    if(arq == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }
    
    printf("Digite uma palavra: ");
    gets(palavra);
    fprintf(arq, "%s", palavra);
    fclose(arq);

    arq = fopen("bd1.txt", "r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    char c;
    int cont = 0;
    
    while((c = fgetc(arq)) != EOF){
        cont++;
    }
    printf("A palavra possui %d letras", cont);
    fclose(arq);
    return 0;
}