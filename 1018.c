#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    char** board;
    board = (char**)malloc(sizeof(char*) * N);
    for (int i = 0; i < N; i++)
    {
        board[i] = (char*)malloc(sizeof(char*) * M);
        scanf("%s", board[i]);
    }

    int cnt_w = 0;
    int cnt_b = 0;
    int min_cnt = 2500;
    for (int r = 0; r < N-7; r++)
    {
        for (int c = 0; c < M-7; c++)
        {
            cnt_b = 0;
            cnt_w = 0;
            for (int ridx = r; ridx < r+8; ridx++)
            {
                for (int cidx = c; cidx < c+8; cidx++)
                {
                    if ((ridx+cidx)%2 == 0)
                    {
                        if (board[ridx][cidx] == 'B')
                        {
                            cnt_w++;
                        }
                        else
                        {
                            cnt_b++;
                        }
                    }
                    else
                    {
                        if (board[ridx][cidx] == 'B')
                        {
                            cnt_b++;
                        }
                        else
                        {
                            cnt_w++;
                        }
                    }
                }   
            }
            min_cnt = min(min(min_cnt, cnt_b), cnt_w);
        }
    }
    printf("%d", min_cnt);
}