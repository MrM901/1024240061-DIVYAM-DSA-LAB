#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int stack_size = 0;

int main() {
    int choice, value;

    while (1) { 
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (stack_size == SIZE) {
                printf("Stack is full!!\n");
            } else {
                printf("Enter value to push: ");
                scanf("%d", &value);
                stack[stack_size] = value;
                stack_size++;
                printf("%d pushed to stack.\n", value);
            }
        } else if (choice == 2) {
            if (stack_size == 0) {
                printf("Stack is empty!!\n");
            } else {
                stack_size--;
                value = stack[stack_size];
                printf("Popped value is %d\n", value);
            }
        } else if (choice == 3) {
            if (stack_size == 0) {
                printf("Stack is empty!!\n");
            } else {
                printf("Stack elements are: ");
                for (int i = 0; i < stack_size; i++) {
                    printf("%d ", stack[i]);
                }
                printf("\n");
            }
        } else if (choice == 4) {
            if (stack_size == 0) {
                printf("Stack is empty!!\n");
            } else {
                printf("Top element is: %d\n", stack[stack_size - 1]);
            }
        } else if (choice == 5) {
            printf("exiting\n");
            break; 
        } else {
            printf("error\n");
        }
    }

    return 0; 
}