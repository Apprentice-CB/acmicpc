#include <stdio.h>

int pas[31][31];
int n, k;

int main(void)
{
    scanf("%d %d", &n, &k);
    pas[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        pas[i][1] = 1;
        pas[i][i] = 1;
    }
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j <= i-1; j++)
        {
            pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
        }
    }
    
    printf("%d\n", pas[n][k]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", pas[i][j]);
        } printf("\n");
    }

}