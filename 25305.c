#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int k = 0;
    scanf("%d %d", &N, &k);
    int *arr = (int*)malloc(sizeof(int) * N);
    for (int idx = 0; idx < N; idx++)
    {
        scanf(" %d", (arr+idx));
    }

    /* insert sort */
    int key = 0;
    int temp = 0;
    for (int i = 1; i < N; i++)
    {
        key = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > key)
            {
                arr[j+1] = arr[j];
                arr[j] = key;
            }
        }
    }

    int cut = arr[N-k];
    printf("%d", cut);
    
    return 0;
}