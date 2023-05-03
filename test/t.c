#include <stdio.h>

int adjG[10][10], visited[10], n, cost = 0;

int min(int c)
{
    int i, nc = 999;
    int min = 999, kmin;

    for (i = 0; i < n; i++)
    {
        if ((adjG[c][i] != 0) && (visited[i] == 0))
            if (adjG[c][i] + adjG[i][c] < min)
            {
                min = adjG[i][0] + adjG[c][i];
                kmin = adjG[c][i];
                nc = i;
            }
    }

    if (min != 999)
        cost += kmin;

    return nc;
}

void userInput()
{
    int i, j;

    printf("Number of villages: ");
    scanf("%d", &n);

    printf("\nAdjacency Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &adjG[i][j]);

        visited[i] = 0;
    }
}

void tsp(int city)
{
    int i, ncity;

    visited[city] = 1;

    printf("%d->", city + 1);
    ncity = min(city);

    if (ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += adjG[city][ncity];
        return;
    }
    tsp(ncity);
}

int main()
{
    userInput();
    int sV;
    printf("\nStarting Vertex: ");
    scanf("%d", &sV);
    printf("\nRoute:\n");
    tsp(sV-1);
    printf("\n\nMinimum cost is %d\n ", cost);
    return 0;
}