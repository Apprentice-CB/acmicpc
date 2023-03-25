#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **arr = (int**)malloc(sizeof(int*)*9);
    for (int i = 0; i < 9; i++)
    {
        arr[i] = (int*)malloc(sizeof(int)*9);
    }

    int d = 0;
    for (int col = 0; col < 9; col++)
    {
        for (int row = 0; row < 9; row++)
        {
            scanf(" %d", &arr[col][row]);
        }
    }

    int max = -1;
    int max_col = 0;
    int max_row = 0;
    for (int col = 0; col < 9; col++)
    {
        for (int row = 0; row < 9; row++)
        {
            if (max < arr[col][row])
            {
                max = arr[col][row];
                max_col = col + 1;
                max_row = row + 1;
            }
        }
    }
    printf("%d\n%d %d", max, max_col, max_row);
}