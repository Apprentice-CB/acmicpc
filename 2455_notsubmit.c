#include <stdio.h>

int main(void)
{
    int x = 0;
    int y = 0;
    int sum = 0;
    int max = 0;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d %d", &x, &y);
        sum = sum + y - x;
        if (sum > max)
        {
            max = sum;
        }
    }
    printf("%d", max);
}