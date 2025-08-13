#include <stdio.h>

int removeDuplicates(int arr[], int n) {
    if (n <= 1) {
        return n; 
    }

    int temp[n]; 
    int unique_count = 0;

    for (int i = 0; i < n; i++) {
        int is_duplicate = 0;
        for (int j = 0; j < unique_count; j++) {
            if (arr[i] == temp[j]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            temp[unique_count] = arr[i];
            unique_count++;
        }
    }

  
    for (int i = 0; i < unique_count; i++) {
        arr[i] = temp[i];
    }

    return unique_count; 
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int new_size = removeDuplicates(arr, n);

    printf("Array after removing duplicates: ");
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}