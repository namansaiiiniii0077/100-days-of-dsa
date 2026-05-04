#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

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

void addEdge(struct Node* adj[], int u, int v, int indegree[]) {
    struct Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
    indegree[v]++;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    int indegree[n];

    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        indegree[i] = 0;
    }

    int u, v;

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v, indegree);
    }

    int queue[MAX], front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[++rear] = i;
    }

    int count = 0;

    while (front <= rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        count++;

        struct Node* temp = adj[curr];

        while (temp != NULL) {
            indegree[temp->vertex]--;

            if (indegree[temp->vertex] == 0)
                queue[++rear] = temp->vertex;

            temp = temp->next;
        }
    }

    if (count != n)
        printf("\nCycle exists");

    return 0;
}