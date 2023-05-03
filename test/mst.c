#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100 
#define INF INT_MAX 

typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX_VERTICES]; 
Edge edges[MAX_VERTICES];
int num_edges = 0; 


int find(int v) {
    if (parent[v] != v) {
        parent[v] = find(parent[v]);
    }
    return parent[v];
}


void union_sets(int u, int v) {
    parent[find(u)] = find(v);
}


int compare_edges(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->weight - e2->weight;
}


void mst(int n, int m, Edge* edges) {

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    qsort(edges, m, sizeof(Edge), compare_edges);

    for (int i = 0; i < m && num_edges < n - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            union_sets(u, v);
            edges[num_edges++] = edges[i];
        }
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }
    mst(n, m, edges);
    printf("The MST is:\n");
    for (int i = 0; i < num_edges; i++) {
        printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].weight);
    }
    return 0;
}