#include <stdio.h>
#include <math.h>

int main(void)
{
    int A = 0;
    int B = 0;
    scanf("%d %d", &A, &B);
    double M = (double)(B - A) / 400;
    double pt = 1 / (1 + pow(10, M));
    printf("%lf", pt);
}