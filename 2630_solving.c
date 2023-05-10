#include <stdio.h>

int map[128][128] = {0, };

void dnc(int map[][128], int N, int x, int y, int* white, int* blue)
{
    int cnt = 0;
    
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            scanf("%d", map[x][y]);
        }
    }

    int white = 0;
    int blue = 0;
    dnc(map, N, 0, 0, &white, &blue);
    printf("%d\n%d", white, blue);
}