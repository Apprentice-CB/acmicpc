#include <stdio.h>

int main(void)
{
    int m = 0;
    int d = 0;
    scanf("%d %d", &m, &d);
    if (m < 2)
    {
        printf("Before");
    }
    else if (m == 2)
    {
        if (d < 18)
        {
            printf("Before");
        }
        else if (d == 18)
        {
            printf("Special");
        }
        else
        {
            printf("After");
        }
    }
    else
    {
        printf("After");
    }
}