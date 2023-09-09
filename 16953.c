#include <stdio.h>

int main(void)
{
    int A, B;
    scanf("%d %d", &A, &B);
    int cnt = 1;
    while (A < B)
    {
        if (B%10 == 1)
        {
            B /= 10;
        }
        else if (B % 2 == 0)
        {
            B /= 2;
        }
        else
        {
            printf("-1");
            return 0;
        }
        cnt++;
    }
    if (A == B) printf("%d", cnt);
    else printf("-1");
    return 0;
}