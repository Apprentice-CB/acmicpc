#include <stdio.h>

int main(void)
{
    int L = 0;
    int P = 0;
    scanf("%d %d", &L, &P);
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    printf("%d %d %d %d %d", a-L*P, b-L*P, c-L*P, d-L*P, e-L*P);
}