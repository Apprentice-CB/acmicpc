#include <stdio.h>

int N, M, R; // 세로, 가로, 횟수
int A[110][110];
int cmd[1010];
int n = 0;

void getInput()
{
    scanf("%d %d %d", &N, &M, &R);
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            scanf("%d", &A[yidx][xidx]);
        }
    }
    for (int i = 0; i < R; i++)
    {
        scanf("%d", &cmd[i]);
    }
}

void flipupdown()
{
    int temp[110][110];
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            temp[yidx][xidx] = A[N-1-yidx][xidx];
        }
    }
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            A[yidx][xidx] = temp[yidx][xidx];
        }
    }
}

void flipleftright()
{
    int temp[110][110];
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            temp[yidx][xidx] = A[yidx][M-1-xidx];
        }
    }
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            A[yidx][xidx] = temp[yidx][xidx];
        }
    }
}

void turnright()
{
    int temp[110][110];
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            temp[xidx][yidx] = A[yidx][xidx];
        }
    }
    int tempn;
    tempn = N;
    N = M;
    M = tempn;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            A[yidx][xidx] = temp[yidx][xidx];
        }
    }
    flipleftright();   
}

void turnleft()
{
    int temp[110][110];
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            temp[xidx][yidx] = A[yidx][xidx];
        }
    }
    int tempn;
    tempn = N;
    N = M;
    M = tempn;
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            A[yidx][xidx] = temp[yidx][xidx];
        }
    }
    flipupdown();
}

void cmd5()
{
    int temp[110][110];
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx][xidx] = A[yidx + N/2][xidx];
        }
    }
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx+N/2][xidx] = A[yidx+N/2][xidx+M/2];
        }
    }
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx][xidx+M/2] = A[yidx][xidx];
        }
    }
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx+N/2][xidx+M/2] = A[yidx][xidx+M/2];
        }
    }
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            A[yidx][xidx] = temp[yidx][xidx];
        }
    }    
}

void cmd6()
{
    int temp[110][110];
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx][xidx] = A[yidx][xidx+M/2];
        }
    }
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx+N/2][xidx] = A[yidx][xidx];
        }
    }
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx][xidx+M/2] = A[yidx+N/2][xidx+M/2];
        }
    }
    for (int yidx = 0; yidx < N/2; yidx++)
    {
        for (int xidx = 0; xidx < M/2; xidx++)
        {
            temp[yidx+N/2][xidx+M/2] = A[yidx+N/2][xidx];
        }
    }
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            A[yidx][xidx] = temp[yidx][xidx];
        }
    }    
}

int main(void)
{
    getInput();
    // for (int yidx = 0; yidx < N; yidx++)
    // {
    //     for (int xidx = 0; xidx < M; xidx++)
    //     {
    //         printf("%d ", A[yidx][xidx]);
    //     }
    //     printf("\n");
    // }

    for (int i = 0; i < R; i++)
    {
        switch (cmd[i])
        {
            case 1:
                flipupdown();
                break;
            case 2:
                flipleftright();
                break;
            case 3:
                turnright();
                break;
            case 4:
                turnleft();
                break;
            case 5:
                cmd5();
                break;
            case 6:
                cmd6();
                break;
            default:
                break;
        }
        
    }
    for (int yidx = 0; yidx < N; yidx++)
    {
        for (int xidx = 0; xidx < M; xidx++)
        {
            printf("%d ", A[yidx][xidx]);
        }
        printf("\n");
    }
    return 0;
}