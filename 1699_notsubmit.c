#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int temp = 0;
    int cnt = 0;
    while (N != 0)
    {
        if (temp*temp > N)
        {
            cnt++;
            temp--;
            N -= temp*temp;
            temp = 0;
        }
        temp++;
    }
    printf("%d", cnt);
}