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

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

int findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root->data;
    }

    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Node* root = NULL;
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    printf("%d", findLCA(root, n1, n2));

    return 0;
}