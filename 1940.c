#include <stdio.h>
#include <stdlib.h>

int N, M, arr[15010];

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int main(void)
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    qsort(arr, N, sizeof(int), compare);
    
    int a = 0;
    int b = N-1;
    int cnt = 0;
    while (a < b)
    {
        if (arr[a] + arr[b] == M)
        {
            cnt++;
            a++;
        }
        else if (arr[a] + arr[b] > M)
        {
            b--;
        }
        else
        {
            a++;
        }
    }
    printf("%d", cnt);
}