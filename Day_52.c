#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* findLCA(struct Node* root, int n1, int n2) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n1 || root->data == n2) {
        return root;
    }

    struct Node* leftLCA = findLCA(root->left, n1, n2);
    struct Node* rightLCA = findLCA(root->right, n1, n2);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }

    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    if (arr[0] == -1) {
        return 0;
    }

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            nodes[i] = NULL;
        } else {
            nodes[i] = createNode(arr[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n) {
                nodes[i]->left = nodes[leftIndex];
            }
            if (rightIndex < n) {
                nodes[i]->right = nodes[rightIndex];
            }
        }
    }

    struct Node* lca = findLCA(nodes[0], n1, n2);

    if (lca != NULL) {
        printf("%d", lca->data);
    }

    return 0;
}