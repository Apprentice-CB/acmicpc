#include <stdio.h>

int main(void)
{
    int N = 0;
    int A = 0;
    int B = 0;
    int C = 0;
    scanf("%d", &N);
    scanf("%d %d %d", &A, &B, &C);
    if (A >= N)
    {
        A = N;
    }
    if (B >= N)
    {
        B = N;
    }
    if (C >= N)
    {
        C = N;
    }
    printf("%d", A+B+C);
}