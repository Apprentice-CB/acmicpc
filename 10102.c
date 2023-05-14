#include <stdio.h>
#include <string.h>

int main(void)
{
    int A = 0;
    int B = 0;
    int V = 0;
    scanf("%d", &V);
    char r[15];
    scanf("%s", r);
    for (int i = 0; i < strlen(r); i++)
    {
        if (r[i] == 'A')
        {
            A++;
        }
        else if (r[i] == 'B')
        {
            B++;
        }
    }
    if (A > B)
    {
        printf("A");
    }
    else if (A < B)
    {
        printf("B");
    }
    else
    {
        printf("Tie");
    }
}