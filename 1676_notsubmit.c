#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    if (N == 0)
    {
        printf("0");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (i % 5 == 0)
            cnt++;
    }
    printf("%d", cnt);
}