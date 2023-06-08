#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nidx = 0;
int midx = 0;
int area = 0;
int dx[4] = {-1, 0, 1, 0};  // n, e, s, w
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    int n_start = 0;
    int m_start = 0;
    int dir = 0;
    scanf("%d %d %d", &n_start, &m_start, &dir);

    int** map = (int**)malloc(sizeof(int*) * N);
    int** visited = (int**)malloc(sizeof(int*) * N);
    for (nidx = 0; nidx < N; nidx++)
    {
        map[nidx] = (int*)malloc(sizeof(int) * M);
        visited[nidx] = (int*)malloc(sizeof(int) * M);
        memset(visited[nidx], 0, sizeof(int) * M);
    }

    for (nidx = 0; nidx < N; nidx++)
    {
        for (midx = 0; midx < M; midx++)
        {
            scanf(" %d", &map[nidx][midx]);
        }
    }

    //dfs(map, visited, N, M, n_start, m_start, dir);
    int n_next = 0;
    int m_next = 0;
    int status = 0;
    int n_prev = n_start;
    int m_prev = m_start;
    while(1)
    {
        if (map[n_prev][m_prev] == 0)
        {
            map[n_prev][m_prev] = 2;
            area++;
        }

        n_next = n_prev + dx[dir];
        m_next = m_prev + dy[dir];

        for (int i = 0; i < 4; i++)
        {
            n_next = n_prev + dx[i];
            m_next = m_prev + dy[i];
            if (0 <= n_next && n_next < N && 0 <= m_next && m_next < M)
            {
                if (map[n_next][m_next] != 0)
                {
                    status = 2; // all adjacent areas are cleaned
                }
                else
                {
                    status = 3;
                    break;
                }
            }
        }
        if (status == 2)
        {
            n_next = n_prev - dx[dir];
            m_next = m_prev - dy[dir];
            if (map[n_next][m_next] == 1)
            {
                break;
            }
        }
        else if (status == 3)
        {
            dir = (dir + 3) % 4;
            n_next = n_prev + dx[dir];
            m_next = m_prev + dy[dir];
            while (map[n_next][m_next] != 0)
            {
                dir = (dir + 3) % 4;
                n_next = n_prev + dx[dir];
                m_next = m_prev + dy[dir];
            }
        }
        
        n_prev = n_next;
        m_prev = m_next;
    }


    printf("%d", area);
    
    return 0;
    
}