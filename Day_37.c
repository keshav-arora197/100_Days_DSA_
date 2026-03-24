#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert element
void insert(int x) {
    if (size == MAX) {
        return;
    }
    pq[size++] = x;
}

// Delete highest priority element (smallest value)
void deleteElement() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    printf("%d\n", pq[minIndex]);

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek highest priority element
void peek() {
    if (size == 0) {
        printf("-1\n");
        return;
    }

    int minValue = pq[0];
    for (int i = 1; i < size; i++) {
        if (pq[i] < minValue) {
            minValue = pq[i];
        }
    }

    printf("%d\n", minValue);
}

int main() {
    int N, x;
    char op[20];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            deleteElement();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}