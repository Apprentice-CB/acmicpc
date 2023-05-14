#include <stdio.h>

int main(void)
{
    int A = 0;
    int B = 0;
    int C = 0;
    int N = 0;
    scanf("%d %d %d", &A, &B, &C);
    scanf("%d", &N);
    int sum = 0;
    int temp = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = 0; j < 3; j++)
        {
            scanf("%d %d %d", &a, &b, &c);
            sum += a * A + b * B + c * C;
        }
        if (sum > temp)
        {
            temp = sum;
        }
    }
    printf("%d", temp);
}