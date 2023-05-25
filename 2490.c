#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        sum = a + b + c + d;
        if (sum == 4)
        {
            printf("E\n");
        }
        else if (sum == 3)
        {
            printf("A\n");
        }
        else if (sum == 2)
        {
            printf("B\n");
        }
        else if (sum == 1)
        {
            printf("C\n");
        }
        else if (sum == 0)
        {
            printf("D\n");
        }
    }
}