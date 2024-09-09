#include <stdio.h>


int main(void)
{
    int l, r;

    scanf ("%d %d", &l, &r);

    if(l) {
        if(r) {
            printf("Invalid\n");
        } else {
            printf("Yes\n");
        }
    } else {
        if(r) {
            printf("No\n");
        } else {
            printf("Invalid\n");
        }
    }

    return 0;
}
