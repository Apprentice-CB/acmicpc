#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int in = 0;
    int arr[2001] = {0, };
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &in);
        arr[in+1000]++;
    }
    for (int i = 0; i < 2002; i++)
    {
        if (arr[i] != 0)
        {
            printf("%d ", i-1000);
        }
    }
}