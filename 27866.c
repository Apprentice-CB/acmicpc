#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[1000];
    scanf("%s", str);
    int i = 0;
    scanf("%d", &i);
    printf("%c", str[i-1]);
}