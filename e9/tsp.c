#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define INF 9999999
#define V 4

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
    ncity = min(city);

    if (ncity == 999)
    {
        ncity = 0;
        cost += adjG[city][ncity];
        return;
    }
    tsp(ncity);
}

void mst()
{
    int no_edge;
    int selected[V];

    memset(selected, false, sizeof(selected));

    no_edge = 0;

    int sel[10];
    int selz[10];

    selected[0] = true;

    int x;
    int y;
    int z = 0;
    int zo = 0;
    while (no_edge < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for (int i = 0; i < V; i++)
        {
            if (selected[i])
            {
                for (int j = 0; j < V; j++)
                {
                    if (!selected[j] && adjG[i][j])
                    {
                        if (min > adjG[i][j])
                        {
                            min = adjG[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        sel[z] = x + 1;
        selz[zo] = y + 1;
        z++;
        zo++;
        selected[y] = true;
        no_edge++;
    }
    sel[z] = sel[0];
    z++;
    for (int i = 0; i < z; i++)
    {
        if (i == zo)
            printf("%d -> %d", selz[zo - 1], sel[i]);
        else
            printf("%d -> ", sel[i]);
    }
}

int main()
{
    userInput();
    printf("\nRoute:\n");
    mst();
    tsp(0);
    printf("\n\nMinimum cost is %d\n", cost);
    return 0;
}
// 0 4 1 3
// 4 0 2 1
// 1 2 0 5
// 3 1 5 0