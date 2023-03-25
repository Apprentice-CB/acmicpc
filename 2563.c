#include <stdio.h>

int arr[100][100] = {0, };

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        for (int xidx = x; xidx < x + 10; xidx++)
        {
            for (int yidx = y; yidx < y + 10; yidx++)
            {
                arr[xidx][yidx] = 1;
            }
        }
    }

    int surface = 0;
    for (int xidx = 0; xidx < 100; xidx++)
    {
        for (int yidx = 0; yidx < 100; yidx++)
        {
            surface += arr[xidx][yidx];
        }
    }
    printf("%d", surface);
}