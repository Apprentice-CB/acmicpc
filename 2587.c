#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int *arr = (int*)malloc(sizeof(int)*5);
    int input = 0;
    for (int idx = 0; idx < 5; idx++)
    {
        scanf("%d", &input);
        arr[idx] = input;
    }

    /* selection sort */
    int min_idx = 0;
    int temp = 0;
    for (int i = 0; i < 4; i++)
    {   
        min_idx = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }

    /* average & mid */
    int sum = 0;
    for (int idx = 0; idx < 5; idx++)
    {
        sum += arr[idx];
    }
    printf("%d\n%d", sum/5, arr[2]);
    return 0;
}