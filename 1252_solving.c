#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int main(void)
{
    char a[80];
    char b[80];

    scanf("%s %s", a, b);
    int long_length = max(strlen(a), strlen(b));
    int short_length = min(strlen(a), strlen(b));
    for (int i = short_length-1; i >= 0; i--)
    {
        if(a[i] == '1' && b[i] == '1')
        {

        }
        else if(a[i] == '1' && b[i] == '1')
        {

        }
        else if(a[i] == '1' && b[i] == '1')
        {

        }
        else if(a[i] == '1' && b[i] == '1')
        {
            
        }
    }
}