#include <stdio.h>
#include <string.h>

#define MAXN 10005
#define MAXM 30005

int head[MAXN];
int to[MAXM];
int next_edge[MAXM];
int edge_count;
int vis[MAXN];

void init_graph(int n) {
    edge_count = 0;
    memset(head, -1, (n + 1) * sizeof(int));
    memset(vis, 0, (n + 1) * sizeof(int));
}

void add_edge(int u, int v) {
    to[edge_count] = v;
    next_edge[edge_count] = head[u];
    head[u] = edge_count++;
}

int dfs_ciclo(int u) {
    vis[u] = 1;

    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to[e];
        if (vis[v] == 1) return 1;
        if (vis[v] == 0) {
            if (dfs_ciclo(v)) return 1;
        }
    }

    vis[u] = 2;
    return 0;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        init_graph(N);

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        int tem_loop = 0;
        for (int i = 1; i <= N; i++) {
            if (vis[i] == 0) {
                if (dfs_ciclo(i)) {
                    tem_loop = 1;
                    break;
                }
            }
        }

        if (tem_loop) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
