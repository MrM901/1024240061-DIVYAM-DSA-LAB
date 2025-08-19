#include <stdio.h>

int main() {
    char ch;

    printf("Enter a lowercase character: ");
    scanf(" %c", &ch); 

    if (ch >= 'a' && ch <= 'z') {
        char upperCh = ch - 32;
        printf("The uppercase character is: %c\n", upperCh);
    } else {
        printf("The entered character is not a lowercase letter.\n");
    }

    return 0;
}