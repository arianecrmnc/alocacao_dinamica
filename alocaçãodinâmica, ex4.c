#include <stdio.h>
#include <stdlib.h>

void mostrar_itinerario(int *vet, int tam)
{
    int i;
    for(i=0; i<tam; i++)
        {
        printf("%d", vet[i]);
        }
    printf("\n");
}

void mostrar_matriz(int **matriz, int n_cidades)
{
    int i, j;
    for (i=0; i < n_cidades; i++)
        {
        for (j=0; j < n_cidades; j++)
        {
            printf("%d", matriz[i][j]);
        }
        printf("\n");
        }
    printf("\n");
}

int * criar_itinerario(int t_itinerario, int n_cidades)
{
    int i, *itinerario;
    itinerario = malloc(t_itinerario * sizeof (int));
    if(itinerario)
        {
        for(i=0; i<t_itinerario; i++)
            {
            itinerario[i] = rand() %n_cidades;
            }
        }
    mostrar_itinerario(itinerario, t_itinerario);

    return itinerario;
}

int * aloca_matriz(int n_cidades)
{
    int i, j, valor, **precos;
    precos = malloc (n_cidades * sizeof (int*));
    for (i=0; i < n_cidades; i++)
        precos[i] = malloc (n_cidades * sizeof (int));

    for (i=0; i < n_cidades; i++)
        {
        for (j = 0; j < n_cidades; j++)
            {
            printf("digite o valor para a viagem entre %d e %d:", i, j);
            scanf("%d", &valor);
            precos[i][j] = valor;
            }
        }
    return precos;
}

int custo_cidades (int* cidades, int n_cidades, int** m)
{
    int i, total;
    for(i = 0; i<n_cidades; i++)
        {
        if(i+1 == n_cidades)
            break;
        printf("de %d para %d \n", cidades[i], cidades[i+1]);
        printf("valor = %d \n", m[cidades[i]][cidades[i+1]]);
        total += m[cidades[i]][cidades[i+1]];
        }
    return total;
}

int main()
    {
    int i, total, *itinerario, t_itinerario, n_cidades, **m;

    printf("digite o numero de cidades:");
    scanf("%d", &n_cidades);
    m = aloca_matriz(n_cidades);
    mostrar_matriz(m, n_cidades);

    printf("digite o numero de viagens a serem feitas:");
    scanf("%d", &t_itinerario);
    printf("o itinerario eh: \n");
    itinerario = criar_itinerario(t_itinerario, n_cidades);

    total = custo_cidades(itinerario, t_itinerario, m);
    printf("o total eh %d", total);

    return 0;
}

