#include <stdio.h>
int main() {
    int n, pos, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int newarr[n + 1];

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the position : ");
    scanf("%d", &pos);

    printf("Enter the element to insert: ");
    scanf("%d", &x);

    for(int i = 0; i < pos - 1; i++) {
        newarr[i] = arr[i];
    }
    newarr[pos - 1] = x;
    for(int i = pos - 1; i < n; i++) {
        newarr[i + 1] = arr[i];
    }
    printf("Updated array:\n");
    for(int i = 0; i < n + 1; i++) {
        printf("%d ", newarr[i]);
    }

    return 0;
}
