#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0)
        {
            return 0;
        }
        if (a > b)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}