#include <stdio.h>

int main(void)
{
    int A = 0;
    int min = 101;
    int sum = 0;
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &A);
        if (A % 2 == 1)
        {
            if (min > A)
            {
                min = A;
            }
            sum += A;
        }
    }
    if (min == 101)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n%d", sum, min);
    }
}