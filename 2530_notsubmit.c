#include <stdio.h>

int main(void)
{
    int h = 0;
    int m = 0;
    int s = 0;
    int t = 0;
    scanf("%d %d %d", &h, &m, &s);
    scanf("%d", &t);

    s = s + t % 60;
    m = m + t / 60;
    m = m + s / 60;
    h = h + m / 60;
    s = s % 60;
    m = m % 60;
    h = h % 24;

    printf("%d %d %d", h, m, s);
}