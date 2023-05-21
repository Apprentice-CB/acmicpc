#include <stdio.h>
#include <stdlib.h>

typedef struct school
{
    char name[20];
    int al;
} school;

int compare(const void* a, const void* b)
{
    school x = *(school *)a;
    school y = *(school *)b;
    if (x.al > y.al)
    {
        return -1;
    }
    else if (x.al == y.al)
    {
        return 0;
    }
    return 1;
}

int main(void)
{
    int T = 0;
    int N = 0;
    scanf("%d", &T);
    school sch[100];
    char n[20];
    int a = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            scanf("%s %d", sch[j].name, &sch[j].al);
        }
        qsort(sch, N, sizeof(school), compare);
        printf("%s\n", sch[0].name);
    }
}