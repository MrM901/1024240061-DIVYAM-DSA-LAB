#include <stdio.h>
#include <stdlib.h> 

// Function to create an array
void createArray(int arr[], int *size, const int MAX_SIZE) {
    if (*size > 0) {
        printf("Array already exists. Please start a new program or delete the existing array.\n");
        return;
    }

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", size);
    if (*size > MAX_SIZE) {
        printf("Error: Size exceeds maximum limit. Setting size to %d.\n", MAX_SIZE);
        *size = MAX_SIZE;
    }

    printf("Enter %d elements:\n", *size);
    for (int i = 0; i < *size; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully.\n");
}

// Function to display the array
void displayArray(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty. Please create an array first.\n");
        return;
    }
    printf("Array elements are: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specific position
void insertElement(int arr[], int *size, const int MAX_SIZE) {
    if (*size >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return;
    }
    if (*size == 0) {
        printf("Array is empty. Please create an array first.\n");
        return;
    }

    int position, value;
    printf("Enter the position to insert the element (1 to %d): ", *size + 1);
    scanf("%d", &position);
    if (position < 1 || position > *size + 1) {
        printf("Invalid position.\n");
        return;
    }
    printf("Enter the value to insert: ");
    scanf("%d", &value);

    // Shift elements to make space for the new element
    for (int i = *size; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = value;
    (*size)++;
    printf("Element inserted successfully.\n");
}

// Function to delete an element from a specific position
void deleteElement(int arr[], int *size) {
    if (*size == 0) {
        printf("Array is empty. Nothing to delete.\n");
        return;
    }
    int position;
    printf("Enter the position of the element to delete (1 to %d): ", *size);
    scanf("%d", &position);

    if (position < 1 || position > *size) {
        printf("Invalid position.\n");
        return;
    }

    // Shift elements to the left to overwrite the deleted element
    for (int i = position - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
    printf("Element deleted successfully.\n");
}

// Function to perform a linear search
void linearSearch(int arr[], int size) {
    if (size == 0) {
        printf("Array is empty. Cannot perform search.\n");
        return;
    }
    int searchValue;
    printf("Enter the value to search for: ");
    scanf("%d", &searchValue);

    int found = 0; // Use int as a boolean flag
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            printf("Element %d found at position %d.\n", searchValue, i + 1);
            found = 1;
            break; // Exit the loop once the element is found
        }
    }
    if (!found) {
        printf("Element %d not found in the array.\n", searchValue);
    }
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size = 0;
    int choice;

    do {
        printf("\n\n------ MENU ------\n");
        printf("1. CREATE\n");
        printf("2. DISPLAY\n");
        printf("3. INSERT\n");
        printf("4. DELETE\n");
        printf("5. LINEAR SEARCH\n");
        printf("6. EXIT\n");
        printf("------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createArray(arr, &size, MAX_SIZE);
                break;
            case 2:
                displayArray(arr, size);
                break;
            case 3:
                insertElement(arr, &size, MAX_SIZE);
                break;
            case 4:
                deleteElement(arr, &size);
                break;
            case 5:
                linearSearch(arr, size);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}



