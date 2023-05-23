#include <stdio.h>

int main(void)
{
    int A = 0;
    int B = 0;
    scanf("%d %d", &A, &B);
    A = A / 2;
    if (A > B)
    {
        printf("%d", B);
    }
    else
    {
        printf("%d", A);
    }
}