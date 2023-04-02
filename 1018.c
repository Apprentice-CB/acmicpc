#include <stdio.h>

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

    int cnt = 0;
    for (int rowidx = 0; rowidx < N-8; rowidx++)
    {
        for (int colidx = 0; colidx < M-8; colidx++)
        {

        }
    }

}