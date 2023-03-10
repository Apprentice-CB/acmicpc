#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int t = 0;
    int *arr = (int*)malloc(sizeof(int)*N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", (arr+i));
    }

    /* insert sorting */
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
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
    }
    printf("%d", sum);
    return 0;
}