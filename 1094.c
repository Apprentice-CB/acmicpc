#include <stdio.h>

int main(void)
{
    int X = 0;
    scanf("%d", &X);
    int S = 64;
    int cnt = 0;
    while(S > 0)
    {
        if (S > X)
        {
            S = S / 2;
        }
        else
        {
            cnt++;
            X = X - S;
        }
    }
    printf("%d", cnt);
}