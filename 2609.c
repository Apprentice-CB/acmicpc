#include <stdio.h>

int gcd(int a, int b)
{
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    while (b!=0)
    {
        int n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main(void)
{
    int x = 0;
    int y = 0;
    scanf("%d %d", &x, &y);
    int g = 0;
    int l = 0;
    g = gcd(x, y);
    l = x*y/g;
    printf("%d\n%d", g, l);
}