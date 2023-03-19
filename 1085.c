#include <stdio.h>
#include <math.h>

int min(int n, int m)
{
    if (n > m)
    {
        return m;
    }
    else
    {
        return n;
    }
}

int main(void)
{
    int x = 0;
    int y = 0;
    int w = 0;
    int h = 0;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    printf("%d", min(min(x, w-x), min(y, h-y)));
}