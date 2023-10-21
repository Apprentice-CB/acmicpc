#include <stdio.h>
#include <stdlib.h>

int N, M;
int A[1000000+10];
int B[1000000+10];


int compare(const void* a, const void * b)
{
    return *(int*)a - *(int*)b;
}

void getInput()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    for (int j = 0; j < M; j++)
    {
        scanf("%d", &B[j]);
    }
}

int main(void)
{
    getInput();
    qsort(A, N, sizeof(int), compare);
    qsort(B, M, sizeof(int), compare);
    int ap = 0;
    int bp = 0;
    while (ap < N && bp < M)
    {
        if (A[ap] < B[bp])
        {
            printf("%d ", A[ap]);
            ap++;
        }
        else if (A[ap] == B[bp])
        {
            printf("%d %d ", A[ap], B[bp]);
            ap++; bp++;
        }
        else
        {
            printf("%d ", B[bp]);
            bp++;
        }
    }
    if (ap == N)
    {
        while (bp < M)
        {
            printf("%d ", B[bp]); bp++;
        }
    }
    else if (bp == M)
    {
        while (ap < N)
        {
            printf("%d ", A[ap]); ap++;
        }
    }
    return 0;
}