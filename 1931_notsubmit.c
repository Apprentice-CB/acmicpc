#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int s;
    int e;
} node;

int compare(const void* a, const void* b)
{
    node x = *(node*)a;
    node y = *(node*)b;
    if (x.e > y.e) return 1;
    else if (x.e == y.e) return 0;
    return -1;
}

int N;
node A[100010];

int main(void)
{
    int ans = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &A[i].s, &A[i].e);
    }

    qsort(A, N, sizeof(node), compare);

    int end = A[0].e;
    for (int i = 1; i < N; i++)
    {
        if (A[i].s >= end)
        {
            end = A[i].e;
            ans++;
        }
    }
    printf("%d", ans);
}