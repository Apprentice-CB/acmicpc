#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    while(1)
    {
        scanf("%d %d %d", &a, &b, &c);
        if (a == 0 && b == 0 && c == 0)
        {
            return 0;
        }
        if ((a*a+b*b == c*c) || (a*a+c*c==b*b) || (b*b+c*c==a*a))
        {
            printf("right\n");
        }
        else
        {
            printf("wrong\n");
        }
    }
}