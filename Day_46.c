#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Queue {
    struct Node* arr[1000];
    int front, rear;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front > q->rear;
}

void enqueue(struct Queue* q, struct Node* node) {
    q->arr[++q->rear] = node;
}

struct Node* dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

void levelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        struct Node* temp = dequeue(&q);
        printf("%d ", temp->data);

        if (temp->left != NULL) {
            enqueue(&q, temp->left);
        }
        if (temp->right != NULL) {
            enqueue(&q, temp->right);
        }
    }
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

    levelOrder(nodes[0]);

    return 0;
}