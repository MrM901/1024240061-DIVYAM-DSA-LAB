#include <stdio.h>
#include <string.h>

int main() {
    char s[] = "Divyam";
    printf("%s\n", s);
  
        int n = strlen(s);
    for (int i = 0; i < n / 2; i++) {
        char temp = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = temp;
}
printf("Reversed: %s\n", s);

return 0;
}