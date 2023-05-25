#include <stdio.h>

int main(void)
{
    int N = 0;
    int a = 0;
    int sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a);
        sum += a;
    }
    printf("%d", sum - N + 1);
}