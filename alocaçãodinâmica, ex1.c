#include <stdio.h>
#include <stdlib.h>

int * cria_vetor(int tam, int lim)
{
    int i, *vet;
    vet = malloc(tam * sizeof (int));
    if(vet)
    {
        for(i=0; i<tam; i++)
        {
            vet[i] = rand() %lim;
        }
    }
    return vet;
}

int * expande_vetor(int *v, int tam, int n, int lim)
{
    int *vet, i;
    vet = realloc(v, tam);
    if(vet){
        for(i=n; i<tam; i++)
            {
            vet[i] = rand() %lim;
            }
    }
    return vet;
}

int main()
{
    int *vetor, tam, lim, i;

    printf("digite o tamanho do vetor:");
    scanf("%d", &tam);
    printf("digite o limite dos valores:");
    scanf("%d", &lim);
    vetor = cria_vetor(tam, lim);
    for(i=0; i<tam; i++)
        {
        printf("%d ", vetor[i]);
        }

    printf("digite o novo tamanho do vetor:");
    scanf("%d", &tam);
    vetor = expande_vetor(vetor, tam, i, lim);
    for(i=0; i<tam; i++)
    {
        printf("%d", vetor[i]);
    }

    return 0;
}

