#include <stdio.h>

int arr[51];
int N;

int main(void)
{
    scanf("%d", &N);
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    int maxidx = 0;
    int go = 0;
    while (1)
    {
        for (int i = 1; i < N; i++)
        {
            if (arr[0] <= arr[i])
            {
                go = 1;
                break;
            }
            go = 0;
        }
        if (go)
        {
            max = 0;
            for (int i = 1; i < N; i++) // 최대값 찾기
            {
                if (arr[i] > max)
                {
                    maxidx = i;
                    max = arr[i];
                }
            }
            arr[maxidx]--;
            arr[0]++;
            cnt++;
            // printf("maxidx: %d, max: %d, cnt: %d\n", maxidx, max, cnt);
            // for (int i = 0; i < N; i++)
            // {
            //     printf("%d ", arr[i]);
            // }
            // printf("\n");
        }
        else
        {
            break;
        }
    }
    printf("%d", cnt);
}