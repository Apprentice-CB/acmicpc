#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int num = 0;
    int arr[10001] = {0, };
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num);
        arr[num]++;
    }


    for (int i = 0; i < 10001; i++)
    {
        for (int j = 1; j <= arr[i]; j++)
            printf("%d\n", i);
    }
    return 0;
}