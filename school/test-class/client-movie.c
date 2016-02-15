#include <stdio.h>

int main()
{

    char name[8][30];
    int totalMovie[8];
    int totalFreeMovie[8];
    int i;

    for(i=0; i < 8; i++){
        printf("Insira o nome: ");
        gets(name[i]);

        printf("\nPlease, insert the total movie:");
        scanf("%d", &totalMovie[i]);

        totalFreeMovie[i] = (totalMovie[i] * 1/10);
    }

    for(i = 0;i < 8;i++)
    {
        printf("\n Nome do cliente: ");
        pusts(name[i]);

        printf("\nTotal de filmes alocados: %d", totalMovie[i]);
        printf("\nTotal de filmes gratuidos para alocar: %d", totalFreeMovie[i]);

    }


}
