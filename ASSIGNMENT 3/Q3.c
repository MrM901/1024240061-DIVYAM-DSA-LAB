#include <stdio.h>

#define MAX_EXPR_SIZE 100

int main() {
    char expr[] = "{[]()}";

    char stack[MAX_EXPR_SIZE];
    int stack_size = 0; 

    for (int i = 0; expr[i] != '\0'; i++) {
        char currentbracket = expr[i];

        if (currentbracket == '(' || currentbracket == '{' || currentbracket == '[') {
            stack[stack_size] = currentbracket;
            stack_size++;
        }
        else if (currentbracket == ')' || currentbracket == '}' || currentbracket == ']') {
            if (stack_size == 0) {                      
                printf("Not Balanced.\n");
                return 0;
            }

            char lastBracket = stack[stack_size - 1];
            
            if ((lastBracket == '(' && currentbracket == ')') ||
                (lastBracket == '{' && currentbracket == '}') ||
                (lastBracket == '[' && currentbracket == ']')) {
                stack_size--;
            } else {
                printf("Not Balanced.\n");
                return 0;
            }
        }
    }

    if (stack_size == 0) {
        printf("Balanced!\n");
    } else {
        printf("Not Balanced.\n");
    }
        
    return 0;
}