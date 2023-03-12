#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct point
{
    int x;
    int y;
} point;

int compare(const void* a, const void* b)
{
    point p_a = *(point*)a;
    point p_b = *(point*)b;
    if (p_a.y > p_b.y)
    {
        return 1;
    }
    else if (p_a.y == p_b.y)
    {
        if (p_a.x > p_b.x)
        {
            return 1;
        }
        else if (p_a.x == p_b.x)
        {
            return 0;
        }
    }
    return -1;
}

int main()
{
    int N = 0;
    scanf("%d", &N);
    point* p_arr = (point*)malloc(sizeof(point)*N);
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x, &y);
        p_arr[i].x = x;
        p_arr[i].y = y;
    }
    qsort(p_arr, N, sizeof(point), compare);

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", p_arr[i].x, p_arr[i].y);
    }
}