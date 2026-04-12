#include <stdio.h>
#include <string.h>

#define SIZE 100

int hashTable[SIZE];
int m;

// Initialize table
void init() {
    for(int i = 0; i < m; i++)
        hashTable[i] = -1;
}

// Insert using Quadratic Probing
void insert(int key) {
    int index = key % m;

    for(int i = 0; i < m; i++) {
        int newIndex = (index + i*i) % m;

        if(hashTable[newIndex] == -1) {
            hashTable[newIndex] = key;
            return;
        }
    }
}

// Search using Quadratic Probing
void search(int key) {
    int index = key % m;

    for(int i = 0; i < m; i++) {
        int newIndex = (index + i*i) % m;

        if(hashTable[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if(hashTable[newIndex] == -1) {
            printf("NOT FOUND\n");
            return;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int n;
    scanf("%d", &m);
    scanf("%d", &n);

    init();

    char op[10];
    int key;

    for(int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if(strcmp(op, "INSERT") == 0)
            insert(key);
        else if(strcmp(op, "SEARCH") == 0)
            search(key);
    }

    return 0;
}