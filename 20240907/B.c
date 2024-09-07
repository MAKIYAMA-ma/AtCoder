#include <stdio.h>


int main(void)
{
    int n = 0;
    int a[100][100] = {0};
    int i, j;
    int res;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < i+1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    res = 1;
    for(i = 1; i <= n; i++) {
        if(res >= i) {
            res = a[res-1][i-1];
        } else {
            res = a[i-1][res-1];
        }
    }
    printf("%d\n", res);
}
