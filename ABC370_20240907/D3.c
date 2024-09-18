#include <stdio.h>

int main(void)
{
    int h, w, q;
    int r, c;
    int i, j;
    int tgt, tmp;
    int sum;

    scanf("%d %d %d", &h, &w, &q);
    char x[h+1][w+1];
    for(i = 0; i <= h; i++) {
        for(j = 0; j <= w; j++) {
            x[i][j] = 0;
        }
    }

    sum = h*w;

    for(i = 0; i < q; i++) {
        scanf("%d %d", &r, &c);

        if(!x[r][c]) {
            x[r][c]++;
            sum--;
        } else {
            for(j = r-1; j > 0; j--) {
                if(!x[j][c]) {
                    x[j][c]++;
                    sum--;
                    break;
                }
            }
            for(j = r+1; j <= h; j++) {
                if(!x[j][c]) {
                    x[j][c]++;
                    sum--;
                    break;
                }
            }
            for(j = c-1; j > 0; j--) {
                if(!x[r][j]) {
                    x[r][j]++;
                    sum--;
                    break;
                }
            }
            for(j = c+1; j <= w; j++) {
                if(!x[r][j]) {
                    x[r][j]++;
                    sum--;
                    break;
                }
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}
