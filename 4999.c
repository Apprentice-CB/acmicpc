#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[1001];
    char b[1001];
    scanf("%s", a);
    scanf("%s", b);
    if (strlen(a) > strlen(b))
    {
        printf("go");
    }
    else
    {
        printf("no");
    }
    return 0;
}