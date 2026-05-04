#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct Node {
    int data;
    struct Node *left, *right;
};

struct Pair {
    struct Node* node;
    int hd;
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
    int f = 0, r = 0;

    struct Node* root = createNode(arr[0]);
    q[r++] = root;

    int i = 1;

    while (i < n) {
        struct Node* cur = q[f++];

        if (arr[i] != -1) {
            cur->left = createNode(arr[i]);
            q[r++] = cur->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            cur->right = createNode(arr[i]);
            q[r++] = cur->right;
        }
        i++;
    }

    free(q);
    return root;
}

void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    struct Pair q[MAX];
    int f = 0, r = 0;

    int hdArr[MAX], valArr[MAX];
    int count = 0;

    int min = 0, max = 0;

    q[r++] = (struct Pair){root, 0};

    while (f < r) {
        struct Pair p = q[f++];

        hdArr[count] = p.hd;
        valArr[count] = p.node->data;
        count++;

        if (p.hd < min) min = p.hd;
        if (p.hd > max) max = p.hd;

        if (p.node->left)
            q[r++] = (struct Pair){p.node->left, p.hd - 1};

        if (p.node->right)
            q[r++] = (struct Pair){p.node->right, p.hd + 1};
    }

    for (int line = min; line <= max; line++) {
        for (int i = 0; i < count; i++) {
            if (hdArr[i] == line)
                printf("%d ", valArr[i]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}