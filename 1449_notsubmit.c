#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N = 0;
    int L = 0;
    scanf("%d %d", &N, &L);
    int arr[1001] = {0, };
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &temp);
        arr[temp] = 1;
    }
    int cnt = 0;
    for (int i = 1; i < 1001; i++)
    {
        if (arr[i] == 1)
        {
            for (int j = 0; j < L; j++)
            {
                arr[i+j] = 0;
            }
            cnt++;
        }
    }
    printf("%d", cnt);
}