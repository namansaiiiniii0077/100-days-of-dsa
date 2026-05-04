#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node** q = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;

    struct Node* root = createNode(arr[0]);
    q[rear++] = root;

    int i = 1;

    while (i < n) {
        struct Node* cur = q[front++];

        if (arr[i] != -1) {
            cur->left = createNode(arr[i]);
            q[rear++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = createNode(arr[i]);
            q[rear++] = cur->right;
        }
        i++;
    }

    free(q);
    return root;
}

void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node** q = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;
    int leftToRight = 1;

    q[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int temp[levelSize];

        for (int i = 0; i < levelSize; i++) {
            struct Node* cur = q[front++];

            int index;
            if (leftToRight)
                index = i;
            else
                index = levelSize - 1 - i;

            temp[index] = cur->data;

            if (cur->left)
                q[rear++] = cur->left;

            if (cur->right)
                q[rear++] = cur->right;
        }

        for (int i = 0; i < levelSize; i++)
            printf("%d ", temp[i]);

        leftToRight = !leftToRight;
    }

    free(q);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    zigzagTraversal(root);

    return 0;
}