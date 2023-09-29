#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int n = 6;
    int p = 2;
    
    printf("Number of pages to flip: [%d]\n", pageCount(n, p));
}
int backFlipsCalc(int n, int p);
int frontFlipsCalc(int n, int p);

int pageCount(int n, int p) {

    int frontFlips;
    int backFlips;

    if ((n == p) || ((n % 2 != 0) && ((n - 1) == p)) || (p - 1) == 0)
    {
        return 0;
    }

    backFlips = backFlipsCalc(n, p);
    frontFlips = frontFlipsCalc(n, p);
    if (backFlips > frontFlips)
    {
        return frontFlips;
    }
    else
    {
        return backFlips;
    }
}
int backFlipsCalc(int n, int p)
{
    if (n % 2 != 0)
    {
        n--;
    }
    if (p % 2 == 0)
    {
        p++;
    }
    return ((n - p) / 2 + 1);
}
int frontFlipsCalc(int n, int p)
{
    if (p % 2 != 0)
    {
        p--;
    }
    return ((p - 1) / 2 + 1);
}