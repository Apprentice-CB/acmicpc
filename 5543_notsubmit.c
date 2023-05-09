#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    if (a > b)
    {
        a = b;
    }
    if (a > c)
    {
        a = c;
    }
    if (d > e)
    {
        d = e;
    }
    printf("%d", a + d - 50);
}