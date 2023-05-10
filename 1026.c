#include <stdio.h>
#include <stdlib.h>

int compareA(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
    {
        return 1;
    }
    else if (*(int*)a < *(int*)b)
    {
        return -1;
    }
    return 0;
}

int compareB(const void* a, const void* b)
{
    if (*(int*)a > *(int*)b)
    {
        return -1;
    }
    else if (*(int*)a < *(int*)b)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int* arrA = (int*)malloc(sizeof(int) * N);
    int* arrB = (int*)malloc(sizeof(int) * N);
    int input = 0;
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &input);
        arrA[i] = input;
    }
    for (int i = 0; i < N; i++)
    {
        scanf(" %d", &input);
        arrB[i] = input;
    }
    qsort(arrA, N, sizeof(int), compareA);
    qsort(arrB, N, sizeof(int), compareB);
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        sum += arrA[i]*arrB[i];
    }
    printf("%d", sum);
}