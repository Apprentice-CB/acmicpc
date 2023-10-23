#include <stdio.h>
#include <stdlib.h>

int N;
int arr[1000000+10];

int compare(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int main(void)
{
    getInput();
    qsort(arr, N, sizeof(int), compare);
    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
}