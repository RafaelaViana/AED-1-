#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[200001];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int x, int y) {
    parent[find(x)] = find(y);
}

int cmp(const void *a, const void *b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}

int main() {
    int m, n;
    
    while (scanf("%d %d", &m, &n), m || n) {
        Edge edges[n];
        int totalCost = 0, savedCost = 0;

        for (int i = 0; i < m; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            totalCost += edges[i].w;
        }

        qsort(edges, n, sizeof(Edge), cmp);

        int mstCost = 0, edgesUsed = 0;

        for (int i = 0; i < n && edgesUsed < m - 1; i++) {
            if (find(edges[i].u) != find(edges[i].v)) {
                unite(edges[i].u, edges[i].v);
                mstCost += edges[i].w;
                edgesUsed++;
            }
        }

        savedCost = totalCost - mstCost;
        printf("%d\n", savedCost);
    }

    return 0;
}
