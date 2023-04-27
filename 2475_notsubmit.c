#include <stdio.h>

int main(void)
{
    int sum = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%d", (a*a+b*b+c*c+d*d+e*e)%10);
}