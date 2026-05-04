#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1000
#define INF 1000000000

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

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        adj[i] = NULL;

    int u, v, w;

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int source;
    scanf("%d", &source);

    int dist[n + 1];

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;
    push(source, 0);

    while (!isEmpty()) {
        struct HeapNode node = pop();
        int curr = node.vertex;

        if (node.dist != dist[curr])
            continue;

        struct Edge* temp = adj[curr];

        while (temp != NULL) {
            int next = temp->vertex;
            int weight = temp->weight;

            if (dist[curr] + weight < dist[next]) {
                dist[next] = dist[curr] + weight;
                push(next, dist[next]);
            }

            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            printf("-1 ");
        else
            printf("%d ", dist[i]);
    }

    return 0;
}