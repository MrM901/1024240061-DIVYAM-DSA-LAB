#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int countDistinct(int arr[], int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    qsort(arr, n, sizeof(int), compare);

    int distinctCount = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            distinctCount++;
        }
    }

    return distinctCount;
}

int main() {
    int arr[] = {10, 20, 20, 30, 40, 40, 40, 50, 50};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("The array is: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int distinct_count = countDistinct(arr, n);
    printf("Total number of distinct elements is: %d\n", distinct_count);

    return 0;
}