#include <stdio.h>
#include <stdlib.h>

int N, M, C;

typedef struct node
{
    int s;
    int e;
    int num;
} node;

node A[2010];
int loaded[2010];

int compare(const void* a, const void* b)
{
    node x = *(node*) a;
    node y = *(node*) b;
    if (x.e > y.e) return 1;
    else if (x.e == y.e) return 0;
    return -1;
}

int min(int a, int b)
{
    if (a > b) return b;
    return a;
}

int main(void)
{
    int ans = 0;
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &A[i].s, &A[i].e, &A[i].num);
    }
    
    qsort(A, M, sizeof(node), compare);

    for (int i = 0; i < M; i++)
    {
        int total = 0;
        for (int j = A[i].s; j < A[i].e; j++)
        {
            if (total < loaded[j])
            {
                total = loaded[j];
            }
        }

        int load_more = min(A[i].num, C - total);
        for (int j = A[i].s; j < A[i].e; j++)
        {
            loaded[j] += load_more;
        }
        ans += load_more;
    }
    printf("%d", ans);
}