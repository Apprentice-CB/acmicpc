#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &arr[i]);
    }
    int sum = 0;
    int max = 0;
    for (int i=0; i<N; i++)
    {
        for (int j=i+1; j<N; j++)
        {
            for (int k=j+1; k < N; k++)
            {
                sum = arr[i] + arr[j] + arr[k];
                if ((sum > max) && (sum <= M))
                {
                    max = sum;
                }
            }
        }
    }
    printf("%d\n", max);
    return 0;
}