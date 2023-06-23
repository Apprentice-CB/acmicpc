#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int a = 0;
    for (int h = 0; h < n; h++)
    {
        scanf("%d", &a);
        sum = 0;
        for (int i = 1; i <= a; i++)
        {
            sum += i * (i + 1) * (i + 2) / 2;
        }
        printf("%d\n", sum);
    }
}