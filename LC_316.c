#include <stdlib.h>
#include <string.h>

char* removeDuplicateLetters(char* s) {

    int freq[26] = {0};
    int visited[26] = {0};

    int n = strlen(s);

    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int top = -1;

    for (int i = 0; i < n; i++) {

        char ch = s[i];

        freq[ch - 'a']--;

        if (visited[ch - 'a']) {
            continue;
        }

        while (top >= 0 &&
               stack[top] > ch &&
               freq[stack[top] - 'a'] > 0) {

            visited[stack[top] - 'a'] = 0;
            top--;
        }

        stack[++top] = ch;
        visited[ch - 'a'] = 1;
    }

    stack[top + 1] = '\0';

    return stack;
}
