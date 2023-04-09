#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int sV)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mDis, nV, i, j;
    int t = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = graph[i][j];
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[sV][i];
        pred[i] = sV;
        visited[i] = 0;
    }
    distance[sV] = 0;
    visited[sV] = 1;
    count = 1;
    while (count < n - 1)
    {
        mDis = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mDis && !visited[i])
            {
                mDis = distance[i];
                nV = i;
            }
        visited[nV] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mDis + cost[nV][i] < distance[i])
                {
                    distance[i] = mDis + cost[nV][i];
                    pred[i] = nV;
                }
        count++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i != sV)
        {
            printf("\n%d<->%d: %d", sV, i, distance[i]);
            if (i == n - 1)
            {
                printf("\nPath: %d", i);
                j = i;
                while (j != sV)
                {
                    j = pred[j];
                    printf("<-%d", j);
                }
            }
        }
    }
}

int main()
{
    int graph[MAX][MAX], i, j, n, u;
    printf("No. of vertices: ");
    scanf("%d", &n);
    printf("\nAdjacency matrix: \n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    printf("\nStarting vertex: ");
    scanf("%d", &u);
    dijkstra(graph, n, u);

    return 0;
}