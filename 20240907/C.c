#include <stdio.h>
#include <string.h>


int main(void)
{
    char s[100];
    char t[100];
    char x[100][100];
    int i, cnt;

    scanf("%s", &s);
    scanf("%s", &t);

    cnt = 0;
    while(strcmp(s, t)) {
        int cgd = 0;
        for(i = 0; i < strlen(s); i++) {
            if (s[i] > t[i]) {
                s[i] = t[i];
                strcpy(x[cnt], s);
                cnt++;
                cgd = 1;
                break;
            }
        }
        if(!cgd) {
            for(i = strlen(s)-1; i >= 0; i--) {
                if (s[i] < t[i]) {
                    s[i] = t[i];
                    strcpy(x[cnt], s);
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n", cnt);
    for(i = 0; i < cnt; i++) {
        printf("%s\n", x[i]);
    }
}
