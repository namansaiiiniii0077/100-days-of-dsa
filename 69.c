#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000
#define INF INT_MAX

struct Edge {
    int vertex;
    int weight;
    struct Edge* next;
};

struct HeapNode {
    int vertex;
    int dist;
};

struct Edge* adj[MAX];
struct HeapNode heap[MAX * MAX];
int heapSize = 0;

struct Edge* createEdge(int v, int w) {
    struct Edge* edge = (struct Edge*)malloc(sizeof(struct Edge));
    edge->vertex = v;
    edge->weight = w;
    edge->next = NULL;
    return edge;
}

void addEdge(int u, int v, int w) {
    struct Edge* edge = createEdge(v, w);
    edge->next = adj[u];
    adj[u] = edge;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void push(int vertex, int dist) {
    heap[heapSize].vertex = vertex;
    heap[heapSize].dist = dist;

    int i = heapSize;
    heapSize++;

    while (i > 0 && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    int i = 0;

    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;

        if (right < heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return root;
}

int isEmpty() {
    return heapSize == 0;
}

void dijkstra(int n, int source) {
    int dist[MAX];

    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while (!isEmpty()) {
        struct HeapNode node = pop();
        int u = node.vertex;
        int d = node.dist;

        if (d != dist[u])
            continue;

        struct Edge* temp = adj[u];

        while (temp != NULL) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }

            temp = temp->next;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    return 0;
}