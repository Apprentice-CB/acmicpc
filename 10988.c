#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char str[100];
    scanf("%s", str);
    int length = strlen(str);
    for (int idx = 0; idx < length / 2; idx++)
    {
        if (str[idx] != str[length-1-idx])
        {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}