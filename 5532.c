#include <stdio.h>

int main(void)
{
    int L = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    int D = 0;
    scanf("%d %d %d %d %d", &L, &A, &B, &C, &D);
    int aa = 0;
    int bb = 0;
    if (A % C == 0)
    {
        aa = A / C;
    }
    else
    {
        aa = A / C + 1;
    }
    if (B % D == 0)
    {
        bb = B / D;
    }
    else
    {
        bb = B / D + 1;
    }
    if (aa > bb)
    {
        printf("%d", L - aa);
    }
    else
    {
        printf("%d", L - bb);
    }

}