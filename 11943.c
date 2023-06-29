#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    if (a + d <= b + c)
    {
        printf("%d", a+d);
    }
    else
    {
        printf("%d", b+c);
    }
}