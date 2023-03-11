#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int T = 0;
    scanf("%d", &T);
    char str[1000];
    for (int i = 0; i < T; i++)
    {
        scanf("%s", str);
        printf("%c%c\n", str[0], str[strlen(str)-1]);
    } 
    return 0;
}