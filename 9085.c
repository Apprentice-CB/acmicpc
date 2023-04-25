#include <stdio.h>

int main(void)
{
    int T = 0;
    int N = 0;
    int input = 0;
    int sum = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        sum = 0;
        for (int j = 0; j < N; j++)
        {
            scanf(" %d", &input);
            sum += input;
        }
        printf("%d\n", sum);
    }
}