#include <stdio.h>

int main(void)
{
    char in[51];
    int N = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf(" %[^\n]", in);
        printf("%d. %s\n", i, in);
    }
}