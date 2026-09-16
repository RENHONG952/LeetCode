#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int s_len = strlen(s);
    int length = 0;
    
    for (int i = s_len - 1; i >= 0; i--) {
        if (s[i] != ' ') {
            length ++;
        } else {
            if (length != 0) {
                break;
            }
        }
    }
    return length;
}

int main() {
    char s[] = "Hello World";
    int ans = lengthOfLastWord(s);
    printf("%d", ans);
    return 0;
}