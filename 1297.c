#include <stdio.h>
#include <math.h>

int main(void)
{
    int D = 0;
    int H = 0;
    int W = 0;
    scanf("%d %d %d", &D, &H, &W);
    double x = D / sqrt(W*W + H*H);
    printf("%d %d", (int)(x * H), (int)(x * W));
}