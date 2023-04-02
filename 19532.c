#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    for (int xidx = -999; xidx <= 999; xidx++)
    {
        for (int yidx = -999; yidx <= 999; yidx++)
        {
            if ((a * xidx + b * yidx == c) && (d * xidx + e * yidx == f))
            {
                printf("%d %d", xidx, yidx);
                return 0;
            }
        }
    }
}