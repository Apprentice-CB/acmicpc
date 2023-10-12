#include <stdio.h>

int min(int a, int b)
{
    if (a > b) return b;
    return a;
}

int main(void)
{
    int A, B, C, D, P;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    scanf("%d", &D);
    scanf("%d", &P);
    int f = A * P;
    int g = 0;
    if (P >= C)
    {
        g = B + D * (P - C);
    }
    else
    {
        g = B;
    }
    printf("%d %d %d\n", min(f, g));
}