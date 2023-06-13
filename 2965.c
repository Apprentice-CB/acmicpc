#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    int m = b - a;
    int n = c - b;
    if (m > n)
    {
        printf("%d", m-1);
    }
    else
    {
        printf("%d", n-1);
    }
}