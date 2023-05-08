#include <stdio.h>

int main(void)
{
    int T = 0;
    int S = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    T = a + b + c + d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    S = a + b + c + d;
    if (T > S)
    {
        printf("%d", T);
    }
    else
    {
        printf("%d", S);
    }
}