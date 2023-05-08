#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int r = 1000 - N;

    int cnt = 0;

    cnt += r / 500;
    r = r % 500;

    cnt += r / 100;
    r = r % 100;

    cnt += r / 50;
    r = r % 50;

    cnt += r / 10;
    r = r % 10;
    
    cnt += r / 5;
    r = r % 5;

    cnt += r;
    printf("%d", cnt);
}