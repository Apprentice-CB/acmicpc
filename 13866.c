#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    printf("%d", abs(a+d-b-c));
}