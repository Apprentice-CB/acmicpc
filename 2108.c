#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int arr[500000+10];
int count[8000+10]; // -4000 -> 0

int compare(const void *a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main(void)
{
    int sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
        count[arr[i]+4000]++;
    }
    float a = (float)sum / (float)N;
    qsort(arr, N, sizeof(int), compare);

    int max = 0;
    int idx = 0;
    for (int i = 0; i <= 8000; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            idx = i;
        }
    }
    int same = 0;
    for (int i = 0; i <= 8000; i++)
    {
        if (count[i] == 0) continue;
        if (count[i] == max)
        {
            idx = i;
            same++;
        }
        if (same == 2)
        {
            idx = i;
            break;
        }
    }

    printf("%d\n%d\n%d\n%d\n", (int)round((double)a), arr[(N+1)/2-1], idx-4000, arr[N-1] - arr[0]);
    return 0;
}