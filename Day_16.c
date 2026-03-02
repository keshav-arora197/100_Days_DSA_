#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for(int i = 0; i < n; i++) {
        int count = 1;

    
        if(arr[i] == -999999)
            continue;

        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                arr[j] = -999999;  
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}