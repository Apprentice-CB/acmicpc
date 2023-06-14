#include <stdio.h>
#include <string.h>

int main(void)
{
    char c[10];
    char black[] = "black";
    char brown[] = "brown";
    char red[] = "red";
    char orange[] = "orange";
    char yellow[] = "yellow";
    char green[] = "green";
    char blue[] = "blue";
    char violet[] = "violet";
    char grey[] = "grey";
    char white[] = "white";
    long long r = 0;
    scanf("%s", c);
    if (!strcmp(c, black))
    {
        r += 0;
    }
    else if (!strcmp(c, brown))
    {
        r += 1;
    }
    else if (!strcmp(c, red))
    {
        r += 2;
    }
    else if (!strcmp(c, orange))
    {
        r += 3;
    }
    else if (!strcmp(c, yellow))
    {
        r += 4;
    }
    else if (!strcmp(c, green))
    {
        r += 5;
    }
    else if (!strcmp(c, blue))
    {
        r += 6;
    }
    else if (!strcmp(c, violet))
    {
        r += 7;
    }
    else if (!strcmp(c, grey))
    {
        r += 8;
    }
    else if (!strcmp(c, white))
    {
        r += 9;
    }

    scanf("%s", c);
    if (!strcmp(c, black))
    {
        r = r*10+0;
    }
    else if (!strcmp(c, brown))
    {
        r = r*10+1;
    }
    else if (!strcmp(c, red))
    {
        r = r*10+2;
    }
    else if (!strcmp(c, orange))
    {
        r = r*10+3;
    }
    else if (!strcmp(c, yellow))
    {
        r = r*10+4;
    }
    else if (!strcmp(c, green))
    {
        r = r*10+5;
    }
    else if (!strcmp(c, blue))
    {
        r = r*10+6;
    }
    else if (!strcmp(c, violet))
    {
        r = r*10+7;
    }
    else if (!strcmp(c, grey))
    {
        r = r*10+8;
    }
    else if (!strcmp(c, white))
    {
        r = r*10+9;
    }    
    scanf("%s", c);
    if (!strcmp(c, black))
    {
        r = r*1;
    }
    else if (!strcmp(c, brown))
    {
        r = r*10;
    }
    else if (!strcmp(c, red))
    {
        r = r*100;
    }
    else if (!strcmp(c, orange))
    {
        r = r*1000;
    }
    else if (!strcmp(c, yellow))
    {
        r = r*10000;
    }
    else if (!strcmp(c, green))
    {
        r = r*100000;
    }
    else if (!strcmp(c, blue))
    {
        r = r*1000000;
    }
    else if (!strcmp(c, violet))
    {
        r = r*10000000;
    }
    else if (!strcmp(c, grey))
    {
        r = r*100000000;
    }
    else if (!strcmp(c, white))
    {
        r = r*1000000000;
    } 
    printf("%lld", r);
}