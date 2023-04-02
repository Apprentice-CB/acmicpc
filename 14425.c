#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char set[10000][500];
char input[500];
int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%s", set[i]);
    }
    
    int cnt = 0;

    for (int i = 0; i < M; i++)
    {
        scanf("%s", input);
        for (int j = 0; j < N; j++)
        {
            if (!strcmp(input, set[j]))
            {
                cnt++;
                break;
            }    
        }
    }
    printf("%d", cnt);
}