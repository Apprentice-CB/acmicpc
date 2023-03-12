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
    point point_1 = *(point*)a;
    point point_2 = *(point*)b;
    if (point_1.x > point_2.x)
    {
        return 1;
    }
    else if (point_1.x == point_2.x)
    {
        if (point_1.y > point_2.y)
        {
            return 1;
        }
        else if (point_1.y == point_2.y)
        {
            return 0;
        }
    }
    return -1;
}

int main(void)
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

    /* insert sort --> need to be done with quick sort? */
    /*
    int min_idx = 0;
    point p_temp;
    for (int i = 0; i < N; i++)
    {
        min_idx = i;
        for (int j = i + 1; j < N; j++)
        {
            if (p_arr[min_idx].x > p_arr[j].x)
            {
                min_idx = j;
            }
            else if (p_arr[min_idx].x == p_arr[min_idx].x)
            {
                if (p_arr[min_idx].y > p_arr[j].y)
                {
                    min_idx = j;
                }
            }
        }
        p_temp = p_arr[min_idx];
        p_arr[min_idx] = p_arr[i];
        p_arr[i] = p_temp;
    }
    */

   /* quick sort */
   qsort(p_arr, N, sizeof(point), compare);
    
    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", p_arr[i].x, p_arr[i].y);
    }
}