#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    FILE *arq;
    int i, num[10];

    arq = fopen("numeros.txt", "w");

    if(arq == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    for(i = 0; i < 10; i++){
        printf("Digite o %d numero: ", i+1);
        scanf("%d", &num[i]);
        fprintf(arq, "%d\n", num[i]);
    }

    arq = fopen("numeros.txt", "r");

    if(arq == NULL){
        printf("Erro na abertura do arquivo");
        exit(1);
    }

    for (i = 0; i < 10; i++){
        fscanf(arq, "%d", &num[i]);
        printf("%d\n", num[i]);
    }

    
    fclose(arq);
    getch();
    return 0;
}