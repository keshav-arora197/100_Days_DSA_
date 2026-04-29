#include <stdio.h>

int integerSqrt(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // To avoid overflow, use mid <= n / mid
        if (mid <= n / mid) {
            ans = mid;       // possible answer
            low = mid + 1;   // search right
        } else {
            high = mid - 1;  // search left
        }
    }

    return ans;
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", integerSqrt(n));

    return 0;
}