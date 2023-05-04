#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int visited[50][50] = {0, };    // height, width
int network[50][50] = {0, };

void DFS(int map[][50], int h, int w, int start_h, int start_w)
{
    visited[start_h][start_w] = 1;

    for (int hidx = start_h - 1; hidx <= start_h + 1; hidx++)
    {
        for (int widx = start_w - 1; widx <= start_w + 1; widx++)
        {
            if (0 <= hidx && hidx < h && 0 <= widx && widx < w)
            {
                if (visited[hidx][widx] == 0 && map[hidx][widx] == 1)
                {
                    DFS(map, h, w, hidx, widx);
                }
            }
        }
    }
}

int main(void)
{
    int w = 0;
    int h = 0;
    
    int cnt = 0;
    while(1)
    {
        // Map size scanf
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0)
        {
            break;
        }

        // Map scanf
        for (int hidx = 0; hidx < h; hidx++)
        {
            for (int widx = 0; widx < w; widx++)
            {
                scanf(" %d", &network[hidx][widx]);
            }
        }

        // init number of islands, stack array, visited array
        cnt = 0;
        memset(visited, 0, sizeof(int) * 50 * 50);

        for (int hidx = 0; hidx < h; hidx++)
        {
            for (int widx = 0; widx < w; widx++)
            {
                if (visited[hidx][widx] == 0 && network[hidx][widx] == 1)
                {
                    DFS(network, h, w, hidx, widx);
                    cnt++;
                }
            }
        }
        
        printf("%d\n", cnt);
    }
}