#include <stdio.h>

int maxLenZeroSum(int arr[], int n) {
    int prefixSum = 0, maxLen = 0;

    // Hash map using arrays (since C doesn't have built-in hashmap)
    // Assuming sum range is manageable
    int hash[10000] = {0};   // adjust size if needed
    int index[10000];

    for (int i = 0; i < 10000; i++) {
        index[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        int key = prefixSum + 5000; // shift to avoid negative index

        if (index[key] != -1) {
            int len = i - index[key];
            if (len > maxLen)
                maxLen = len;
        } else {
            index[key] = i;
        }
    }

    return maxLen;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLenZeroSum(arr, n));

    return 0;
}