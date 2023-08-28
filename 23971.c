#include <stdio.h>

int main(void)
{
    int H, W, N, M;
    scanf("%d %d %d %d", &H, &W, &N, &M);
    int s;
    int h, w;
    if (H % (N+1) == 0)
    {
        h = H / (N+1);
    }
    else
    {
        h = H / (N+1) + 1;
    }
    if (W % (M+1) == 0)
    {
        w = W / (M+1);
    }
    else
    {
        w = W / (M+1) + 1;
    }
    s = h * w;
    printf("%d", s);
}