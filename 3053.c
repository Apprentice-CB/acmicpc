#include <stdio.h>
#define PI 3.14159265359

int main(void)
{
    int R = 0;
    scanf("%d", &R);
    printf("%.6lf\n%.6lf", (double)PI*R*R, (double)2.0*R*R);
}