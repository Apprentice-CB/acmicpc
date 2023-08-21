#include <stdio.h>
#include <string.h>

int main(void)
{
    char in[51];
    scanf("%s", in);
    int len = strlen(in);
    int h = 10;
    for (int i = 1; i < len; i++)
    {
        if (in[i] == '(')
        {
            if (in[i-1] == '(')
            {
                h += 5;
            }
            else
            {
                h += 10;
            }
        }
        else
        {
            if (in[i-1] == '(')
            {
                h += 10;
            }
            else
            {
                h += 5;
            }
        }
    }
    printf("%d\n", h);
}