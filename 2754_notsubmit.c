#include <stdio.h>

int main(void)
{
    char s[2];
    scanf("%s", s);
    if (!strcmp(s, "A+"))
    {
        printf("4.3");
    }
    else if (!strcmp(s, "A0"))
    {
        printf("4.0");
    }
    else if (!strcmp(s, "A-"))
    {
        printf("3.7");
    }
    else if (!strcmp(s, "B+"))
    {
        printf("3.3");
    }
    else if (!strcmp(s, "B0"))
    {
        printf("3.0");
    }
    else if (!strcmp(s, "B-"))
    {
        printf("2.7");
    }
    else if (!strcmp(s, "C+"))
    {
        printf("2.3");
    }
    else if (!strcmp(s, "C0"))
    {
        printf("2.0");
    }
    else if (!strcmp(s, "C-"))
    {
        printf("1.7");
    }
    else if (!strcmp(s, "D+"))
    {
        printf("1.3");
    }
    else if (!strcmp(s, "D0"))
    {
        printf("1.0");
    }
    else if (!strcmp(s, "D-"))
    {
        printf("0.7");
    }
    else
    {
        printf("0.0");
    }
}