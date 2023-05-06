#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int N = 0;
    int K = 0;
    scanf("%d %d", &N, &K);
    int* arr = (int*)malloc(sizeof(int) * (N+1));
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }
    int cnt = 0;
    
    for (int i = 2; i <= N; i++)
    {
        if (arr[i] == 0)
        {
            continue;
        }
        else
        {
            for (int j = i; j <= N; j += i)
            {
                if (arr[j] != 0)
                {
                    arr[j] = 0;
                    cnt++;
                }
                if (cnt == K)
                {
                    printf("%d", j);
                    break;
                }
            }
        }
    }
    
}