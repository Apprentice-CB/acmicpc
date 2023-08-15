#include <stdio.h>
#include <string.h>

int main(void)
{
    int N = 0;
    int M = 0;
    scanf("%d %d", &N, &M);
    char l[12];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", l);
        for (int j = strlen(l)-1; j >= 0; j--)
        {
            printf("%c", l[j]);
        }
        printf("\n");
    }
}