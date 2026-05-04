#include <stdio.h>

#define INF 1000000000

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[n + 1][n + 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int selected[n + 1];
    int key[n + 1];

    for (int i = 1; i <= n; i++) {
        selected[i] = 0;
        key[i] = INF;
    }

    key[1] = 0;
    int total = 0;

    for (int count = 1; count <= n; count++) {
        int min = INF;
        int vertex = -1;

        for (int i = 1; i <= n; i++) {
            if (!selected[i] && key[i] < min) {
                min = key[i];
                vertex = i;
            }
        }

        if (vertex == -1) {
            printf("-1");
            return 0;
        }

        selected[vertex] = 1;
        total += key[vertex];

        for (int i = 1; i <= n; i++) {
            if (!selected[i] && graph[vertex][i] < key[i]) {
                key[i] = graph[vertex][i];
            }
        }
    }

    printf("%d", total);

    return 0;
}