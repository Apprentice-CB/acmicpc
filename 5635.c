#include <stdio.h>
#include <stdlib.h>

typedef struct info
{
    char name[16];
    int dd;
    int mm;
    int yyyy;
} info;

int compare(const void* x, const void* y)
{
    info* a = (info*)x;
    info* b = (info*)y;
    if (a->yyyy > b->yyyy)
    {
        return 1;
    }
    else if (a->yyyy < b->yyyy)
    {
        return -1;
    }
    else
    {
        if (a->mm > b->mm)
        {
            return 1;
        }
        else if (a->mm < b->mm)
        {
            return -1;
        }
        else
        {
            if (a->dd > b->dd)
            {
                return 1;
            }
            else if (a->dd < b->dd)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    info* ls = (info*)malloc(sizeof(info) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", ls[i].name, &ls[i].dd, &ls[i].mm, &ls[i].yyyy);
    }
    qsort(ls, n, sizeof(info), compare);

    printf("%s\n%s", ls[n-1].name, ls[0].name);
}