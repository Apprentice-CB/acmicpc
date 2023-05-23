#include <stdio.h>

int main(void)
{
    char st;
    scanf("%c", &st);
    if (st == 'n' || st == 'N')
    {
        printf("Naver D2");
    }
    else
    {
        printf("Naver Whale");
    }
}