#include <stdio.h>

int iterative_binary_search(int arr[], int n, int x) {
    int min = 0;
    int max = n - 1;

    while (min <= max) {
        int mid = min + (max - min) / 2; 
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            min = mid + 1;
        }
        else {
            max = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2; 
    int result = iterative_binary_search(arr, n, x);
    if (result == -1) {
        printf("Element is not present in the array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }
    return 0;
}