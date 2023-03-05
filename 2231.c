#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int N = 0;
    int sum = 0;
    int temp;
    int done;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        temp = i;
        sum = temp;
        while (temp >= 10)
        {
            sum = sum + (temp % 10);
            temp = temp / 10;
        }
        sum = sum + temp;
        if (sum == N)
        {
            done = i;
            printf("%d\n", done);
            return 0;
        }
    }
    printf("0");
}