#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex = v;
    node->next = NULL;
    return node;
}

void addEdge(struct Node* adj[], int u, int v) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;

    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

void dfs(struct Node* adj[], int visited[], int v) {
    visited[v] = 1;
    struct Node* temp = adj[v];

    while (temp) {
        if (!visited[temp->vertex])
            dfs(adj, visited, temp->vertex);
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n + 1];
    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[n + 1];
    for (int i = 1; i <= n; i++)
        visited[i] = 0;

    dfs(adj, visited, 1);

    int connected = 1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("CONNECTED");
    else
        printf("NOT CONNECTED");

    return 0;
}