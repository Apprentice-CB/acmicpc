#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main(void)
{
    int T = 0;
    int A = 0;
    int B = 0;
    scanf("%d", &T);
    int g = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &A, &B);
        g = gcd(A, B);
        printf("%d\n", A*B/g);
    }
}