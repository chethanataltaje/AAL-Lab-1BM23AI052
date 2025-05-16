#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bruteForceMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}
int main() {
    char text[100], pattern[50];

    printf("Enter text: ");
    scanf(" %[^\n]", text);
    printf("Enter the pattern to search: ");
    scanf(" %[^\n]", pattern);

    bruteForceMatch(text, pattern);

    return 0;
}

/*output:
Enter text: Hello people
Enter the pattern to search: llo
Pattern found at index 2
*/
