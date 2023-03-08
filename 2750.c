#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 0;
    scanf("%d", &N);
    int *list = (int*)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", list + i);
    }
    /* Insert sort */
    /*
    int key = 0;
    for (int i = 1; i < N; i++)
    {
        key = list[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (key < list[j])
            {
                list[j+1] = list[j];
                list[j] = key;
            }
        }
    }
    */

    /* Selection Sort */   
    int idx = 0;
    int temp = 0;
    for (int i = 0; i < N-1; i++)
    {
        idx = i;
        for (int j = i + 1; j < N; j++)
        {
            if (list[j] < list[idx])
            {
                idx = j;
            }
        }
        temp = list[idx];
        list[idx] = list[i];
        list[i] = temp;
    }


    for (int i = 0; i < N; i++)
    {
        printf("%d\n", list[i]);
    }
    return 0;
}