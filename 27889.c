#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[5];
    scanf("%s", s);
    if (!strcmp(s, "NLCS"))
    {
        printf("North London collegiate School");
    }
    else if (!strcmp(s, "BHA"))
    {
        printf("Branksome Hall Asia");
    }
    else if (!strcmp(s, "KIS"))
    {
        printf("Korea International School");
    }
    else if (!strcmp(s, "SJA"))
    {
        printf("St.Johnsbury Academy");
    }
    else
    {
        
    }
    return 0;
}