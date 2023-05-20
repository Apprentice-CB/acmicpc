#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int cur = 0;
    int score = 0;
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &cur);
        if (cur == 0)
        {
            score = 0 ;
        }
        else
        {
            score++;
            total = total + score;
        }
    }
    printf("%d", total);
}