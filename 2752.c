#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b && b > c)
    {
        printf("%d %d %d", c, b, a);
    }
    else if (a > c && c > b)
    {
        printf("%d %d %d", b, c, a);
    }
    else if (b > a && a > c)
    {
        printf("%d %d %d", c, a, b);
    }
    else if (b > c && c > a)
    {
        printf("%d %d %d", a, c, b);
    }
    else if (c > a && a > b)
    {
        printf("%d %d %d", b, a, c);
    }
    else if (c > b && b > a)
    {
        printf("%d %d %d",a, b, c);
    }
}