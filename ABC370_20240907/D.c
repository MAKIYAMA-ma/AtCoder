#include <stdio.h>

int main(void)
{
    int h, w, q;
    int r, c;
    int i, j;
    int tgt, tmp;
    int sum;
    char x[400000] = {0};

    scanf("%d %d %d", &h, &w, &q);
    /* for(i = 0; i < h*w; i++) { */
    /*     x[i] = 1; */
    /* } */

    sum = h*w;
    for(i = 0; i < q; i++) {
        scanf("%d %d", &r, &c);
        r--;
        c--;
        tgt = r*w+c;

        if(!x[tgt]) {
            x[tgt]++;
            sum--;
        } else {
            tmp = tgt-w;
            for(j = r-1; j >= 0; j--) {
                if(!x[tmp]) {
                    x[tmp]++;
                    sum--;
                    break;
                }
                tmp -= w;
            }
            tmp = tgt+w;
            for(j = r+1; j < h; j++) {
                if(!x[tmp]) {
                    x[tmp]++;
                    sum--;
                    break;
                }
                tmp += w;
            }
            tmp = tgt-1;
            for(j = c-1; j >= 0; j--) {
                if(!x[tmp]) {
                    x[tmp]++;
                    sum--;
                    break;
                }
                tmp--;
            }
            tmp = tgt+1;
            for(j = c+1; j < w; j++) {
                if(!x[tmp]) {
                    x[tmp]++;
                    sum--;
                    break;
                }
                tmp++;
            }
        }

        /* int k, l; */
        /* for(k = 0; k < h; k++) { */
        /*     for(l = 0; l < w; l++) { */
        /*         printf("%d ", x[k*w+l]); */
        /*     } */
        /*     printf("\n"); */
        /* } */
    }

    printf("%d\n", sum);

    return 0;
}
