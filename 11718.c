#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char str;
    
    while(scanf("%c", &str) != -1)
    {    
        printf("%c", str);
    }
}