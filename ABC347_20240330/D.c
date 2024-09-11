#include <stdio.h>

#define CHAR_BIT 8

unsigned long long int power(unsigned long long base, int exp)
{
    unsigned long long int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

unsigned long long int min(unsigned long long a, unsigned long long b)
{
    if(a > b) {
        return b;
    } else {
        return a;
    }
}

int popcount(unsigned long long a)
{
    int count = 0;
    while (a) {
        count += a & 1;
        a >>= 1;
    }
    return count;
}

unsigned long long next_popcount(unsigned long long x)
{
    unsigned long long smallest = x & -x;
    unsigned long long ripple = x + smallest;
    unsigned long long ones = x ^ ripple;
    ones = (ones >> 2) / smallest;
    return ripple | ones;
}

unsigned long long max_x(int a, int b, int cpc, unsigned long long C)
{
    unsigned long long x = 0;
    unsigned long long bit = 1;
    int x_bits_left = a;
    int y_bits_left = b;
    int c_bits_left = cpc;

    // C のビット位置に応じて x のビットをセット
    for (int bit_pos = 0; bit_pos < sizeof(C) * CHAR_BIT; ++bit_pos) {
        if (C & bit) {
            if (x_bits_left > 0) {
                x |= bit;
                --x_bits_left;
            }
            --c_bits_left;
        }
        bit <<= 1;
    }

    // C のビット位置以外のビット位置に応じて x のビットをセット
    bit = 1;
    for (int bit_pos = 0; bit_pos < sizeof(C) * CHAR_BIT; ++bit_pos) {
        if (!(C & bit) && x_bits_left > 0) {
            x |= bit;
            --x_bits_left;
        }
        bit <<= 1;
    }

    return x;
}

int main(void)
{
    int a, b;
    int i;
    unsigned long long C, x, y;

    scanf("%d %d %llu", &a, &b, &C);

    x = 0;
    for(i = 0; i < a; i++) {
        x = (x<<1)|0x01;
    }

    do {
        y = x ^ C;
        /* printf("%llu %llu\n", x, y); */
        if(popcount(y) == b) {
            printf("%llu %llu\n", x, y);
            return 0;
        }
        x = next_popcount(x);
    } while(x < power(2, 60));

    printf("-1\n");
    return 0;
}
